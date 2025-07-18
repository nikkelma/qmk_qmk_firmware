/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 Matt Nikkel <matt.nikkel@hey.com>


This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include <lib/lib8tion/lib8tion.h>

// RGB LED locations
typedef enum led_location_map {
    LED_ESC, // 0, ESC, k13
    LED_GRV, // 1, ~, k16
    LED_TAB, // 2, Tab, k11
    LED_CAPS, // 3, Caps, k21
    LED_LSFT, // 4, Sh_L, k00
    LED_LCTL, // 5, Ct_L, k06
    LED_F1, // 6, F1, k26
    LED_1, // 7, 1, k17
    LED_Q, // 8, Q, k10
    LED_A, // 9, A, k12
    LED_Z, // 10, Z, k14
    LED_LWIN, // 11, Win_L, k90
    LED_F2, // 12, F2, k36
    LED_2, // 13, 2, k27
    LED_W, // 14, W, k20
    LED_S, // 15, S, k22
    LED_X, // 16, X, k24
    LED_LALT, // 17, Alt_L, k93
    LED_F3, // 18, F3, k31
    LED_3, // 19, 3, k37
    LED_E, // 20, E, k30
    LED_D, // 21, D, k32
    LED_C, // 22, C, k34
    LED_F4, // 23, F4, k33
    LED_4, // 24, 4, k47
    LED_R, // 25, R, k40
    LED_F, // 26, F, k42
    LED_V, // 27, V, k44
    LED_F5, // 28, F5, k07
    LED_5, // 29, 5, k46
    LED_T, // 30, T, k41
    LED_G, // 31, G, k43
    LED_B, // 32, B, k45
    LED_SPC, // 33, SPACE, k94
    LED_F6, // 34, F6, k63
    LED_6, // 35, 6, k56
    LED_Y, // 36, Y, k51
    LED_H, // 37, H, k53
    LED_N, // 38, N, k55
    LED_F7, // 39, F7, k71
    LED_7, // 40, 7, k57
    LED_U, // 41, U, k50
    LED_J, // 42, J, k52
    LED_M, // 43, M, k54
    LED_F8, // 44, F8, k76
    LED_8, // 45, 8, k67
    LED_I, // 46, I, k60
    LED_K, // 47, K, k62
    LED_COMM, // 48, ,, k64
    LED_RALT, // 49, Alt_R, k95
    LED_F9, // 50, F9, ka6
    LED_9, // 51, 9, k77
    LED_O, // 52, O, k70
    LED_L, // 53, L, k72
    LED_DOT, // 54, ., k74
    LED_FN, // 55, FN, k92
    LED_F10, // 56, F10, ka7
    LED_0, // 57, 0, k87
    LED_P, // 58, P, k80
    LED_SCLN, // 59, ;, k82
    LED_SLSH, // 60, ?, k85
    LED_F11, // 61, F11, ka3
    LED_MINS, // 62, -, k86
    LED_LBRC, // 63, [, k81
    LED_QUOT, // 64, ", k83
    LED_RCTL, // 65, Ct_R, k04
    LED_F12, // 66, F12, ka5
    LED_L1, // 67, LED, l01
    LED_R1, // 68, LED, l11
    LED_DEL, // 69, Prt, k97  -- remapped to Del
    LED_L2, // 70, LED, l02
    LED_R2, // 71, LED, l12
    LED_HOME, // 72, Del, k65 -- remapped to Home
    LED_L3, // 73, LED, l03
    LED_R3, // 74, LED, l13
    LED_END, // 75, PgUp, k15 -- remapped to End
    LED_L4, // 76, LED, l04
    LED_R4, // 77, LED, l14
    LED_EQL, // 78, =, k66
    LED_RIGHT, // 79, Right, k05
    LED_L5, // 80, LED, l05
    LED_R5, // 81, LED, l15
    LED_PGDN, // 82, End, k75 -- remapped to PgDn
    LED_L6, // 83, LED, l06
    LED_R6, // 84, LED, l16
    LED_BSPC, // 85, BSpc, ka1
    LED_PGUP, // 86, PgDn, k25 -- remapped to PgUp
    LED_L7, // 87, LED, l07
    LED_R7, // 88, LED, l17
    LED_RBRC, // 89, ], k61
    LED_RSFT, // 90, Sh_R, k91
    LED_L8, // 91, LED, l08
    LED_R8, // 92, LED, l18
    LED_BSLS, // 93, \, ka2
    LED_UP, // 94, Up, k35
    LED_LEFT, // 95, Left, k03
    LED_ENT, // 96, Enter, ka4
    LED_DOWN // 97, Down, k73
} led_location_map;

// Pulse Blue
// HSV: 112 (uint8_t) / 158 deg, 255, 255
// RGB: 0, 255, 162
#define RGB_PULSE_BLUE(pin) rgb_matrix_set_color(pin, 0, 255, 162)

// Gateway Orange
// HSV: 8 (uint8_t) / 11 deg, 255, 255
// RGB: 255, 48, 0
#define RGB_GATEWAY_ORANGE(pin) rgb_matrix_set_color(pin, 255, 48, 0)

// Gateway Blue
// HSV: 151 (uint8_t) / 213 deg, 207, 255
// RGB: 47, 140, 255
#define RGB_GATEWAY_BLUE(pin) rgb_matrix_set_color(pin, 0, 133, 255)

#define RGB_GATEWAY_WHITE(pin) rgb_matrix_set_color(pin, 255, 255, 255)

