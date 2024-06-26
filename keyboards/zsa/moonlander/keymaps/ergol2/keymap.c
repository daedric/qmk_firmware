
#include QMK_KEYBOARD_H

#include <stdint.h>

#include "keycodes.h"
#include "version.h"

enum layers {
    Base,
    DK,
    Sym,
    Media,
    Fn,
};

enum custom_keycodes {
    _FIRST = SAFE_RANGE,
    Base_EKC_1,
    Base_EKC_2,
    Base_EKC_3,
    Base_EKC_SPC,
    Sym_EKC_Q,
    Sym_EKC_C,
    Sym_EKC_O,
    Sym_EKC_W,
    Sym_EKC_J,
    Sym_EKC_D,
    Sym_EKC_DK,
    Sym_EKC_Y,
    Sym_EKC_A,
    Sym_EKC_N,
    Sym_EKC_F,
    Sym_EKC_L,
    Sym_EKC_R,
    Sym_EKC_T,
    Sym_EKC_I,
    Sym_EKC_U,
    Sym_EKC_Z,
    Sym_EKC_X,
    Sym_EKC_MNS,
    Sym_EKC_V,
    Sym_EKC_DOT,
    Sym_EKC_H,
    Sym_EKC_G,
    Sym_EKC_K,
};

#define DK_EKC_1 UP(DOUBLE_LOW_9_QUOTATION_MARK, SINGLE_LOW_9_QUOTATION_MARK)
#define DK_EKC_2 UP(LEFT_DOUBLE_QUOTATION_MARK, LEFT_SINGLE_QUOTATION_MARK)
#define DK_EKC_3 UP(DOUBLE_HIGH_REVERSED_9_QUOTATION_MARK, RIGHT_SINGLE_QUOTATION_MARK)
#define DK_EKC_4 UM(CENT_SIGN)
#define DK_EKC_5 UM(PER_MILLE_SIGN)
#define DK_EKC_8 UM(SECTION_SIGN)
#define DK_EKC_9 UM(PILCROW_SIGN)
#define DK_EKC_0 UM(DEGREE_SIGN)
#define DK_EKC_Q UP(LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX)
#define DK_EKC_C UP(LATIN_SMALL_LETTER_C_WITH_CEDILLA, LATIN_CAPITAL_LETTER_C_WITH_CEDILLA)
#define DK_EKC_O UP(LATIN_SMALL_LIGATURE_OE, LATIN_CAPITAL_LIGATURE_OE)
#define DK_EKC_P UP(LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX)
#define DK_EKC_M UM(MICRO_SIGN)
#define DK_EKC_DK UP(COMBINING_DIAERESIS, INVERTED_EXCLAMATION_MARK)
#define DK_EKC_Y UP(LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX)
#define DK_EKC_A UP(LATIN_SMALL_LETTER_A_WITH_GRAVE, LATIN_CAPITAL_LETTER_A_WITH_GRAVE)
#define DK_EKC_S UP(LATIN_SMALL_LETTER_E_WITH_ACUTE, LATIN_CAPITAL_LETTER_E_WITH_ACUTE)
#define DK_EKC_E UP(LATIN_SMALL_LETTER_E_WITH_GRAVE, LATIN_CAPITAL_LETTER_E_WITH_GRAVE)
#define DK_EKC_N UP(LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX)
#define DK_EKC_F UP(LATIN_SMALL_LETTER_N_WITH_TILDE, LATIN_CAPITAL_LETTER_N_WITH_TILDE)
#define DK_EKC_T UP(LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX)
#define DK_EKC_I UP(LATIN_SMALL_LETTER_I_WITH_DIAERESIS, LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS)
#define DK_EKC_U UP(LATIN_SMALL_LETTER_U_WITH_GRAVE, LATIN_CAPITAL_LETTER_U_WITH_GRAVE)
#define DK_EKC_Z UP(LATIN_SMALL_LETTER_AE, LATIN_CAPITAL_LETTER_AE)
#define DK_EKC_MNS UP(NON_BREAKING_HYPHEN, INVERTED_QUESTION_MARK)
#define DK_EKC_V UM(EN_DASH)
#define DK_EKC_B UM(EM_DASH)
#define DK_EKC_DOT UM(HORIZONTAL_ELLIPSIS)
#define DK_EKC_COMM UP(MIDDLE_DOT, BULLET)
#define DK_EKC_SPC UM(RIGHT_SINGLE_QUOTATION_MARK)
#define Sym_EKC_1 UP(SUBSCRIPT_ONE, SUPERSCRIPT_ONE)
#define Sym_EKC_2 UP(SUBSCRIPT_TWO, SUPERSCRIPT_TWO)
#define Sym_EKC_3 UP(SUBSCRIPT_THREE, SUPERSCRIPT_THREE)
#define Sym_EKC_4 UP(SUBSCRIPT_FOUR, SUPERSCRIPT_FOUR)
#define Sym_EKC_5 UP(SUBSCRIPT_FIVE, SUPERSCRIPT_FIVE)
#define Sym_EKC_6 UP(SUBSCRIPT_SIX, SUPERSCRIPT_SIX)
#define Sym_EKC_7 UP(SUBSCRIPT_SEVEN, SUPERSCRIPT_SEVEN)
#define Sym_EKC_8 UP(SUBSCRIPT_EIGHT, SUPERSCRIPT_EIGHT)
#define Sym_EKC_9 UP(SUBSCRIPT_NINE, SUPERSCRIPT_NINE)
#define Sym_EKC_0 UP(SUBSCRIPT_ZERO, SUPERSCRIPT_ZERO)

