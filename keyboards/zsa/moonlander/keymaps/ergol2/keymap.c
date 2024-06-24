
#include QMK_KEYBOARD_H

#include <stdint.h>

#include "keycodes.h"
#include "version.h"

enum layers { Base, DK, Sym };

enum custom_keycodes { _FIRST = SAFE_RANGE };

enum unicode_names {
    EKC_Q_DK_base,
    EKC_Q_DK_shifted,
    EKC_Q_Sym_shifted,
    EKC_C_DK_base,
    EKC_C_DK_shifted,
    EKC_C_Sym_shifted,
    EKC_O_DK_base,
    EKC_O_DK_shifted,
    EKC_O_Sym_shifted,
    EKC_P_DK_base,
    EKC_P_DK_shifted,
    EKC_W_Sym_shifted,
    EKC_J_Sym_shifted,
    EKC_M_DK_base,
    EKC_D_Sym_shifted,
    EKC_DK_DK_shifted,
    EKC_DK_Sym_shifted,
    EKC_Y_DK_base,
    EKC_Y_DK_shifted,
    EKC_Y_Sym_shifted,
    EKC_A_DK_base,
    EKC_A_DK_shifted,
    EKC_A_Sym_shifted,
    EKC_S_DK_base,
    EKC_S_DK_shifted,
    EKC_E_DK_base,
    EKC_E_DK_shifted,
    EKC_N_DK_base,
    EKC_N_DK_shifted,
    EKC_N_Sym_shifted,
    EKC_F_DK_base,
    EKC_F_DK_shifted,
    EKC_F_Sym_shifted,
    EKC_L_Sym_shifted,
    EKC_R_Sym_shifted,
    EKC_T_DK_base,
    EKC_T_DK_shifted,
    EKC_T_Sym_shifted,
    EKC_I_DK_base,
    EKC_I_DK_shifted,
    EKC_I_Sym_shifted,
    EKC_U_DK_base,
    EKC_U_DK_shifted,
    EKC_U_Sym_shifted,
    EKC_Z_DK_base,
    EKC_Z_DK_shifted,
    EKC_Z_Sym_shifted,
    EKC_X_Sym_shifted,
    EKC_MNS_DK_base,
    EKC_MNS_DK_shifted,
    EKC_MNS_Sym_shifted,
    EKC_V_DK_base,
    EKC_B_DK_base,
    EKC_DOT_DK_base,
    EKC_DOT_Sym_shifted,
    EKC_H_Sym_shifted,
    EKC_G_Sym_shifted,
    EKC_COMM_DK_base,
    EKC_COMM_DK_shifted,
    EKC_K_Sym_shifted,
    EKC_1_Base_shifted,
    EKC_1_DK_base,
    EKC_1_DK_shifted,
    EKC_1_Sym_base,
    EKC_1_Sym_shifted,
    EKC_2_Base_shifted,
    EKC_2_DK_base,
    EKC_2_DK_shifted,
    EKC_2_Sym_base,
    EKC_2_Sym_shifted,
    EKC_3_Base_shifted,
    EKC_3_DK_base,
    EKC_3_DK_shifted,
    EKC_3_Sym_base,
    EKC_3_Sym_shifted,
    EKC_4_DK_base,
    EKC_4_Sym_base,
    EKC_4_Sym_shifted,
    EKC_5_Sym_base,
    EKC_5_Sym_shifted,
    EKC_6_Sym_base,
    EKC_6_Sym_shifted,
    EKC_7_Sym_base,
    EKC_7_Sym_shifted,
    EKC_8_DK_base,
    EKC_8_Sym_base,
    EKC_8_Sym_shifted,
    EKC_9_DK_base,
    EKC_9_Sym_base,
    EKC_9_Sym_shifted,
    EKC_0_DK_base,
    EKC_0_Sym_base,
    EKC_0_Sym_shifted,
    EKC_SPC_Base_shifted
};