typedef enum nikkelma_keycodes {
  NMD_HD8 = SAFE_RANGE,
  NMD_HD1,
  NMD_HU1,
  NMD_HU8,
  NMD_SD8,
  NMD_SD1,
  NMD_SU1,
  NMD_SU8,
  NMD_VD8,
  NMD_VD1,
  NMD_VU1,
  NMD_VU8,
} nikkelma_keycodes;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 End
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgUp
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       PgDn
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, NMD_HD8, NMD_HD1, NMD_HU1, NMD_HU8, NMD_SD8, NMD_SD1, NMD_SU1, NMD_SU8, NMD_VD8, NMD_VD1, NMD_VU1, NMD_VU8, _______,          _______,
        _______, RM_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY,
        _______, _______, RM_VALU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          KC_MNXT,
        _______, _______, RM_VALD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_MPRV,
        _______,          RM_HUED, RM_HUEU, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RM_NEXT, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RM_SPDD, RM_PREV, RM_SPDU
    ),

};
// clang-format on

#ifdef RGB_MATRIX_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NMD_HD8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h = qsub8(rgb_matrix_config.hsv.h, 8);
            }
            return false;
        case NMD_HD1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h = qsub8(rgb_matrix_config.hsv.h, 1);
            }
            return false;
        case NMD_HU1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h = qadd8(rgb_matrix_config.hsv.h, 1);
            }
            return false;
        case NMD_HU8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h = qadd8(rgb_matrix_config.hsv.h, 8);
            }
            return false;
        case NMD_SD8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qsub8(rgb_matrix_config.hsv.s, 8);
            }
            return false;
        case NMD_SD1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qsub8(rgb_matrix_config.hsv.s, 1);
            }
            return false;
        case NMD_SU1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qadd8(rgb_matrix_config.hsv.s, 1);
            }
            return false;
        case NMD_SU8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qadd8(rgb_matrix_config.hsv.s, 8);
            }
            return false;
        case NMD_VD8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qsub8(rgb_matrix_config.hsv.v, 8);
            }
            return false;
        case NMD_VD1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qsub8(rgb_matrix_config.hsv.v, 1);
            }
            return false;
        case NMD_VU1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qadd8(rgb_matrix_config.hsv.v, 1);
            }
            return false;
        case NMD_VU8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qadd8(rgb_matrix_config.hsv.v, 8);
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);
    bool caps_lock_on = host_keyboard_led_state().caps_lock;
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (i) {
            // Left LEDs
            case LED_L1:
            case LED_L2:
            case LED_L3:
            case LED_L4:
            case LED_L5:
            case LED_L6:
            case LED_L7:
            case LED_L8:

            // Right LEDs
            case LED_R1:
            case LED_R2:
            case LED_R3:
            case LED_R4:
            case LED_R5:
            case LED_R6:
            case LED_R7:
            case LED_R8:
                if (caps_lock_on) {
                    RGB_GATEWAY_WHITE(i);
                }
                break;

            // row 1 (F keys)
            case LED_ESC:
                // if (caps_lock_on) {
                //     RGB_GATEWAY_WHITE(i);
                // }
                // break;
            case LED_F1:
            case LED_F2:
            case LED_F3:
            case LED_F4:
            case LED_F5:
            case LED_F6:
            case LED_F7:
            case LED_F8:
            case LED_F9:
            case LED_F10:
            case LED_F11:
            case LED_F12:
            case LED_DEL: // case LED_PRT
                break;

            // row 2 (number keys)
            case LED_GRV:
                // if (caps_lock_on) {
                //     RGB_GATEWAY_WHITE(i);
                // }
                // break;
            case LED_1:
            case LED_2:
            case LED_3:
            case LED_4:
            case LED_5:
            case LED_6:
            case LED_7:
            case LED_8:
            case LED_9:
            case LED_0:
            case LED_MINS:
            case LED_EQL:
            case LED_BSPC:
                break;

            // row 3 (QWERTY)
            case LED_TAB:
            case LED_Q:
            case LED_W:
            case LED_E:
            case LED_R:
            case LED_T:
            case LED_Y:
            case LED_U:
            case LED_I:
            case LED_O:
            case LED_P:
            case LED_LBRC:
            case LED_RBRC:
            case LED_BSLS:
                break;

            // row 4 (ASDF)
            case LED_CAPS:
            case LED_A:
            case LED_S:
            case LED_D:
            case LED_F:
            case LED_G:
            case LED_H:
            case LED_J:
            case LED_K:
            case LED_L:
            case LED_SCLN:
            case LED_QUOT:
            case LED_ENT:
                break;

            // row 5 (ZXCV)
            case LED_LSFT:
            case LED_Z:
            case LED_X:
            case LED_C:
            case LED_V:
            case LED_B:
            case LED_N:
            case LED_M:
            case LED_COMM:
            case LED_DOT:
            case LED_SLSH:
            case LED_RSFT:
                break;

            // row 6 (modifiers + space)
            case LED_LCTL:
            case LED_LWIN:
            case LED_LALT:
            case LED_SPC:
            case LED_RALT:
            case LED_FN:
            case LED_RCTL:
                break;

            // side keys
            case LED_HOME:
            case LED_END:
            case LED_PGUP:
            case LED_PGDN:
                break;

            // arrow keys
            case LED_UP:
            case LED_LEFT:
            case LED_DOWN:
            case LED_RIGHT:
                break;

            default:
                rgb_matrix_set_color(i, 0xff, 0x00, 0x00);
        }
    }
    return false;
}

#endif // RGB_MATRIX_ENABLE

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif // ENCODER_MAP_ENABLE
