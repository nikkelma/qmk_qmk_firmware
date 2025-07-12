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
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(3, RGB_RED);
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