const uint32_t PROGMEM unicode_map[] = {
    [EKC_Q_DK_base] = 226 /* â */,     [EKC_Q_DK_shifted] = 194 /* Â */,   [EKC_Q_Sym_shifted] = 770 /* ̂ */,   [EKC_C_DK_base] = 231 /* ç */,  [EKC_C_DK_shifted] = 199 /* Ç */, [EKC_C_Sym_shifted] = 8804 /* ≤ */, [EKC_O_DK_base] = 339 /* œ */,       [EKC_O_DK_shifted] = 338 /* Œ */,   [EKC_O_Sym_shifted] = 8805 /* ≥ */, [EKC_P_DK_base] = 244 /* ô */,      [EKC_P_DK_shifted] = 212 /* Ô */,     [EKC_W_Sym_shifted] = 8240 /* ‰ */, [EKC_J_Sym_shifted] = 778 /* ̊ */,    [EKC_M_DK_base] = 181 /* µ */,    [EKC_D_Sym_shifted] = 215 /* × */,  [EKC_DK_DK_shifted] = 161 /* ¡ */, [EKC_DK_Sym_shifted] = 769 /* ́ */, [EKC_Y_DK_base] = 251 /* û */,      [EKC_Y_DK_shifted] = 219 /* Û */, [EKC_Y_Sym_shifted] = 768 /* ̀ */,  [EKC_A_DK_base] = 224 /* à */,      [EKC_A_DK_shifted] = 192 /* À */,  [EKC_A_Sym_shifted] = 780 /* ̌ */,   [EKC_S_DK_base] = 233 /* é */,
    [EKC_S_DK_shifted] = 201 /* É */,  [EKC_E_DK_base] = 232 /* è */,      [EKC_E_DK_shifted] = 200 /* È */,   [EKC_N_DK_base] = 234 /* ê */,  [EKC_N_DK_shifted] = 202 /* Ê */, [EKC_N_Sym_shifted] = 775 /* ̇ */,   [EKC_F_DK_base] = 241 /* ñ */,       [EKC_F_DK_shifted] = 209 /* Ñ */,   [EKC_F_Sym_shifted] = 8800 /* ≠ */, [EKC_L_Sym_shifted] = 824 /* ̸ */,   [EKC_R_Sym_shifted] = 10866 /* ⩲ */,  [EKC_T_DK_base] = 238 /* î */,      [EKC_T_DK_shifted] = 206 /* Î */,    [EKC_T_Sym_shifted] = 772 /* ̄ */, [EKC_I_DK_base] = 239 /* ï */,      [EKC_I_DK_shifted] = 207 /* Ï */,  [EKC_I_Sym_shifted] = 247 /* ÷ */, [EKC_U_DK_base] = 249 /* ù */,      [EKC_U_DK_shifted] = 217 /* Ù */, [EKC_U_Sym_shifted] = 779 /* ̋ */,  [EKC_Z_DK_base] = 230 /* æ */,      [EKC_Z_DK_shifted] = 198 /* Æ */,  [EKC_Z_Sym_shifted] = 771 /* ̃ */,   [EKC_X_Sym_shifted] = 806 /* ̦ */,
    [EKC_MNS_DK_base] = 8209 /* ‑ */,  [EKC_MNS_DK_shifted] = 191 /* ¿ */, [EKC_MNS_Sym_shifted] = 808 /* ̨ */, [EKC_V_DK_base] = 8211 /* – */, [EKC_B_DK_base] = 8212 /* — */,   [EKC_DOT_DK_base] = 8230 /* … */,   [EKC_DOT_Sym_shifted] = 166 /* ¦ */, [EKC_H_Sym_shifted] = 172 /* ¬ */,  [EKC_G_Sym_shifted] = 786 /* ̒ */,   [EKC_COMM_DK_base] = 183 /* · */,   [EKC_COMM_DK_shifted] = 8226 /* • */, [EKC_K_Sym_shifted] = 774 /* ̆ */,   [EKC_1_Base_shifted] = 8364 /* € */, [EKC_1_DK_base] = 8222 /* „ */,   [EKC_1_DK_shifted] = 8218 /* ‚ */,  [EKC_1_Sym_base] = 8321 /* ₁ */,   [EKC_1_Sym_shifted] = 185 /* ¹ */, [EKC_2_Base_shifted] = 171 /* « */, [EKC_2_DK_base] = 8220 /* “ */,   [EKC_2_DK_shifted] = 8216 /* ‘ */, [EKC_2_Sym_base] = 8322 /* ₂ */,    [EKC_2_Sym_shifted] = 178 /* ² */, [EKC_3_Base_shifted] = 187 /* » */, [EKC_3_DK_base] = 8223 /* ‟ */,
    [EKC_3_DK_shifted] = 8217 /* ’ */, [EKC_3_Sym_base] = 8323 /* ₃ */,    [EKC_3_Sym_shifted] = 179 /* ³ */,  [EKC_4_DK_base] = 162 /* ¢ */,  [EKC_4_Sym_base] = 8324 /* ₄ */,  [EKC_4_Sym_shifted] = 8308 /* ⁴ */, [EKC_5_Sym_base] = 8325 /* ₅ */,     [EKC_5_Sym_shifted] = 8309 /* ⁵ */, [EKC_6_Sym_base] = 8326 /* ₆ */,    [EKC_6_Sym_shifted] = 8310 /* ⁶ */, [EKC_7_Sym_base] = 8327 /* ₇ */,      [EKC_7_Sym_shifted] = 8311 /* ⁷ */, [EKC_8_DK_base] = 167 /* § */,       [EKC_8_Sym_base] = 8328 /* ₈ */,  [EKC_8_Sym_shifted] = 8312 /* ⁸ */, [EKC_9_DK_base] = 182 /* ¶ */,     [EKC_9_Sym_base] = 8329 /* ₉ */,   [EKC_9_Sym_shifted] = 8313 /* ⁹ */, [EKC_0_DK_base] = 176 /* ° */,    [EKC_0_Sym_base] = 8320 /* ₀ */,   [EKC_0_Sym_shifted] = 8304 /* ⁰ */, [EKC_SPC_Base_shifted] = 8239 /*   */
};

