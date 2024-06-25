#include QMK_KEYBOARD_H

#include "version.h"
#include "config.h"

static void set_let_for_input_mode(uint8_t input_mode);

void keyboard_post_init_user(void) {
    debug_enable = true;
    /* debug_matrix   = true; */
    /* debug_keyboard = true; */
    // debug_mouse=true;

    uint8_t mode;
    switch (detected_host_os()) {
        case OS_UNSURE:
        case OS_LINUX:
            mode = UNICODE_MODE_LINUX;
            break;
        case OS_WINDOWS:
            mode = UNICODE_MODE_WINCOMPOSE;
            break;
        case OS_MACOS:
        case OS_IOS:
            mode = UNICODE_MODE_MACOS;
            break;
    }

    set_unicode_input_mode(mode);
    set_let_for_input_mode(mode);
}

#define HSV_C(h, s, v) ({h, s, v})
#define BLACK HSV_C(0, 0, 0)

// XXX:
enum layers { Base, DK, Sym, Media };

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [Base]  = {LED_LAYOUT_ALL(BLACK)},
    [DK]    = {LED_LAYOUT_ALL(BLACK)},
    [Sym]   = {LED_LAYOUT_ALL(BLACK)},
    [Media] = {LED_LAYOUT_ALL(BLACK)},
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }

    int layer = biton32(layer_state);
    set_layer_color(layer);

    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);

    switch (layer) {
        case 0:
            ML_LED_1(true);
            break;
        case 1:
            ML_LED_2(true);
            break;
        case 2:
            ML_LED_1(true);
            ML_LED_2(true);
            break;
        case 3:
            ML_LED_3(true);
            break;
        case 4:
            ML_LED_1(true);
            ML_LED_3(true);
            break;
        case 5:
            ML_LED_2(true);
            ML_LED_3(true);
            break;
        case 6:
            ML_LED_1(true);
            ML_LED_2(true);
            ML_LED_3(true);
            break;
    }

    return true;
}

static void set_let_for_input_mode(uint8_t input_mode) {
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);
    switch (input_mode) {
        default:
            ML_LED_4(true);
            ML_LED_5(true);
            ML_LED_6(true);
            break;
        case UNICODE_MODE_LINUX:
            ML_LED_4(true);
            break;
        case UNICODE_MODE_WINCOMPOSE:
        case UNICODE_MODE_WINDOWS:
            ML_LED_5(true);
            break;
        case UNICODE_MODE_MACOS:
            ML_LED_6(true);
            break;
    }
}

void unicode_input_mode_set_user(uint8_t input_mode) {
    set_let_for_input_mode(input_mode);
}
