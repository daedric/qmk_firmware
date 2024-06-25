/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Should not be required
// #define ORYX_CONFIGURATOR

// Not sure what it is...
// #define FIRMWARE_VERSION u8"QjAXm/vWLel"

/* #define FR_HOST */

// sets the number of milliseconds to pause after sending a wakeup packet.
// Disabled by default, you might want to set this to 200 (or higher) if the
// keyboard does not wake up properly after suspending

#define USB_SUSPEND_WAKEUP_DELAY 0

/* Set by Oryx to their default value:
 * https://github.com/qmk/qmk_firmware/blob/a4da5f219fe0f202a07afa045fc0c08f6ce1f86b/docs/features/rawhid.md#basic-configuration-basic-configuration
 */
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

// As long as I'm using <= 8 layers
// https://github.com/qmk/qmk_firmware/blob/a4da5f219fe0f202a07afa045fc0c08f6ce1f86b/docs/squeezing_avr.md#layers
#define LAYER_STATE_8BIT

// Default animation speed
#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS

// give me back my leds :)
#define MOONLANDER_USER_LEDS

#if 0
#    define AUTO_SHIFT_TIMEOUT 175
// NO_AUTO_SHIFT_TAB (simple define)
// Do not Auto Shift KC_TAB but leave Auto Shift enabled for the other special
// characters.
// Autoshift has doc there: docs/features/auto_shift.md
// https://github.com/qmk/qmk_firmware/blob/a4da5f219fe0f202a07afa045fc0c08f6ce1f86b/docs/features/auto_shift.md
#    define NO_AUTO_SHIFT_TAB
#endif

// From https://stackoverflow.com/a/62984543
#define DEPAREN(X) ESC(ISH X)
#define ISH(...) ISH __VA_ARGS__
#define ESC(...) ESC_(__VA_ARGS__)
#define ESC_(...) VAN##__VA_ARGS__
#define VANISH

// clang-format off
#define LED_LAYOUT(l0, l5, l10, l15, l20, l25, l29, l65, l61, l56, l51, l46, l41, l36, l1, l6, l11, l16, l21, l26, l30, l66, l62, l57, l52, l47, l42, l37, l2, l7, l12, l17, l22, l27, l31, l67, l63, l58, l53, l48, l43, l38, l3, l8, l13, l18, l23, l28, l64, l59, l54, l49, l44, l39, l4, l9, l14, l19, l24, l35, l71, l60, l55, l50, l45, l40, l32, l33, l34, l70, l69, l68) \
    DEPAREN(l0), DEPAREN(l5), DEPAREN(l10), DEPAREN(l15), DEPAREN(l20), DEPAREN(l25), DEPAREN(l29),              DEPAREN(l65), DEPAREN(l61), DEPAREN(l56), DEPAREN(l51), DEPAREN(l46), DEPAREN(l41), DEPAREN(l36), \
    DEPAREN(l1), DEPAREN(l6), DEPAREN(l11), DEPAREN(l16), DEPAREN(l21), DEPAREN(l26), DEPAREN(l30),              DEPAREN(l66), DEPAREN(l62), DEPAREN(l57), DEPAREN(l52), DEPAREN(l47), DEPAREN(l42), DEPAREN(l37), \
    DEPAREN(l2), DEPAREN(l7), DEPAREN(l12), DEPAREN(l17), DEPAREN(l22), DEPAREN(l27), DEPAREN(l31),              DEPAREN(l67), DEPAREN(l63), DEPAREN(l58), DEPAREN(l53), DEPAREN(l48), DEPAREN(l43), DEPAREN(l38), \
    DEPAREN(l3), DEPAREN(l8), DEPAREN(l13), DEPAREN(l18), DEPAREN(l23), DEPAREN(l28),                        DEPAREN(l64), DEPAREN(l59), DEPAREN(l54), DEPAREN(l49), DEPAREN(l44), DEPAREN(l39), \
    DEPAREN(l4), DEPAREN(l9), DEPAREN(l14), DEPAREN(l19), DEPAREN(l24),      DEPAREN(l35),              DEPAREN(l71),      DEPAREN(l60), DEPAREN(l55), DEPAREN(l50), DEPAREN(l45), DEPAREN(l40), \
                           DEPAREN(l32), DEPAREN(l33), DEPAREN(l34),    DEPAREN(l70), DEPAREN(l69), DEPAREN(l68)
// clang-format on

#define LED_LAYOUT_ALL(color) LED_LAYOUT(color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color, color)