const key_override_t Base_EKC_DK   = ko_make_basic(MOD_MASK_SHIFT, OSL(DK), KC_EXLM);
const key_override_t Base_EKC_MNS  = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_QUES);
const key_override_t Base_EKC_DOT  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t Base_EKC_COMM = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t Base_EKC_1    = ko_make_basic(MOD_MASK_SHIFT, KC_1, UM(EKC_1_Base_shifted));
const key_override_t Base_EKC_2    = ko_make_basic(MOD_MASK_SHIFT, KC_2, UM(EKC_2_Base_shifted));
const key_override_t Base_EKC_3    = ko_make_basic(MOD_MASK_SHIFT, KC_3, UM(EKC_3_Base_shifted));
const key_override_t Base_EKC_4    = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_DLR);
const key_override_t Base_EKC_5    = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_PERC);
const key_override_t Base_EKC_6    = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_CIRC);
const key_override_t Base_EKC_7    = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_AMPR);
const key_override_t Base_EKC_8    = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_ASTR);
const key_override_t Base_EKC_9    = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_HASH);
const key_override_t Base_EKC_0    = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_AT);
const key_override_t Base_EKC_SPC  = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, UM(EKC_SPC_Base_shifted));
const key_override_t DK_EKC_D      = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_TRNS);
const key_override_t DK_EKC_DK     = ko_make_basic(MOD_MASK_SHIFT, KC_TRNS, UM(EKC_DK_DK_shifted));
const key_override_t DK_EKC_L      = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_TRNS);
const key_override_t DK_EKC_R      = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_TRNS);
const key_override_t Sym_EKC_Q     = ko_make_basic(MOD_MASK_SHIFT, KC_CIRC, UM(EKC_Q_Sym_shifted));
const key_override_t Sym_EKC_C     = ko_make_basic(MOD_MASK_SHIFT, KC_LABK, UM(EKC_C_Sym_shifted));
const key_override_t Sym_EKC_O     = ko_make_basic(MOD_MASK_SHIFT, KC_RABK, UM(EKC_O_Sym_shifted));
const key_override_t Sym_EKC_P     = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, KC_TRNS);
const key_override_t Sym_EKC_W     = ko_make_basic(MOD_MASK_SHIFT, KC_PERC, UM(EKC_W_Sym_shifted));
const key_override_t Sym_EKC_J     = ko_make_basic(MOD_MASK_SHIFT, KC_AT, UM(EKC_J_Sym_shifted));
const key_override_t Sym_EKC_M     = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_TRNS);
const key_override_t Sym_EKC_D     = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, UM(EKC_D_Sym_shifted));
const key_override_t Sym_EKC_DK    = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, UM(EKC_DK_Sym_shifted));
const key_override_t Sym_EKC_Y     = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, UM(EKC_Y_Sym_shifted));
const key_override_t Sym_EKC_A     = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, UM(EKC_A_Sym_shifted));
const key_override_t Sym_EKC_S     = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_TRNS);
const key_override_t Sym_EKC_E     = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_TRNS);
const key_override_t Sym_EKC_N     = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, UM(EKC_N_Sym_shifted));
const key_override_t Sym_EKC_F     = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, UM(EKC_F_Sym_shifted));
const key_override_t Sym_EKC_L     = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, UM(EKC_L_Sym_shifted));
const key_override_t Sym_EKC_R     = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, UM(EKC_R_Sym_shifted));
const key_override_t Sym_EKC_T     = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, UM(EKC_T_Sym_shifted));
const key_override_t Sym_EKC_I     = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, UM(EKC_I_Sym_shifted));
const key_override_t Sym_EKC_U     = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, UM(EKC_U_Sym_shifted));
const key_override_t Sym_EKC_Z     = ko_make_basic(MOD_MASK_SHIFT, KC_TILD, UM(EKC_Z_Sym_shifted));
const key_override_t Sym_EKC_X     = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, UM(EKC_X_Sym_shifted));
const key_override_t Sym_EKC_MNS   = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, UM(EKC_MNS_Sym_shifted));
const key_override_t Sym_EKC_V     = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, UM(EKC_V_DK_base));
const key_override_t Sym_EKC_B     = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_TRNS);
const key_override_t Sym_EKC_DOT   = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, UM(EKC_DOT_Sym_shifted));
const key_override_t Sym_EKC_H     = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, UM(EKC_H_Sym_shifted));
const key_override_t Sym_EKC_G     = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, UM(EKC_G_Sym_shifted));
const key_override_t Sym_EKC_COMM  = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_TRNS);
const key_override_t Sym_EKC_K     = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, UM(EKC_K_Sym_shifted));
const key_override_t Sym_EKC_SPC   = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_TRNS);