enum unicode_names {
    LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX,
    COMBINING_CIRCUMFLEX_ACCENT,
    LATIN_SMALL_LETTER_C_WITH_CEDILLA,
    LATIN_CAPITAL_LETTER_C_WITH_CEDILLA,
    LESS_THAN_OR_EQUAL_TO,
    LATIN_SMALL_LIGATURE_OE,
    LATIN_CAPITAL_LIGATURE_OE,
    GREATER_THAN_OR_EQUAL_TO,
    LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX,
    PER_MILLE_SIGN,
    COMBINING_RING_ABOVE,
    MICRO_SIGN,
    MULTIPLICATION_SIGN,
    COMBINING_DIAERESIS,
    INVERTED_EXCLAMATION_MARK,
    COMBINING_ACUTE_ACCENT,
    LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX,
    COMBINING_GRAVE_ACCENT,
    LATIN_SMALL_LETTER_A_WITH_GRAVE,
    LATIN_CAPITAL_LETTER_A_WITH_GRAVE,
    COMBINING_CARON,
    LATIN_SMALL_LETTER_E_WITH_ACUTE,
    LATIN_CAPITAL_LETTER_E_WITH_ACUTE,
    LATIN_SMALL_LETTER_E_WITH_GRAVE,
    LATIN_CAPITAL_LETTER_E_WITH_GRAVE,
    LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX,
    COMBINING_DOT_ABOVE,
    LATIN_SMALL_LETTER_N_WITH_TILDE,
    LATIN_CAPITAL_LETTER_N_WITH_TILDE,
    NOT_EQUAL_TO,
    COMBINING_LONG_SOLIDUS_OVERLAY,
    PLUS_SIGN_ABOVE_EQUALS_SIGN,
    LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX,
    COMBINING_MACRON,
    LATIN_SMALL_LETTER_I_WITH_DIAERESIS,
    LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS,
    DIVISION_SIGN,
    LATIN_SMALL_LETTER_U_WITH_GRAVE,
    LATIN_CAPITAL_LETTER_U_WITH_GRAVE,
    COMBINING_DOUBLE_ACUTE_ACCENT,
    LATIN_SMALL_LETTER_AE,
    LATIN_CAPITAL_LETTER_AE,
    COMBINING_TILDE,
    COMBINING_COMMA_BELOW,
    NON_BREAKING_HYPHEN,
    INVERTED_QUESTION_MARK,
    COMBINING_OGONEK,
    EN_DASH,
    EM_DASH,
    HORIZONTAL_ELLIPSIS,
    BROKEN_BAR,
    NOT_SIGN,
    COMBINING_TURNED_COMMA_ABOVE,
    MIDDLE_DOT,
    BULLET,
    COMBINING_BREVE,
    EURO_SIGN,
    DOUBLE_LOW_9_QUOTATION_MARK,
    SINGLE_LOW_9_QUOTATION_MARK,
    SUBSCRIPT_ONE,
    SUPERSCRIPT_ONE,
    LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK,
    LEFT_DOUBLE_QUOTATION_MARK,
    LEFT_SINGLE_QUOTATION_MARK,
    SUBSCRIPT_TWO,
    SUPERSCRIPT_TWO,
    RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK,
    DOUBLE_HIGH_REVERSED_9_QUOTATION_MARK,
    RIGHT_SINGLE_QUOTATION_MARK,
    SUBSCRIPT_THREE,
    SUPERSCRIPT_THREE,
    CENT_SIGN,
    SUBSCRIPT_FOUR,
    SUPERSCRIPT_FOUR,
    SUBSCRIPT_FIVE,
    SUPERSCRIPT_FIVE,
    SUBSCRIPT_SIX,
    SUPERSCRIPT_SIX,
    SUBSCRIPT_SEVEN,
    SUPERSCRIPT_SEVEN,
    SECTION_SIGN,
    SUBSCRIPT_EIGHT,
    SUPERSCRIPT_EIGHT,
    PILCROW_SIGN,
    SUBSCRIPT_NINE,
    SUPERSCRIPT_NINE,
    DEGREE_SIGN,
    SUBSCRIPT_ZERO,
    SUPERSCRIPT_ZERO,
    NARROW_NO_BREAK_SPACE,
};

