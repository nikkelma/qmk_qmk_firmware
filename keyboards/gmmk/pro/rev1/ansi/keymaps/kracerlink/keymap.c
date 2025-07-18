/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
    LED_PRT, // 69, Prt, k97
    LED_L2, // 70, LED, l02
    LED_R2, // 71, LED, l12
    LED_DEL, // 72, Del, k65
    LED_L3, // 73, LED, l03
    LED_R3, // 74, LED, l13
    LED_PGUP, // 75, PgUp, k15
    LED_L4, // 76, LED, l04
    LED_R4, // 77, LED, l14
    LED_EQL, // 78, =, k66
    LED_RIGHT, // 79, Right, k05
    LED_L5, // 80, LED, l05
    LED_R5, // 81, LED, l15
    LED_END, // 82, End, k75
    LED_L6, // 83, LED, l06
    LED_R6, // 84, LED, l16
    LED_BSPC, // 85, BSpc, ka1
    LED_PGDN, // 86, PgDn, k25
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

typedef enum nikkelma_keycodes {
    // custom color-focused keycodes
    // -> adjust hue
    NMC_HD8 = SAFE_RANGE,
    NMC_HD1,
    NMC_HU1,
    NMC_HU8,
    // -> adjust saturation
    NMC_SD8,
    NMC_SD1,
    NMC_SU1,
    NMC_SU8,
    // -> adjust value
    NMC_VD8,
    NMC_VD1,
    NMC_VU1,
    NMC_VU8,

    // custom RGB config focused keycodes
    // -> adjust speed
    NMR_SU4,
    NMR_SU1,
    NMR_SD1,
    NMR_SD4,
    // -> write RGB config to eeprom
    NMR_WRT,
} nikkelma_keycodes;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        TG(2),   KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, RM_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RM_VALU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, _______, RM_VALD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          RM_HUED, RM_HUEU, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RM_NEXT, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RM_SPDD, RM_PREV, RM_SPDU
    ),

    [2] = LAYOUT(
        _______, NMC_HD8, NMC_HD1, NMC_HU1, NMC_HU8, NMC_SD8, NMC_SD1, NMC_SU1, NMC_SU8, NMC_VD8, NMC_VD1, NMC_VU1, NMC_VU8, NMR_WRT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          NMR_SU4,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          NMR_SU1,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          NMR_SD1,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, NMR_SD4,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NMC_HD8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h -= 8;
            }
            return false;
        case NMC_HD1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h -= 1;
            }
            return false;
        case NMC_HU1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h += 1;
            }
            return false;
        case NMC_HU8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.h += 8;
            }
            return false;
        case NMC_SD8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qsub8(rgb_matrix_config.hsv.s, 8);
            }
            return false;
        case NMC_SD1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qsub8(rgb_matrix_config.hsv.s, 1);
            }
            return false;
        case NMC_SU1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qadd8(rgb_matrix_config.hsv.s, 1);
            }
            return false;
        case NMC_SU8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.s = qadd8(rgb_matrix_config.hsv.s, 8);
            }
            return false;
        case NMC_VD8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qsub8(rgb_matrix_config.hsv.v, 8);
            }
            return false;
        case NMC_VD1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qsub8(rgb_matrix_config.hsv.v, 1);
            }
            return false;
        case NMC_VU1:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qadd8(rgb_matrix_config.hsv.v, 1);
            }
            return false;
        case NMC_VU8:
            if (record->event.pressed) {
                rgb_matrix_config.hsv.v = qadd8(rgb_matrix_config.hsv.v, 8);
            }
            return false;
        case NMR_SU4:
            if (record->event.pressed) {
                rgb_matrix_config.speed = qadd8(rgb_matrix_config.speed, 4);
            }
            return false;
        case NMR_SU1:
            if (record->event.pressed) {
                rgb_matrix_config.speed = qadd8(rgb_matrix_config.speed, 1);
            }
            return false;
        case NMR_SD1:
            if (record->event.pressed) {
                rgb_matrix_config.speed = qsub8(rgb_matrix_config.speed, 1);
            }
            return false;
        case NMR_SD4:
            if (record->event.pressed) {
                rgb_matrix_config.speed = qsub8(rgb_matrix_config.speed, 4);
            }
            return false;
        case NMR_WRT:
            if (record->event.pressed) {
                // commit all RGB config to eeprom by "re-enabling" RGB, using
                // the eeprom write side effect as the main purpose
                rgb_matrix_enable();
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

#define CAPS_BLINK_MS 250

static bool caps_blink_force_dark;
static uint16_t timer_prev;
static uint16_t remainder;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint16_t timer_cur = timer_read();

    bool caps_lock_on = host_keyboard_led_state().caps_lock;
    if (!caps_lock_on) {
        timer_prev = timer_cur;
        caps_blink_force_dark = false;
        return true;
    }

    uint16_t elapsed = timer_cur + remainder - timer_prev;
    remainder = elapsed % CAPS_BLINK_MS;

    if (elapsed >= CAPS_BLINK_MS) {
        caps_blink_force_dark = !caps_blink_force_dark;
    }

    timer_prev = timer_cur;
    if (!caps_blink_force_dark) {
        return true;
    }

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
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
                break;

            // row 1 (F keys)
            case LED_ESC:
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
            case LED_PRT:

            // row 2 (number keys)
            case LED_GRV:
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

            // row 6 (modifiers + space)
            case LED_LCTL:
            case LED_LWIN:
            case LED_LALT:
            case LED_SPC:
            case LED_RALT:
            case LED_FN:
            case LED_RCTL:

            // side keys
            case LED_DEL:
            case LED_PGUP:
            case LED_PGDN:
            case LED_END:

            // arrow keys
            case LED_UP:
            case LED_LEFT:
            case LED_DOWN:
            case LED_RIGHT:

            default:
                break;
        }
    }
    return true;
}

#endif // RGB_MATRIX_ENABLE

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif
