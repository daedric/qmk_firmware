from collections import defaultdict
import itertools
from dataclasses import dataclass
import copy
from enum import Enum
from typing import Generator
from unicodedata import name as unicode_name
import re


class Mode(Enum):
    Base = 0
    DK = 1
    Sym = 2
    # perso
    Media = 3


class ShiftMode(Enum):
    Default = 0
    Override = 1
    CustomKey = 2
    UnicodeMap = 3


def is_basic(kc) -> bool:
    return isinstance(kc, str)


def is_unicode(kc) -> bool:
    return isinstance(kc, int)


def get_shift_mod(kc, skc) -> ShiftMode:
    if is_basic(kc):
        if skc is None or kc == skc:
            return ShiftMode.Default
        return ShiftMode.Override
    if is_unicode(kc):
        if is_unicode(skc):
            return ShiftMode.UnicodeMap
        if skc == "KC_TRNS":
            return ShiftMode.Default
    return ShiftMode.CustomKey


def parse_lt(kc):
    pattern = re.compile(r"^LT\((?P<layer>\w+)\|\s*(?P<keycode>\w+)\)$")
    if match := pattern.match(kc):
        return match.group("layer"), match.group("keycode")
    raise ValueError("kc does not match the expected format LT(layer|keycode)")


TRNS = "_______"


def is_transparent(kc):
    return kc == "KC_TRNS" or kc == TRNS


@dataclass
class Override:
    m: Mode
    n: str
    kc: str | int
    skc: str | int

    @property
    def name(self):
        return f"{self.m.name}_{self.n}"


@dataclass
class Key:
    base: str
    shifted: str | int | None

    dk_base: str | int
    dk_shifted: str | int

    sym_base: str | int
    sym_shifted: str | int

    def get_kc(self, m: Mode):
        kc = None
        skc = None
        match m:
            case Mode.Base:
                kc, skc = self.base, self.shifted
            case Mode.DK:
                kc, skc = self.dk_base, self.dk_shifted
            case Mode.Sym:
                kc, skc = self.sym_base, self.sym_shifted
            case _:
                kc, skc = TRNS, TRNS
        if not skc:
            skc = kc

        return kc, skc

    def is_basic(self, m: Mode):
        kc, _ = self.get_kc(m)
        return isinstance(kc, str)


@dataclass
class Coord:
    row: int
    col: int


class Layer:
    def __init__(self, layout: "Keymaps", rows: list[list[str]]):
        self.layout: "Keymaps" = layout
        self.rows = rows
        self.max_length = 0
        for cols in rows:
            for c in cols:
                self.max_length = max(self.max_length, len(c))

    def set_key(self, coord: Coord, key: str):
        if is_transparent(key):
            return

        prev = self.rows[coord.row][coord.col]
        if not is_transparent(prev) and key != prev:
            raise Exception(f"Key at {coord} is not transparent: {prev}")
        self.rows[coord.row][coord.col] = key
        self.max_length = max(self.max_length, len(key))

    def format(self, FMT: str | None):
        if not FMT:
            return ",\n".join(", ".join(cols) for cols in self.rows)

        fmt = "{{:^{}}}".format(self.max_length)
        kcs = [fmt.format(kc) for kc in itertools.chain(*self.rows)]
        return f"\n// clang-format off\n{FMT.format(*kcs)}\n// clang-format on\n"


class Keymaps:
    TRNS = "_______"

    def __init__(self, fmt_layer: str, nb_keys):
        self.fmt_layer = fmt_layer

        self.final_layers: dict[Mode, Layer] = {}
        self.transparent_layer = self._parse(fmt_layer.format(*([self.TRNS] * nb_keys)))

    @classmethod
    def _parse(cls, layout):
        lines: str = layout.split("\n")
        base_layer = []
        for line in lines:
            line = line.lstrip()
            if line.startswith("//"):
                continue
            keys = list(filter(None, [kc.strip() for kc in line.split(",")]))
            if keys:
                base_layer.append(keys)
        return base_layer

    def add_layer(self, m: Mode, preset: None | str = None) -> Layer:
        if l := self.final_layers.get(m):
            if preset != None:
                raise Exception(f"there is already a layer for mode: {m}")
            return l
        if preset is None:
            l = Layer(self, copy.deepcopy(self.transparent_layer))
        else:
            l = Layer(self, self._parse(preset))
        self.final_layers[m] = l
        return l

    def set_base(self, layer):
        self.base_layer = self._parse(layer)

    def base_keys(self) -> Generator[tuple[str, Coord], None, None]:
        for row, cols in enumerate(self.base_layer):
            for col, name in enumerate(cols):
                yield (name, Coord(row=row, col=col))

    def format(self, m: Mode) -> str:
        return self.final_layers[m].format(self.fmt_layer)