const uint32_t PROGMEM unicode_map[] = {
    [LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX]       = 0x00e2 /* â */,
    [LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX]     = 0x00c2 /* Â */,
    [COMBINING_CIRCUMFLEX_ACCENT]                = 0x0302 /* ̂ */,
    [LATIN_SMALL_LETTER_C_WITH_CEDILLA]          = 0x00e7 /* ç */,
    [LATIN_CAPITAL_LETTER_C_WITH_CEDILLA]        = 0x00c7 /* Ç */,
    [LESS_THAN_OR_EQUAL_TO]                      = 0x2264 /* ≤ */,
    [LATIN_SMALL_LIGATURE_OE]                    = 0x0153 /* œ */,
    [LATIN_CAPITAL_LIGATURE_OE]                  = 0x0152 /* Œ */,
    [GREATER_THAN_OR_EQUAL_TO]                   = 0x2265 /* ≥ */,
    [LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX]       = 0x00f4 /* ô */,
    [LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX]     = 0x00d4 /* Ô */,
    [PER_MILLE_SIGN]                             = 0x2030 /* ‰ */,
    [COMBINING_RING_ABOVE]                       = 0x030a /* ̊ */,
    [MICRO_SIGN]                                 = 0x00b5 /* µ */,
    [MULTIPLICATION_SIGN]                        = 0x00d7 /* × */,
    [COMBINING_DIAERESIS]                        = 0x0308 /* ̈ */,
    [INVERTED_EXCLAMATION_MARK]                  = 0x00a1 /* ¡ */,
    [COMBINING_ACUTE_ACCENT]                     = 0x0301 /* ́ */,
    [LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX]       = 0x00fb /* û */,
    [LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX]     = 0x00db /* Û */,
    [COMBINING_GRAVE_ACCENT]                     = 0x0300 /* ̀ */,
    [LATIN_SMALL_LETTER_A_WITH_GRAVE]            = 0x00e0 /* à */,
    [LATIN_CAPITAL_LETTER_A_WITH_GRAVE]          = 0x00c0 /* À */,
    [COMBINING_CARON]                            = 0x030c /* ̌ */,
    [LATIN_SMALL_LETTER_E_WITH_ACUTE]            = 0x00e9 /* é */,
    [LATIN_CAPITAL_LETTER_E_WITH_ACUTE]          = 0x00c9 /* É */,
    [LATIN_SMALL_LETTER_E_WITH_GRAVE]            = 0x00e8 /* è */,
    [LATIN_CAPITAL_LETTER_E_WITH_GRAVE]          = 0x00c8 /* È */,
    [LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX]       = 0x00ea /* ê */,
    [LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX]     = 0x00ca /* Ê */,
    [COMBINING_DOT_ABOVE]                        = 0x0307 /* ̇ */,
    [LATIN_SMALL_LETTER_N_WITH_TILDE]            = 0x00f1 /* ñ */,
    [LATIN_CAPITAL_LETTER_N_WITH_TILDE]          = 0x00d1 /* Ñ */,
    [NOT_EQUAL_TO]                               = 0x2260 /* ≠ */,
    [COMBINING_LONG_SOLIDUS_OVERLAY]             = 0x0338 /* ̸ */,
    [PLUS_SIGN_ABOVE_EQUALS_SIGN]                = 0x2a72 /* ⩲ */,
    [LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX]       = 0x00ee /* î */,
    [LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX]     = 0x00ce /* Î */,
    [COMBINING_MACRON]                           = 0x0304 /* ̄ */,
    [LATIN_SMALL_LETTER_I_WITH_DIAERESIS]        = 0x00ef /* ï */,
    [LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS]      = 0x00cf /* Ï */,
    [DIVISION_SIGN]                              = 0x00f7 /* ÷ */,
    [LATIN_SMALL_LETTER_U_WITH_GRAVE]            = 0x00f9 /* ù */,
    [LATIN_CAPITAL_LETTER_U_WITH_GRAVE]          = 0x00d9 /* Ù */,
    [COMBINING_DOUBLE_ACUTE_ACCENT]              = 0x030b /* ̋ */,
    [LATIN_SMALL_LETTER_AE]                      = 0x00e6 /* æ */,
    [LATIN_CAPITAL_LETTER_AE]                    = 0x00c6 /* Æ */,
    [COMBINING_TILDE]                            = 0x0303 /* ̃ */,
    [COMBINING_COMMA_BELOW]                      = 0x0326 /* ̦ */,
    [NON_BREAKING_HYPHEN]                        = 0x2011 /* ‑ */,
    [INVERTED_QUESTION_MARK]                     = 0x00bf /* ¿ */,
    [COMBINING_OGONEK]                           = 0x0328 /* ̨ */,
    [EN_DASH]                                    = 0x2013 /* – */,
    [EM_DASH]                                    = 0x2014 /* — */,
    [HORIZONTAL_ELLIPSIS]                        = 0x2026 /* … */,
    [BROKEN_BAR]                                 = 0x00a6 /* ¦ */,
    [NOT_SIGN]                                   = 0x00ac /* ¬ */,
    [COMBINING_TURNED_COMMA_ABOVE]               = 0x0312 /* ̒ */,
    [MIDDLE_DOT]                                 = 0x00b7 /* · */,
    [BULLET]                                     = 0x2022 /* • */,
    [COMBINING_BREVE]                            = 0x0306 /* ̆ */,
    [EURO_SIGN]                                  = 0x20ac /* € */,
    [DOUBLE_LOW_9_QUOTATION_MARK]                = 0x201e /* „ */,
    [SINGLE_LOW_9_QUOTATION_MARK]                = 0x201a /* ‚ */,
    [SUBSCRIPT_ONE]                              = 0x2081 /* ₁ */,
    [SUPERSCRIPT_ONE]                            = 0x00b9 /* ¹ */,
    [LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK]  = 0x00ab /* « */,
    [LEFT_DOUBLE_QUOTATION_MARK]                 = 0x201c /* “ */,
    [LEFT_SINGLE_QUOTATION_MARK]                 = 0x2018 /* ‘ */,
    [SUBSCRIPT_TWO]                              = 0x2082 /* ₂ */,
    [SUPERSCRIPT_TWO]                            = 0x00b2 /* ² */,
    [RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK] = 0x00bb /* » */,
    [DOUBLE_HIGH_REVERSED_9_QUOTATION_MARK]      = 0x201f /* ‟ */,
    [RIGHT_SINGLE_QUOTATION_MARK]                = 0x2019 /* ’ */,
    [SUBSCRIPT_THREE]                            = 0x2083 /* ₃ */,
    [SUPERSCRIPT_THREE]                          = 0x00b3 /* ³ */,
    [CENT_SIGN]                                  = 0x00a2 /* ¢ */,
    [SUBSCRIPT_FOUR]                             = 0x2084 /* ₄ */,
    [SUPERSCRIPT_FOUR]                           = 0x2074 /* ⁴ */,
    [SUBSCRIPT_FIVE]                             = 0x2085 /* ₅ */,
    [SUPERSCRIPT_FIVE]                           = 0x2075 /* ⁵ */,
    [SUBSCRIPT_SIX]                              = 0x2086 /* ₆ */,
    [SUPERSCRIPT_SIX]                            = 0x2076 /* ⁶ */,
    [SUBSCRIPT_SEVEN]                            = 0x2087 /* ₇ */,
    [SUPERSCRIPT_SEVEN]                          = 0x2077 /* ⁷ */,
    [SECTION_SIGN]                               = 0x00a7 /* § */,
    [SUBSCRIPT_EIGHT]                            = 0x2088 /* ₈ */,
    [SUPERSCRIPT_EIGHT]                          = 0x2078 /* ⁸ */,
    [PILCROW_SIGN]                               = 0x00b6 /* ¶ */,
    [SUBSCRIPT_NINE]                             = 0x2089 /* ₉ */,
    [SUPERSCRIPT_NINE]                           = 0x2079 /* ⁹ */,
    [DEGREE_SIGN]                                = 0x00b0 /* ° */,
    [SUBSCRIPT_ZERO]                             = 0x2080 /* ₀ */,
    [SUPERSCRIPT_ZERO]                           = 0x2070 /* ⁰ */,
    [NARROW_NO_BREAK_SPACE]                      = 0x202f /*   */,
};

