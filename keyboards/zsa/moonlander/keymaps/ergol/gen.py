from collections import defaultdict
from dataclasses import dataclass
from enum import Enum


class Mode(Enum):
    Base = 0
    DK = 1
    Sym = 2


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
    if is_unicode(kc) and is_unicode(skc):
        return ShiftMode.UnicodeMap
    return ShiftMode.CustomKey


@dataclass
class CustomKeyCode:
    m: Mode
    n: str
    kc: str | int
    skc: str | int | None

    @property
    def name(self):
        return f"{self.m.name}_{self.n}"


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
        if not skc:
            skc = kc

        return kc, skc

    def is_basic(self, m: Mode):
        kc, _ = self.get_kc(m)
        return isinstance(kc, str)


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
        "EKC_DK": Key(base="DK", shifted="KC_EXLM", dk_base="KC_TRNS", dk_shifted=0x00A1, sym_base="KC_QUOT", sym_shifted=0x0301),
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
        "EKC_DK": Key(base="DK", shifted="KC_EXLM", dk_base="KC_TRNS", dk_shifted=0x00A1, sym_base="FR_QUOT", sym_shifted=0x0301),
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
        {custom_keycodes}
    }};

    {unicode_map}

    {overrides}


    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{
        {layouts}
    }};

    """

    def __init__(self, host, layout):
        self.host = host
        self.layout = layout
        self.keys = ergol_keys[self.host]
        self.unicode_to_idx: dict[int, str] = {}
        self.unicode_map: str | None = None
        self.custom_keys: dict[Mode, dict[str, CustomKeyCode]] = defaultdict(dict)
        self.override: dict[Mode, dict[str, Override]] = defaultdict(dict)

        self._check()

    def _check(self):
        for _, k in self.keys.items():
            if not k.is_basic(Mode.Base):
                raise Exception("At the moment base layout need to be basic")

    def _gen_unicode_map(self):
        indices_line = "{idx}"
        unicode_map_line = "[{idx}]  = {cp} /* {dsp} */"
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
        for ekc, key in self.keys.items():
            for m in Mode:
                kc, skc = key.get_kc(m)
                for k, n in ((kc, "base"), (skc, "shifted")):
                    if is_unicode(k):
                        if k in already_gen:
                            continue
                        already_gen.add(k)
                        idx = indices_line.format(idx=f"{ekc}_{m.name}_{n}")
                        self.unicode_to_idx[k] = idx
                        ln = unicode_map_line.format(idx=idx, cp=k, dsp=chr(k))
                        indices.append(idx)
                        unicode_map_lines.append(ln)
        self.unicode_map = tpl.format(
            indices=",\n".join(indices),
            unicode_map_lines=",\n".join(unicode_map_lines),
        )

    def _create_custom_keys(self, m: Mode, name, kc, skc):
        ckc = CustomKeyCode(m=m, n=name, kc=kc, skc=skc)
        self.custom_keys[m][name] = ckc
        return ckc

    def _create_override(self, m: Mode, name, kc, skc):
        if is_unicode(skc):
            skc = f"UM({self.unicode_to_idx[skc]})"
        ovr = Override(m=m, n=name, kc=kc, skc=skc)
        self.override[m][name] = ovr
        return ovr

    def _gen_override(self):
        override_line = "const key_override_t {name} = ko_make_basic(MOD_MASK_SHIFT, {key}, {skey});"
        tpl = """
        {overrides}

        const key_override_t **key_overrides = (const key_override_t *[]){{
            {override_names},
            NULL
        }};
        """
        overrides = []
        override_names = []
        for _, override_per_kc in self.override.items():
            for _, override in override_per_kc.items():
                overrides.append(
                    override_line.format(
                        name=override.name, key=override.kc, skey=override.skc
                    )
                )
                override_names.append(f"&{override.name}")
        self.override_code = tpl.format(
            overrides="\n".join(overrides),
            override_names=",\n".join(override_names),
        )

    def _gen_kc(self, m: Mode, name, kc, skc):
        match get_shift_mod(kc, skc):
            case ShiftMode.Default:
                return kc
            case ShiftMode.Override:
                self._create_override(m, name, kc, skc)
                return kc
            case ShiftMode.CustomKey:
                ckc = self._create_custom_keys(m, name, kc, skc)
                return ckc.name
            case ShiftMode.UnicodeMap:
                return "UP({}, {})".format(
                    self.unicode_to_idx[kc],
                    self.unicode_to_idx[skc],
                )

    def _gen(self, m: Mode):
        l = self.layout[:]
        for n, key in self.keys.items():
            kc, skc = key.get_kc(m)
            final_kc = self._gen_kc(m, n, kc, skc)
            l = l.replace(n, final_kc)
        return l

    def gen(self):
        self._gen_unicode_map()
        self.layers = []
        for m in Mode:
            self.layers.append(self._gen(m))
        self._gen_override()

        return self.file_tpl.format(
            layers=",\n".join(m.name for m in Mode),
            custom_keycodes="",
            unicode_map=self.unicode_map,
            overrides=self.override_code,
            layouts=",\n".join(
                f"[{m.name}] = {layout}" for m, layout in zip(Mode, self.layers)
            ),
        )


host = "us"


LAYOUT = """
 LAYOUT(
        KC_ESC ,  EKC_1 ,  EKC_2 ,  EKC_3 ,  EKC_4 ,  EKC_5 , _______,           _______,  EKC_6 ,  EKC_7,   EKC_8 ,  EKC_9 ,  EKC_0 , QK_BOOT,
        KC_TAB ,  EKC_Q ,  EKC_C ,  EKC_O ,  EKC_P ,  EKC_W , KC_DEL ,           KC_BSPC,  EKC_J ,  EKC_M ,  EKC_D , EKC_DK ,  EKC_Y , _______,
        KC_GRV ,  EKC_A ,  EKC_S ,  EKC_E ,  EKC_N ,  EKC_F , _______,           _______,  EKC_L ,  EKC_R ,  EKC_T ,  EKC_I ,  EKC_U , _______,
        KC_LSFT,  EKC_Z ,  EKC_X , EKC_MNS,  EKC_V ,  EKC_B ,                             EKC_DOT,  EKC_H ,  EKC_G ,EKC_COMM,  EKC_K , KC_RSFT,
        KC_LCTL, _______, KC_LEFT,KC_RIGHT, KC_LGUI,         _______,            _______,           KC_UP , KC_DOWN, _______, _______, _______,
                                           _______, _______, _______,     _______, KC_ENTER, EKC_SPC
 )
"""


g = Gen(host, LAYOUT)
print(g.gen())

# print(g.override_code)
# for l in g.layers:
#     print(l)
# print(g.unicode_map)