ergol_keys = {
    "us": {
        # fmt: off
        "EKC_Q": Key(base="KC_Q", shifted=None, dk_base=0x00E2, dk_shifted=0x00C2, sym_base="KC_CIRC", sym_shifted=0x0302),
        "EKC_C": Key(base="KC_C", shifted=None, dk_base=0x00E7, dk_shifted=0x00C7, sym_base="KC_LABK", sym_shifted=0x2264),
        "EKC_O": Key(base="KC_O", shifted=None, dk_base=0x0153, dk_shifted=0x0152, sym_base="KC_RABK", sym_shifted=0x2265),
        "EKC_P": Key(base="KC_P", shifted=None, dk_base=0x00F4, dk_shifted=0x00D4, sym_base="KC_DLR", sym_shifted="KC_TRNS"),
        "EKC_W": Key(base="KC_W", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="KC_PERC", sym_shifted=0x2030),

        "EKC_J": Key(base="KC_J", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="KC_AT", sym_shifted=0x030A),
        "EKC_M": Key(base="KC_M", shifted=None, dk_base=0x00B5, dk_shifted="KC_TRNS", sym_base="KC_AMPR", sym_shifted="KC_TRNS"),
        "EKC_D": Key(base="KC_D", shifted=None, dk_base="KC_UNDS", dk_shifted="KC_TRNS", sym_base="KC_ASTR", sym_shifted=0x00D7),
        "EKC_DK": Key(base="OSL(DK)", shifted="KC_EXLM", dk_base=0x0308, dk_shifted=0x00A1, sym_base="KC_QUOT", sym_shifted=0x0301),
        "EKC_Y": Key(base="KC_Y", shifted=None, dk_base=0x00FB, dk_shifted=0x00DB, sym_base="KC_GRV", sym_shifted=0x0300),

        "EKC_A": Key(base="KC_A", shifted=None, dk_base=0x00E0, dk_shifted=0x00C0, sym_base="KC_LCBR", sym_shifted=0x030C),
        "EKC_S": Key(base="KC_S", shifted=None, dk_base=0x00E9, dk_shifted=0x00C9, sym_base="KC_LPRN", sym_shifted="KC_TRNS"),
        "EKC_E": Key(base="KC_E", shifted=None, dk_base=0x00E8, dk_shifted=0x00C8, sym_base="KC_RPRN", sym_shifted="KC_TRNS"),
        "EKC_N": Key(base="KC_N", shifted=None, dk_base=0x00EA, dk_shifted=0x00CA, sym_base="KC_RCBR", sym_shifted=0x0307),
        "EKC_F": Key(base="KC_F", shifted=None, dk_base=0x00F1, dk_shifted=0x00D1, sym_base="KC_EQL", sym_shifted=0x2260),

        "EKC_L": Key(base="KC_L", shifted=None, dk_base="KC_LPRN", dk_shifted="KC_TRNS", sym_base="KC_BSLS", sym_shifted=0x0338),
        "EKC_R": Key(base="KC_R", shifted=None, dk_base="KC_RPRN", dk_shifted="KC_TRNS", sym_base="KC_PLUS", sym_shifted=0x2A72),
        "EKC_T": Key(base="KC_T", shifted=None, dk_base=0x00EE, dk_shifted=0x00CE, sym_base="KC_MINS", sym_shifted=0x0304),
        "EKC_I": Key(base="KC_I", shifted=None, dk_base=0x00EF, dk_shifted=0x00CF, sym_base="KC_SLSH", sym_shifted=0x00F7),
        "EKC_U": Key(base="KC_U", shifted=None, dk_base=0x00F9, dk_shifted=0x00D9, sym_base="KC_DQUO", sym_shifted=0x030B),

        "EKC_Z": Key(base="KC_Z", shifted=None, dk_base=0x00E6, dk_shifted=0x00C6, sym_base="KC_TILD", sym_shifted=0x0303),
        "EKC_X": Key(base="KC_X", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="KC_LBRC", sym_shifted=0x0326),
        "EKC_MNS": Key(base="KC_MINS", shifted="KC_QUES", dk_base=0x2011, dk_shifted=0x00BF, sym_base="KC_RBRC", sym_shifted=0x0328),
        "EKC_V": Key(base="KC_V", shifted=None, dk_base=0x2013, dk_shifted="KC_TRNS", sym_base="KC_UNDS", sym_shifted=0x2013),
        "EKC_B": Key(base="KC_B", shifted=None, dk_base=0x2014, dk_shifted="KC_TRNS", sym_base="KC_HASH", sym_shifted="KC_TRNS"),

        "EKC_DOT": Key(base="KC_DOT", shifted="KC_COLN", dk_base=0x2026, dk_shifted="KC_TRNS", sym_base="KC_PIPE", sym_shifted=0x00A6),
        "EKC_H": Key(base="KC_H", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="KC_EXLM", sym_shifted=0x00AC),
        "EKC_G": Key(base="KC_G", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="KC_SCLN", sym_shifted=0x0312),
        "EKC_COMM": Key(base="KC_COMM", shifted="KC_SCLN", dk_base=0x00B7, dk_shifted=0x2022, sym_base="KC_COLN", sym_shifted="KC_TRNS"),
        "EKC_K": Key(base="KC_K", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="KC_QUES", sym_shifted=0x0306),

        "EKC_1": Key(base="KC_1", shifted=0x20AC, dk_base=0x201E, dk_shifted=0x201A, sym_base=0x2081, sym_shifted=0x00B9),
        "EKC_2": Key(base="KC_2", shifted=0x00AB, dk_base=0x201C, dk_shifted=0x2018, sym_base=0x2082, sym_shifted=0x00B2),
        "EKC_3": Key(base="KC_3", shifted=0x00BB, dk_base=0x201F, dk_shifted=0x2019, sym_base=0x2083, sym_shifted=0x00B3),
        "EKC_4": Key(base="KC_4", shifted="KC_DLR", dk_base=0x00A2, dk_shifted="KC_TRNS", sym_base=0x2084, sym_shifted=0x2074),
        "EKC_5": Key(base="KC_5", shifted="KC_PERC", dk_base=0x2030, dk_shifted="KC_TRNS", sym_base=0x2085, sym_shifted=0x2075),
        "EKC_6": Key(base="KC_6", shifted="KC_CIRC", dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base=0x2086, sym_shifted=0x2076),

        "EKC_7": Key(base="KC_7", shifted="KC_AMPR", dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base=0x2087, sym_shifted=0x2077),
        "EKC_8": Key(base="KC_8", shifted="KC_ASTR", dk_base=0x00A7, dk_shifted="KC_TRNS", sym_base=0x2088, sym_shifted=0x2078),
        "EKC_9": Key(base="KC_9", shifted="KC_HASH", dk_base=0x00B6, dk_shifted="KC_TRNS", sym_base=0x2089, sym_shifted=0x2079),
        "EKC_0": Key(base="KC_0", shifted="KC_AT", dk_base=0x00B0, dk_shifted="KC_TRNS", sym_base=0x2080, sym_shifted=0x2070),

        "EKC_SPC": Key(base="KC_SPC", shifted=0x202F, dk_base=0x2019, dk_shifted="KC_TRNS", sym_base="KC_SPC", sym_shifted="KC_TRNS"),
        # fmt: on
    },
    "fr": {
        # fmt: off
        "EKC_Q": Key(base="FR_Q", shifted=None, dk_base=0x00E2, dk_shifted=0x00C2, sym_base=0x005E, sym_shifted=0x0302),
        "EKC_C": Key(base="FR_C", shifted=None, dk_base="FR_CCED", dk_shifted=0x00C7, sym_base="FR_LABK", sym_shifted=0x2264),
        "EKC_O": Key(base="FR_O", shifted=None, dk_base=0x0153, dk_shifted=0x0152, sym_base="FR_RABK", sym_shifted=0x2265),
        "EKC_P": Key(base="FR_P", shifted=None, dk_base=0x00F4, dk_shifted=0x00D4, sym_base="FR_DLR", sym_shifted="KC_TRNS"),
        "EKC_W": Key(base="FR_W", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="FR_PERC", sym_shifted=0x2030),

        "EKC_J": Key(base="FR_J", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="FR_AT", sym_shifted=0x030A),
        "EKC_M": Key(base="FR_M", shifted=None, dk_base=0x00B5, dk_shifted="KC_TRNS", sym_base="FR_AMPR", sym_shifted="KC_TRNS"),
        "EKC_D": Key(base="FR_D", shifted=None, dk_base="FR_UNDS", dk_shifted="KC_TRNS", sym_base="FR_ASTR", sym_shifted=0x00D7),
        "EKC_DK": Key(base="OSL(DK)", shifted="KC_EXLM", dk_base=0x0308, dk_shifted=0x00A1, sym_base="FR_QUOT", sym_shifted=0x0301),
        "EKC_Y": Key(base="FR_Y", shifted=None, dk_base=0x00FB, dk_shifted=0x00DB, sym_base="FR_GRV", sym_shifted=0x0300),

        "EKC_A": Key(base="FR_A", shifted=None, dk_base="FR_AGRV", dk_shifted=0x00C0, sym_base="FR_LCBR", sym_shifted=0x0306),
        "EKC_S": Key(base="FR_S", shifted=None, dk_base="FR_EACU", dk_shifted=0x00C9, sym_base="FR_LPRN", sym_shifted="KC_TRNS"),
        "EKC_E": Key(base="FR_E", shifted=None, dk_base="FR_EGRV", dk_shifted=0x00C8, sym_base="FR_RPRN", sym_shifted="KC_TRNS"),
        "EKC_N": Key(base="FR_N", shifted=None, dk_base=0x00EA, dk_shifted=0x00CA, sym_base="FR_RCBR", sym_shifted=0x0307),
        "EKC_F": Key(base="FR_F", shifted=None, dk_base=0x00F1, dk_shifted=0x00D1, sym_base="FR_EQL", sym_shifted=0x2260),

        "EKC_L": Key(base="FR_L", shifted=None, dk_base="FR_LPRN", dk_shifted="KC_TRNS", sym_base="FR_BSLS", sym_shifted=0x0338),
        "EKC_R": Key(base="FR_R", shifted=None, dk_base="FR_RPRN", dk_shifted="KC_TRNS", sym_base="FR_PLUS", sym_shifted=0x2A72),
        "EKC_T": Key(base="FR_T", shifted=None, dk_base=0x00EE, dk_shifted=0x00CE, sym_base="FR_MINS", sym_shifted=0x0304),
        "EKC_I": Key(base="FR_I", shifted=None, dk_base=0x00EF, dk_shifted=0x00CF, sym_base="FR_SLSH", sym_shifted=0x00F7),
        "EKC_U": Key(base="FR_U", shifted=None, dk_base=0x00F9, dk_shifted=0x00D9, sym_base="FR_DQUO", sym_shifted=0x030B),

        "EKC_Z": Key(base="FR_Z", shifted=None, dk_base=0x00E6, dk_shifted=0x00C6, sym_base="FR_TILD", sym_shifted=0x0303),
        "EKC_X": Key(base="FR_X", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="FR_LBRC", sym_shifted=0x0326),
        "EKC_MNS": Key(base="FR_MINS", shifted="FR_QUES", dk_base=0x2011, dk_shifted=0x00BF, sym_base="FR_RBRC", sym_shifted=0x0328),
        "EKC_V": Key(base="FR_V", shifted=None, dk_base=0x2013, dk_shifted="KC_TRNS", sym_base="FR_UNDS", sym_shifted=0x2013),
        "EKC_B": Key(base="FR_B", shifted=None, dk_base=0x2014, dk_shifted="KC_TRNS", sym_base="FR_HASH", sym_shifted="KC_TRNS"),

        "EKC_DOT": Key(base="FR_DOT", shifted="FR_COLN", dk_base=0x2026, dk_shifted="KC_TRNS", sym_base="FR_PIPE", sym_shifted=0x00A6),
        "EKC_H": Key(base="FR_H", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="FR_EXLM", sym_shifted=0x00AC),
        "EKC_G": Key(base="FR_G", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="FR_SCLN", sym_shifted=0x0312),
        "EKC_COMM": Key(base="FR_COMM", shifted="FR_SCLN", dk_base=0x00B7, dk_shifted=0x2022, sym_base="FR_COLN", sym_shifted="KC_TRNS"),
        "EKC_K": Key(base="FR_K", shifted=None, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base="FR_QUES", sym_shifted=0x0306),

        "EKC_1": Key(base="FR_1", shifted=0x20AC, dk_base=0x201E, dk_shifted=0x201A, sym_base=0x2081, sym_shifted=0x00B9),
        "EKC_2": Key(base="FR_2", shifted=0x00AB, dk_base=0x201C, dk_shifted=0x2018, sym_base=0x2082, sym_shifted=0x00B2),
        "EKC_3": Key(base="FR_3", shifted=0x00BB, dk_base=0x201F, dk_shifted=0x2019, sym_base=0x2083, sym_shifted=0x00B3),
        "EKC_4": Key(base="FR_4", shifted="FR_DLR", dk_base=0x00A2, dk_shifted="KC_TRNS", sym_base=0x2084, sym_shifted=0x2074),
        "EKC_5": Key(base="FR_5", shifted="FR_PERC", dk_base=0x2030, dk_shifted="KC_TRNS", sym_base=0x2085, sym_shifted=0x2075),
        "EKC_6": Key(base="FR_6", shifted=0x005E, dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base=0x2086, sym_shifted=0x2076),

        "EKC_7": Key(base="FR_7", shifted="FR_AMPR", dk_base="KC_TRNS", dk_shifted="KC_TRNS", sym_base=0x2087, sym_shifted=0x2077),
        "EKC_8": Key(base="FR_8", shifted="FR_ASTR", dk_base="FR_SECT", dk_shifted="KC_TRNS", sym_base=0x2088, sym_shifted=0x2078),
        "EKC_9": Key(base="FR_9", shifted="FR_HASH", dk_base=0x00B6, dk_shifted="KC_TRNS", sym_base=0x2089, sym_shifted=0x2079),
        "EKC_0": Key(base="FR_0", shifted="FR_AT", dk_base="FR_DEG", dk_shifted="KC_TRNS", sym_base=0x2080, sym_shifted=0x2070),

        "EKC_SPC": Key(base="KC_SPC", shifted=0x202F, dk_base=0x2019, dk_shifted="KC_TRNS", sym_base="KC_SPC", sym_shifted="KC_TRNS"),
        # fmt: on
    },
}