const key_override_t **key_overrides = (const key_override_t *[]){&Base_EKC_DK, &Base_EKC_MNS, &Base_EKC_DOT, &Base_EKC_COMM, &Base_EKC_1, &Base_EKC_2, &Base_EKC_3, &Base_EKC_4, &Base_EKC_5, &Base_EKC_6, &Base_EKC_7, &Base_EKC_8, &Base_EKC_9, &Base_EKC_0, &Base_EKC_SPC, &DK_EKC_D, &DK_EKC_DK, &DK_EKC_L, &DK_EKC_R, &Sym_EKC_Q, &Sym_EKC_C, &Sym_EKC_O, &Sym_EKC_P, &Sym_EKC_W, &Sym_EKC_J, &Sym_EKC_M, &Sym_EKC_D, &Sym_EKC_DK, &Sym_EKC_Y, &Sym_EKC_A, &Sym_EKC_S, &Sym_EKC_E, &Sym_EKC_N, &Sym_EKC_F, &Sym_EKC_L, &Sym_EKC_R, &Sym_EKC_T, &Sym_EKC_I, &Sym_EKC_U, &Sym_EKC_Z, &Sym_EKC_X, &Sym_EKC_MNS, &Sym_EKC_V, &Sym_EKC_B, &Sym_EKC_DOT, &Sym_EKC_H, &Sym_EKC_G, &Sym_EKC_COMM, &Sym_EKC_K, &Sym_EKC_SPC, NULL};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Base] = LAYOUT(
        // clang-format off
        KC_ESC ,  KC_1 ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 , _______,           _______,  KC_6 ,  KC_7,   KC_8 ,  KC_9 ,  KC_0 , QK_BOOT,
        KC_TAB ,  KC_Q ,  KC_C ,  KC_O ,  KC_P ,  KC_W , KC_DEL ,           KC_BSPC,  KC_J ,  KC_M ,  KC_D , OSL(DK) ,  KC_Y , _______,
        KC_GRV ,  KC_A ,  KC_S ,  KC_E ,  KC_N ,  KC_F , _______,           _______,  KC_L ,  KC_R ,  KC_T ,  KC_I ,  KC_U , _______,
        KC_LSFT,  KC_Z ,  KC_X , KC_MINS,  KC_V ,  KC_B ,                             KC_DOT,  KC_H ,  KC_G ,KC_COMM,  KC_K , KC_RSFT,
        KC_LCTL, _______, KC_LEFT,KC_RIGHT, KC_LGUI,         _______,            _______,           KC_UP , KC_DOWN, _______, _______, _______,
                                           _______, _______, _______,     _______, KC_ENTER, KC_SPC
        // clang-format on
        ),
    [DK] = LAYOUT(
        // clang-format off
        KC_ESC ,  UP(EKC_1_DK_base, EKC_1_DK_shifted) ,  UP(EKC_2_DK_base, EKC_2_DK_shifted) ,  UP(EKC_3_DK_base, EKC_3_DK_shifted) ,  UM(EKC_4_DK_base) ,  UM(EKC_W_Sym_shifted) , _______,           _______,  KC_TRNS ,  KC_TRNS,   UM(EKC_8_DK_base) ,  UM(EKC_9_DK_base) ,  UM(EKC_0_DK_base) , QK_BOOT,
        KC_TAB ,  UP(EKC_Q_DK_base, EKC_Q_DK_shifted) ,  UP(EKC_C_DK_base, EKC_C_DK_shifted) ,  UP(EKC_O_DK_base, EKC_O_DK_shifted) ,  UP(EKC_P_DK_base, EKC_P_DK_shifted) ,  KC_TRNS , KC_DEL ,           KC_BSPC,  KC_TRNS ,  UM(EKC_M_DK_base) ,  KC_UNDS , KC_TRNS ,  UP(EKC_Y_DK_base, EKC_Y_DK_shifted) , _______,
        KC_GRV ,  UP(EKC_A_DK_base, EKC_A_DK_shifted) ,  UP(EKC_S_DK_base, EKC_S_DK_shifted) ,  UP(EKC_E_DK_base, EKC_E_DK_shifted) ,  UP(EKC_N_DK_base, EKC_N_DK_shifted) ,  UP(EKC_F_DK_base, EKC_F_DK_shifted) , _______,           _______,  KC_LPRN ,  KC_RPRN ,  UP(EKC_T_DK_base, EKC_T_DK_shifted) ,  UP(EKC_I_DK_base, EKC_I_DK_shifted) ,  UP(EKC_U_DK_base, EKC_U_DK_shifted) , _______,
        KC_LSFT,  UP(EKC_Z_DK_base, EKC_Z_DK_shifted) ,  KC_TRNS , UP(EKC_MNS_DK_base, EKC_MNS_DK_shifted),  UM(EKC_V_DK_base) ,  UM(EKC_B_DK_base) ,                             UM(EKC_DOT_DK_base),  KC_TRNS ,  KC_TRNS ,UP(EKC_COMM_DK_base, EKC_COMM_DK_shifted),  KC_TRNS , KC_RSFT,
        KC_LCTL, _______, KC_LEFT,KC_RIGHT, KC_LGUI,         _______,            _______,           KC_UP , KC_DOWN, _______, _______, _______,
                                           _______, _______, _______,     _______, KC_ENTER, UM(EKC_3_DK_shifted)
        // clang-format on
        ),
    [Sym] = LAYOUT(
        // clang-format off
        KC_ESC ,  UP(EKC_1_Sym_base, EKC_1_Sym_shifted) ,  UP(EKC_2_Sym_base, EKC_2_Sym_shifted) ,  UP(EKC_3_Sym_base, EKC_3_Sym_shifted) ,  UP(EKC_4_Sym_base, EKC_4_Sym_shifted) ,  UP(EKC_5_Sym_base, EKC_5_Sym_shifted) , _______,           _______,  UP(EKC_6_Sym_base, EKC_6_Sym_shifted) ,  UP(EKC_7_Sym_base, EKC_7_Sym_shifted),   UP(EKC_8_Sym_base, EKC_8_Sym_shifted) ,  UP(EKC_9_Sym_base, EKC_9_Sym_shifted) ,  UP(EKC_0_Sym_base, EKC_0_Sym_shifted) , QK_BOOT,
        KC_TAB ,  KC_CIRC ,  KC_LABK ,  KC_RABK ,  KC_DLR ,  KC_PERC , KC_DEL ,           KC_BSPC,  KC_AT ,  KC_AMPR ,  KC_ASTR , KC_QUOT ,  KC_GRV , _______,
        KC_GRV ,  KC_LCBR ,  KC_LPRN ,  KC_RPRN ,  KC_RCBR ,  KC_EQL , _______,           _______,  KC_BSLS ,  KC_PLUS ,  KC_MINS ,  KC_SLSH ,  KC_DQUO , _______,
        KC_LSFT,  KC_TILD ,  KC_LBRC , KC_RBRC,  KC_UNDS ,  KC_HASH ,                             KC_PIPE,  KC_EXLM ,  KC_SCLN ,KC_COLN,  KC_QUES , KC_RSFT,
        KC_LCTL, _______, KC_LEFT,KC_RIGHT, KC_LGUI,         _______,            _______,           KC_UP , KC_DOWN, _______, _______, _______,
                                           _______, _______, _______,     _______, KC_ENTER, KC_SPC
        // clang-format on
        )

};