const key_override_t Base_EKC_4    = ko_make_with_layers(MOD_MASK_SHIFT, KC_4, KC_DLR, (1 << Base));
const key_override_t Base_EKC_5    = ko_make_with_layers(MOD_MASK_SHIFT, KC_5, KC_PERC, (1 << Base));
const key_override_t Base_EKC_6    = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, KC_CIRC, (1 << Base));
const key_override_t Base_EKC_7    = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, KC_AMPR, (1 << Base));
const key_override_t Base_EKC_8    = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, KC_ASTR, (1 << Base));
const key_override_t Base_EKC_9    = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, KC_HASH, (1 << Base));
const key_override_t Base_EKC_0    = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_AT, (1 << Base));
const key_override_t Base_EKC_DK   = ko_make_with_layers(MOD_MASK_SHIFT, OSL(DK), KC_EXLM, (1 << Base));
const key_override_t Base_EKC_U    = ko_make_with_layers(MOD_MASK_SHIFT, LT(Media, KC_U), KC_U, (1 << Base));
const key_override_t Base_EKC_MNS  = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_QUES, (1 << Base));
const key_override_t Base_EKC_DOT  = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, (1 << Base));
const key_override_t Base_EKC_COMM = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, (1 << Base));
const key_override_t DK_EKC_D      = ko_make_with_layers(MOD_MASK_SHIFT, KC_UNDS, KC_UNDS, (1 << DK));
const key_override_t DK_EKC_L      = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_LPRN, (1 << DK));
const key_override_t DK_EKC_R      = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_RPRN, (1 << DK));
const key_override_t Sym_EKC_P     = ko_make_with_layers(MOD_MASK_SHIFT, KC_DLR, KC_DLR, (1 << Sym));
const key_override_t Sym_EKC_M     = ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPR, KC_AMPR, (1 << Sym));
const key_override_t Sym_EKC_S     = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_LPRN, (1 << Sym));
const key_override_t Sym_EKC_E     = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_RPRN, (1 << Sym));
const key_override_t Sym_EKC_B     = ko_make_with_layers(MOD_MASK_SHIFT, KC_HASH, KC_HASH, (1 << Sym));
const key_override_t Sym_EKC_COMM  = ko_make_with_layers(MOD_MASK_SHIFT, KC_COLN, KC_COLN, (1 << Sym));
const key_override_t Sym_EKC_SPC   = ko_make_with_layers(MOD_MASK_SHIFT, KC_SPC, KC_SPC, (1 << Sym));