class Gen:
    file_tpl = """
        #include QMK_KEYBOARD_H

        #include <stdint.h>

        #include "keycodes.h"
        #include "version.h"

    enum layers {{
        {layers}
    }};

    enum custom_keycodes {{
        _FIRST = SAFE_RANGE
    }};

    {aliases}

    {unicode_map}

    {overrides}


    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{
        {layouts},
    }};

    """

    def __init__(self, host, kms: "Keymaps"):
        self.host = host
        self.keymaps = kms
        self.keys = ergol_keys[self.host]
        self.unicode_to_idx: dict[int, str] = {}
        self.unicode_map: str | None = None
        self.override: dict[Mode, dict[str, Override]] = defaultdict(dict)
        self.aliases: dict[str, str] = {}

        self._check()

    def _check(self):
        for _, k in self.keys.items():
            if not k.is_basic(Mode.Base):
                raise Exception("At the moment base keymaps need to be basic")

    def _gen_unicode_map(self):
        indices_line = "{idx}"
        unicode_map_line = "[{idx}]  = {cp:#06x} /* {dsp} */"
        tpl = """
            enum unicode_names {{
                {indices}
            }};


            const uint32_t PROGMEM unicode_map[] = {{
                {unicode_map_lines}
            }};
        """
        indices = []
        unicode_map_lines = []
        already_gen = set()
        for _, key in self.keys.items():
            for m in Mode:
                kc, skc = key.get_kc(m)
                for k in (kc, skc):
                    if is_unicode(k):
                        if k in already_gen:
                            continue
                        already_gen.add(k)

                        ch = chr(k)
                        name = unicode_name(ch)
                        name = name.replace(" ", "_").replace("-", "_")

                        idx = indices_line.format(idx=name)
                        self.unicode_to_idx[k] = idx
                        ln = unicode_map_line.format(idx=idx, cp=k, dsp=ch)
                        indices.append(idx)
                        unicode_map_lines.append(ln)
        self.unicode_map = tpl.format(
            indices=",\n".join(indices),
            unicode_map_lines=",\n".join(unicode_map_lines),
        )

    def _create_override(self, m: Mode, name, kc, skc):
        if is_unicode(skc):
            skc = f"UM({self.unicode_to_idx[skc]})"
        if is_transparent(skc):
            skc = kc
        ovr = Override(m=m, n=name, kc=kc, skc=skc)
        self.override[m][name] = ovr
        return ovr

    def _gen_override(self):
        override_line = "const key_override_t {name} = ko_make_with_layers(MOD_MASK_SHIFT, {key}, {skey}, (1 << {mode}));"
        tpl = """
        {overrides}

        const key_override_t **key_overrides = (const key_override_t *[]){{
            {override_names},
            NULL,
        }};
        """
        overrides = []
        override_names = []
        for m, override_per_kc in self.override.items():
            for _, override in override_per_kc.items():
                overrides.append(
                    override_line.format(
                        name=override.name,
                        key=override.kc,
                        skey=override.skc,
                        mode=m.name,
                    )
                )
                override_names.append(f"&{override.name}")
        self.override_code = tpl.format(
            overrides="\n".join(overrides),
            override_names=",\n".join(override_names),
        )

    def _alias(self, name, value):
        if v := self.aliases.get(name):
            if v != value:
                raise Exception(f"conflict for {name}, we have {v} and {value}")
            return name
        self.aliases[name] = value
        return name

    def _gen_kc(self, m: Mode, name, kc, skc):
        alias_name = f"{m.name}_{name}"
        match get_shift_mod(kc, skc):
            case ShiftMode.Default:
                if is_unicode(kc):
                    return self._alias(alias_name, f"UM({self.unicode_to_idx[kc]})")
                return kc
            case ShiftMode.CustomKey:
                raise Exception("Custom key are not implemented")
            case ShiftMode.Override:
                self._create_override(m, name, kc, skc)
                return kc
            case ShiftMode.UnicodeMap:
                return self._alias(
                    alias_name,
                    "UP({}, {})".format(
                        self.unicode_to_idx[kc],
                        self.unicode_to_idx[skc],
                    ),
                )

    def _gen(self, m: Mode):
        l = self.keymaps.add_layer(m)
        for n, coord in self.keymaps.base_keys():
            is_lt = False
            layer = None
            if m == Mode.Base and n.startswith("LT"):
                is_lt = True
                layer, n = parse_lt(n)

            key = self.keys.get(n)
            if not key:
                if m == Mode.Base:
                    l.set_key(coord, n)
                continue

            kc, skc = key.get_kc(m)
            final_kc = self._gen_kc(m, n, kc, skc)
            if is_lt:
                final_kc = f"LT({layer}, {final_kc})"
            l.set_key(coord, final_kc)

    def gen(self):
        self._gen_unicode_map()
        for m in Mode:
            self._gen(m)
        self._gen_override()

        return self.file_tpl.format(
            layers=",\n".join(m.name for m in Mode),
            aliases="\n".join(
                f"#define {name} {value}" for name, value in self.aliases.items()
            ),
            unicode_map=self.unicode_map,
            overrides=self.override_code,
            layouts=",\n".join(
                f"[{m.name}] = LAYOUT({self.keymaps.format(m)})" for m in Mode
            ),
        )


