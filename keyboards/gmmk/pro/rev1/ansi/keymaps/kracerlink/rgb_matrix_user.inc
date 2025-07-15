// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(solid_color_debug_rgb)
RGB_MATRIX_EFFECT(solid_color_debug_hsv)
RGB_MATRIX_EFFECT(spectrum_sides_rgb_main)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

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

// Solid color debug (RGB): allow figuring out ideal RGB without constantly
// reflashing the KB

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

// Solid color debug (RGB): allow figuring out ideal RGB without constantly
// reflashing the KB
static bool solid_color_debug_rgb(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_t rgb = hsv_to_rgb(rgb_matrix_config.hsv);
        switch (i) {
            case LED_F1:
                rgb_matrix_set_color(i, 0, 0, 0);
                break;
            case LED_F2:
                rgb_matrix_set_color(i, 85, 0, 0);
                break;
            case LED_F3:
                rgb_matrix_set_color(i, 170, 0, 0);
                break;
            case LED_F4:
                rgb_matrix_set_color(i, 255, 0, 0);
                break;

            case LED_F5:
                rgb_matrix_set_color(i, 0, 0, 0);
                break;
            case LED_F6:
                rgb_matrix_set_color(i, 0, 85, 0);
                break;
            case LED_F7:
                rgb_matrix_set_color(i, 0, 171, 0);
                break;
            case LED_F8:
                rgb_matrix_set_color(i, 0, 255, 0);
                break;

            case LED_F9:
                rgb_matrix_set_color(i, 0, 0, 0);
                break;
            case LED_F10:
                rgb_matrix_set_color(i, 0, 0, 85);
                break;
            case LED_F11:
                rgb_matrix_set_color(i, 0, 0, 171);
                break;
            case LED_F12:
                rgb_matrix_set_color(i, 0, 0, 255);
                break;

            case LED_1:
                ((rgb.r >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_2:
                ((rgb.r >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_3:
                ((rgb.r >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_4:
                ((rgb.r >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_5:
                ((rgb.r >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_6:
                ((rgb.r >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_7:
                ((rgb.r >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_8:
                ((rgb.r >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;

            case LED_Q:
                ((rgb.g >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_W:
                ((rgb.g >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_E:
                ((rgb.g >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_R:
                ((rgb.g >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_T:
                ((rgb.g >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_Y:
                ((rgb.g >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_U:
                ((rgb.g >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_I:
                ((rgb.g >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;

            case LED_A:
                ((rgb.b >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_S:
                ((rgb.b >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_D:
                ((rgb.b >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_F:
                ((rgb.b >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_G:
                ((rgb.b >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_H:
                ((rgb.b >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_J:
                ((rgb.b >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_K:
                ((rgb.b >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;

            default:
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                break;

        } // switch i
    }
    return rgb_matrix_check_finished_leds(led_max);
}

// Solid color debug (HSV): allow figuring out ideal HSV without constantly
// reflashing the KB
static bool solid_color_debug_hsv(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_t rgb = hsv_to_rgb(rgb_matrix_config.hsv);
        switch (i) {
            case LED_F1:
                rgb_matrix_set_color(i, 255, 0, 0);
                break;
            case LED_F2:
                rgb_matrix_set_color(i, 127, 255, 0);
                break;
            case LED_F3:
                rgb_matrix_set_color(i, 0, 255, 255);
                break;
            case LED_F4:
                rgb_matrix_set_color(i, 127, 0, 255);
                break;

            case LED_F5:
                rgb_matrix_set_color(i, 255, 255, 255);
                break;
            case LED_F6:
                rgb_matrix_set_color(i, 170, 255, 170);
                break;
            case LED_F7:
                rgb_matrix_set_color(i, 84, 255, 84);
                break;
            case LED_F8:
                rgb_matrix_set_color(i, 0, 255, 0);
                break;

            case LED_F9:
                rgb_matrix_set_color(i, 0, 0, 0);
                break;
            case LED_F10:
                rgb_matrix_set_color(i, 84, 84, 84);
                break;
            case LED_F11:
                rgb_matrix_set_color(i, 170, 170, 170);
                break;
            case LED_F12:
                rgb_matrix_set_color(i, 255, 255, 255);
                break;

            case LED_1:
                ((rgb_matrix_config.hsv.h >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_2:
                ((rgb_matrix_config.hsv.h >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_3:
                ((rgb_matrix_config.hsv.h >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_4:
                ((rgb_matrix_config.hsv.h >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_5:
                ((rgb_matrix_config.hsv.h >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_6:
                ((rgb_matrix_config.hsv.h >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_7:
                ((rgb_matrix_config.hsv.h >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_8:
                ((rgb_matrix_config.hsv.h >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;

            case LED_Q:
                ((rgb_matrix_config.hsv.s >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_W:
                ((rgb_matrix_config.hsv.s >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_E:
                ((rgb_matrix_config.hsv.s >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_R:
                ((rgb_matrix_config.hsv.s >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_T:
                ((rgb_matrix_config.hsv.s >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_Y:
                ((rgb_matrix_config.hsv.s >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_U:
                ((rgb_matrix_config.hsv.s >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_I:
                ((rgb_matrix_config.hsv.s >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;

            case LED_A:
                ((rgb_matrix_config.hsv.v >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_S:
                ((rgb_matrix_config.hsv.v >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_D:
                ((rgb_matrix_config.hsv.v >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_F:
                ((rgb_matrix_config.hsv.v >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_G:
                ((rgb_matrix_config.hsv.v >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_H:
                ((rgb_matrix_config.hsv.v >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_J:
                ((rgb_matrix_config.hsv.v >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;
            case LED_K:
                ((rgb_matrix_config.hsv.v >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
                break;

            default:
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                break;

        } // switch i
    }
    return rgb_matrix_check_finished_leds(led_max);
}

// ---
// RGB led number layout, function of the key
//  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
//  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Del        71, led 13
//  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
//  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
//  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
//  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
//  87, led 07                                                                                                                                                                      88, led 18
//  91, led 08                                                                                                                                                                      92, led 19

#define LED_HUE_OFFSET(i) (i*32)

static uint8_t led_hue_offset(uint8_t led_id) {
    switch (led_id) {
        // Left LEDs
        case LED_L1:
            return LED_HUE_OFFSET(0);
        case LED_L2:
            return LED_HUE_OFFSET(1);
        case LED_L3:
            return LED_HUE_OFFSET(2);
        case LED_L4:
            return LED_HUE_OFFSET(3);
        case LED_L5:
            return LED_HUE_OFFSET(4);
        case LED_L6:
            return LED_HUE_OFFSET(5);
        case LED_L7:
            return LED_HUE_OFFSET(6);
        case LED_L8:
            return LED_HUE_OFFSET(7);

        // Right LEDs
        case LED_R1:
            return LED_HUE_OFFSET(0);
        case LED_R2:
            return LED_HUE_OFFSET(1);
        case LED_R3:
            return LED_HUE_OFFSET(2);
        case LED_R4:
            return LED_HUE_OFFSET(3);
        case LED_R5:
            return LED_HUE_OFFSET(4);
        case LED_R6:
            return LED_HUE_OFFSET(5);
        case LED_R7:
            return LED_HUE_OFFSET(6);
        case LED_R8:
            return LED_HUE_OFFSET(7);

        default:
            return 0;
    }
}

/*
rgb_matrix_config.speed will reflect ms / hue increase
rgb_matrix_config.speed = 255 -> 1 ms / hue increase
rgb_matrix_config.speed = 1 ->   255 ms / hue increase
rgb_matrix_config.speed = 0 ->   static
*/

static led_location_map left_leds_arr[8] = {LED_L1, LED_L2, LED_L3, LED_L4, LED_L5, LED_L6, LED_L7, LED_L8};
static led_location_map right_leds_arr[8] = {LED_R1, LED_R2, LED_R3, LED_R4, LED_R5, LED_R6, LED_R7, LED_R8};

static uint8_t hue_base = 0;
// static uint8_t hue_base_manual = 0;
// TODO - precompute all one-time period / speed / hue values?
static uint8_t speed_config;
static uint16_t timer_last_ms;
static uint16_t remainder_ms = 0;

static uint16_t ms_per_hue_config(uint8_t speed_config) {
    if (speed_config == 0) {
        return 0;
    }
    return 256 - speed_config;
}

static void update_hue_base(void) {
    uint16_t ms_per_hue = ms_per_hue_config(speed_config);
    if (ms_per_hue == 0) {
        return;
    }

    uint16_t timer_cur_ms = timer_read();
    uint16_t elapsed_ms = timer_cur_ms - timer_last_ms + remainder_ms;

    uint8_t hue_adjust = (elapsed_ms / ms_per_hue);
    remainder_ms = elapsed_ms % ms_per_hue;
    hue_base += hue_adjust;

    timer_last_ms = timer_cur_ms;
}

// Spectrum (dynamic) RGB side LEDs, static chosen RGB main keys
static bool spectrum_sides_rgb_main(effect_params_t* params) {
    if (params->init) {
        speed_config = rgb_matrix_config.speed;

        timer_last_ms = timer_read();
        for (uint8_t i = 0; i < 8; i++) {
            uint8_t led_hue_left = led_hue_offset(left_leds_arr[i]);
            uint8_t led_hue_right = led_hue_offset(right_leds_arr[i]);

            hsv_t spectrum_hsv_left = rgb_matrix_config.hsv;
            hsv_t spectrum_hsv_right = rgb_matrix_config.hsv;
            spectrum_hsv_left.h = led_hue_left;
            spectrum_hsv_right.h = led_hue_right;

            rgb_t spectrum_rgb_left = hsv_to_rgb(spectrum_hsv_left);
            rgb_t spectrum_rgb_right = hsv_to_rgb(spectrum_hsv_right);

            rgb_matrix_set_color(left_leds_arr[i], spectrum_rgb_left.r, spectrum_rgb_left.g, spectrum_rgb_left.b);
            rgb_matrix_set_color(right_leds_arr[i], spectrum_rgb_right.r, spectrum_rgb_right.g, spectrum_rgb_right.b);
        }
    }

    speed_config = rgb_matrix_config.speed;
    update_hue_base();

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    rgb_t default_rgb = hsv_to_rgb(rgb_matrix_config.hsv);

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
                uint8_t led_hue = hue_base + led_hue_offset(i);
                hsv_t spectrum_hsv = {led_hue, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};
                rgb_t spectrum_rgb = hsv_to_rgb(spectrum_hsv);
                rgb_matrix_set_color(i, spectrum_rgb.r, spectrum_rgb.g, spectrum_rgb.b);
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
                rgb_matrix_set_color(i, default_rgb.r, default_rgb.g, default_rgb.b);
                break;
            case LED_PRT:
                if IS_LAYER_ON(2) {
                    hsv_t default_hsv_inv = rgb_matrix_config.hsv;
                    default_hsv_inv.h -= 128;
                    rgb_t default_rgb_inv = hsv_to_rgb(default_hsv_inv);
                    rgb_matrix_set_color(i, default_rgb_inv.r, default_rgb_inv.g, default_rgb_inv.b);
                }
                break;

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
                rgb_matrix_set_color(i, default_rgb.r, default_rgb.g, default_rgb.b);
                break;
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

//// e.g: A more complex effect, relying on external methods and state, with
//// dedicated init and run methods
//static uint8_t some_global_state;
//static void my_cool_effect2_complex_init(effect_params_t* params) {
//  some_global_state = 1;
//}
//static bool my_cool_effect2_complex_run(effect_params_t* params) {
//  RGB_MATRIX_USE_LIMITS(led_min, led_max);
//  for (uint8_t i = led_min; i < led_max; i++) {
//    rgb_matrix_set_color(i, 0xff, some_global_state++, 0xff);
//  }
//  return rgb_matrix_check_finished_leds(led_max);
//}
//static bool my_cool_effect2(effect_params_t* params) {
//  if (params->init) my_cool_effect2_complex_init(params);
//  return my_cool_effect2_complex_run(params);
//}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