const key_override_t **key_overrides = (const key_override_t *[]){
    &Base_EKC_4, &Base_EKC_5, &Base_EKC_6, &Base_EKC_7, &Base_EKC_8, &Base_EKC_9, &Base_EKC_0, &Base_EKC_DK, &Base_EKC_U, &Base_EKC_MNS, &Base_EKC_DOT, &Base_EKC_COMM, &DK_EKC_D, &DK_EKC_L, &DK_EKC_R, &Sym_EKC_P, &Sym_EKC_M, &Sym_EKC_S, &Sym_EKC_E, &Sym_EKC_B, &Sym_EKC_COMM, &Sym_EKC_SPC, NULL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Base] = LAYOUT(
        // clang-format off

            KC_ESC     ,   Base_EKC_1   ,   Base_EKC_2   ,   Base_EKC_3   ,      KC_4      ,      KC_5      , LT(Fn, KC_ESC) ,           LT(Fn, KC_ESC) ,      KC_6      ,      KC_7      ,      KC_8      ,      KC_9      ,      KC_0      ,     QK_BOOT    ,
            KC_TAB     ,      KC_Q      ,      KC_C      ,      KC_O      ,      KC_P      ,      KC_W      ,     KC_DEL     ,               KC_BSPC    ,      KC_J      ,      KC_M      ,      KC_D      ,     OSL(DK)    ,      KC_Y      ,     _______    ,
            KC_GRV     ,      KC_A      ,      KC_S      ,      KC_E      ,      KC_N      ,      KC_F      ,     _______    ,               _______    ,      KC_L      ,      KC_R      ,      KC_T      ,      KC_I      , LT(Media, KC_U),     _______    ,
            KC_LSFT    ,      KC_Z      ,      KC_X      ,     KC_MINS    ,      KC_V      ,      KC_B      ,                       KC_DOT     ,      KC_H      ,      KC_G      ,     KC_COMM    ,      KC_K      ,     KC_RSFT    ,
            KC_LCTL    ,     _______    ,     KC_LEFT    ,    KC_RIGHT    ,     KC_LGUI    ,             _______    ,         _______    ,            KC_UP     ,     KC_DOWN    ,     _______    ,     _______    ,     _______    ,
                                MO(Sym)    ,     _______    ,     _______    ,         _______    ,    KC_ENTER    ,  Base_EKC_SPC

        // clang-format on
        ),
    [DK] = LAYOUT(
        // clang-format off

          _______  ,  DK_EKC_1  ,  DK_EKC_2  ,  DK_EKC_3  ,  DK_EKC_4  ,  DK_EKC_5  ,   _______  ,             _______  ,   _______  ,   _______  ,  DK_EKC_8  ,  DK_EKC_9  ,  DK_EKC_0  ,   _______  ,
          _______  ,  DK_EKC_Q  ,  DK_EKC_C  ,  DK_EKC_O  ,  DK_EKC_P  ,   _______  ,   _______  ,             _______  ,   _______  ,  DK_EKC_M  ,   KC_UNDS  ,  DK_EKC_DK ,  DK_EKC_Y  ,   _______  ,
          _______  ,  DK_EKC_A  ,  DK_EKC_S  ,  DK_EKC_E  ,  DK_EKC_N  ,  DK_EKC_F  ,   _______  ,             _______  ,   KC_LPRN  ,   KC_RPRN  ,  DK_EKC_T  ,  DK_EKC_I  ,  DK_EKC_U  ,   _______  ,
          _______  ,  DK_EKC_Z  ,   _______  , DK_EKC_MNS ,  DK_EKC_V  ,  DK_EKC_B  ,                   DK_EKC_DOT ,   _______  ,   _______  , DK_EKC_COMM,   _______  ,   _______  ,
          _______  ,   _______  ,   _______  ,   _______  ,   _______  ,           _______  ,       _______  ,         _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
                              _______  ,   _______  ,   _______  ,       _______  ,   _______  , DK_EKC_SPC

        // clang-format on
        ),
    [Sym] = LAYOUT(
        // clang-format off

          _______  ,  Sym_EKC_1 ,  Sym_EKC_2 ,  Sym_EKC_3 ,  Sym_EKC_4 ,  Sym_EKC_5 ,   _______  ,             _______  ,  Sym_EKC_6 ,  Sym_EKC_7 ,  Sym_EKC_8 ,  Sym_EKC_9 ,  Sym_EKC_0 ,   _______  ,
          _______  ,  Sym_EKC_Q ,  Sym_EKC_C ,  Sym_EKC_O ,   KC_DLR   ,  Sym_EKC_W ,   _______  ,             _______  ,  Sym_EKC_J ,   KC_AMPR  ,  Sym_EKC_D , Sym_EKC_DK ,  Sym_EKC_Y ,   _______  ,
          _______  ,  Sym_EKC_A ,   KC_LPRN  ,   KC_RPRN  ,  Sym_EKC_N ,  Sym_EKC_F ,   _______  ,             _______  ,  Sym_EKC_L ,  Sym_EKC_R ,  Sym_EKC_T ,  Sym_EKC_I ,  Sym_EKC_U ,   _______  ,
          _______  ,  Sym_EKC_Z ,  Sym_EKC_X , Sym_EKC_MNS,  Sym_EKC_V ,   KC_HASH  ,                   Sym_EKC_DOT,  Sym_EKC_H ,  Sym_EKC_G ,   KC_COLN  ,  Sym_EKC_K ,   _______  ,
          _______  ,   _______  ,   _______  ,   _______  ,   _______  ,           _______  ,       _______  ,         _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
                              _______  ,   _______  ,   _______  ,       _______  ,   _______  ,   KC_SPC

        // clang-format on
        ),
    [Media] = LAYOUT(
        // clang-format off

        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, KC_PWR , QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, KC_MPRV, KC_MNXT, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,     _______,       UC_NEXT, UC_PREV, _______, _______, _______,
                            KC_PGDN, KC_PGUP, _______,     _______, _______, _______

        // clang-format on
        ),
    [Fn] = LAYOUT(
        // clang-format off

         KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 , _______,           _______,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_VAD, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,     _______,       _______, _______, _______, _______, _______,
                            _______, _______, _______,     _______, _______, _______

        // clang-format on
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const bool key_pressed = record->event.pressed;
    const bool shifted     = (get_mods() & MOD_MASK_SHIFT) != 0;
    uint16_t   kc;
    uint32_t   skc;
    switch (keycode) {
        default:
            return true;

        case Base_EKC_1:
            kc  = KC_1;
            skc = 0x20ac;
            break;

        case Base_EKC_2:
            kc  = KC_2;
            skc = 0x00ab;
            break;

        case Base_EKC_3:
            kc  = KC_3;
            skc = 0x00bb;
            break;

        case Base_EKC_SPC:
            kc  = KC_SPC;
            skc = 0x202f;
            break;

        case Sym_EKC_Q:
            kc  = KC_CIRC;
            skc = 0x0302;
            break;

        case Sym_EKC_C:
            kc  = KC_LABK;
            skc = 0x2264;
            break;

        case Sym_EKC_O:
            kc  = KC_RABK;
            skc = 0x2265;
            break;

        case Sym_EKC_W:
            kc  = KC_PERC;
            skc = 0x2030;
            break;

        case Sym_EKC_J:
            kc  = KC_AT;
            skc = 0x030a;
            break;

        case Sym_EKC_D:
            kc  = KC_ASTR;
            skc = 0x00d7;
            break;

        case Sym_EKC_DK:
            kc  = KC_QUOT;
            skc = 0x0301;
            break;

        case Sym_EKC_Y:
            kc  = KC_GRV;
            skc = 0x0300;
            break;

        case Sym_EKC_A:
            kc  = KC_LCBR;
            skc = 0x030c;
            break;

        case Sym_EKC_N:
            kc  = KC_RCBR;
            skc = 0x0307;
            break;

        case Sym_EKC_F:
            kc  = KC_EQL;
            skc = 0x2260;
            break;

        case Sym_EKC_L:
            kc  = KC_BSLS;
            skc = 0x0338;
            break;

        case Sym_EKC_R:
            kc  = KC_PLUS;
            skc = 0x2a72;
            break;

        case Sym_EKC_T:
            kc  = KC_MINS;
            skc = 0x0304;
            break;

        case Sym_EKC_I:
            kc  = KC_SLSH;
            skc = 0x00f7;
            break;

        case Sym_EKC_U:
            kc  = KC_DQUO;
            skc = 0x030b;
            break;

        case Sym_EKC_Z:
            kc  = KC_TILD;
            skc = 0x0303;
            break;

        case Sym_EKC_X:
            kc  = KC_LBRC;
            skc = 0x0326;
            break;

        case Sym_EKC_MNS:
            kc  = KC_RBRC;
            skc = 0x0328;
            break;

        case Sym_EKC_V:
            kc  = KC_UNDS;
            skc = 0x2013;
            break;

        case Sym_EKC_DOT:
            kc  = KC_PIPE;
            skc = 0x00a6;
            break;

        case Sym_EKC_H:
            kc  = KC_EXLM;
            skc = 0x00ac;
            break;

        case Sym_EKC_G:
            kc  = KC_SCLN;
            skc = 0x0312;
            break;

        case Sym_EKC_K:
            kc  = KC_QUES;
            skc = 0x0306;
            break;
    }

    if (shifted) {
        if (key_pressed) {
            uint8_t temp_mod = get_mods();
            clear_mods();
            register_unicode(skc);
            set_mods(temp_mod);
            return false;
        }
    } else {
        if (key_pressed) {
            register_code16(kc);
        } else {
            unregister_code16(kc);
        }
    }

    return true;
}