host = "us"

fmt_layer = """
        {}, {}, {}, {}, {}, {}, {},           {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},           {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},           {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {},                   {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {},         {},     {},       {}, {}, {}, {}, {},
                            {}, {}, {},     {}, {}, {}
"""


base = """
        KC_ESC ,  EKC_1 ,  EKC_2 ,  EKC_3 ,  EKC_4 ,  EKC_5 , _______,           _______,  EKC_6 ,  EKC_7,   EKC_8 ,  EKC_9 ,  EKC_0 , QK_BOOT,
        KC_TAB ,  EKC_Q ,  EKC_C ,  EKC_O ,  EKC_P ,  EKC_W , KC_DEL ,           KC_BSPC,  EKC_J ,  EKC_M ,  EKC_D , EKC_DK ,  EKC_Y , _______,
        KC_GRV ,  EKC_A ,  EKC_S ,  EKC_E ,  EKC_N ,  EKC_F , _______,           _______,  EKC_L ,  EKC_R ,  EKC_T ,  EKC_I ,  LT(Media|EKC_U), _______,
        KC_LSFT,  EKC_Z ,  EKC_X , EKC_MNS,  EKC_V ,  EKC_B ,                             EKC_DOT,  EKC_H ,  EKC_G ,EKC_COMM,  EKC_K , KC_RSFT,
        KC_LCTL, _______, KC_LEFT,KC_RIGHT, KC_LGUI,         _______,            _______,           KC_UP , KC_DOWN, _______, _______, _______,
                                            MO(Sym), _______, _______,            _______, KC_ENTER, EKC_SPC
"""

media = """
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, KC_PWR, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, KC_MPRV, KC_MNXT, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,     _______,       UC_NEXT, UC_PREV, _______, _______, _______,
                                           _______, _______, _______,     _______, _______, _______
"""

km = Keymaps(fmt_layer=fmt_layer, nb_keys=72)
km.set_base(base)
km.add_layer(Mode.Media, media)

g = Gen(host, km)
r = g.gen()
print(r)
