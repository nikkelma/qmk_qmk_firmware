// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(solid_color_debug_rgb)
RGB_MATRIX_EFFECT(solid_color_debug_hsv)
RGB_MATRIX_EFFECT(gmk_pulse_a)
RGB_MATRIX_EFFECT(gmk_gateway_a)

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

typedef enum NikkelmaKeyGroup {
  UNKNOWN = 0,
  DEFAULT,
  F1_F4,
  F5_F8,
  F9_F12,
  COLOR_1,
  COLOR_2,
  COLOR_3,
} NikkelmaKeyGroup;

// static NikkelmaKeyGroup pin_to_key_group(uint8_t pin) {
//   switch (pin) {
//     case 6:
// 	case 12:
// 	case 18:
// 	case 23:
//       return F1_F4;
// 
//     case 28:
//     case 34:
//     case 39:
//     case 44:
//       return F5_F8;
// 
//     case 50:
//     case 56:
//     case 61:
//     case 66:
//       return F9_F12;
// 
//     case 7:
//     case 13:
//     case 19:
//     case 24:
//     case 29:
//     case 35:
//     case 40:
//     case 45:
//       return COLOR_1;
// 
//     case 8:
//     case 14:
//     case 20:
//     case 25:
//     case 30:
//     case 36:
//     case 41:
//     case 46:
//       return COLOR_2;
// 
//     case 9:
//     case 15:
//     case 21:
//     case 26:
//     case 31:
//     case 37:
//     case 42:
//     case 47:
//       return COLOR_3;
// 
//     default:
//       return DEFAULT;
// 
//   }
// }

// Solid color debug (RGB): allow figuring out ideal RGB without constantly
// reflashing the KB
static bool solid_color_debug_rgb(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_t rgb = hsv_to_rgb(rgb_matrix_config.hsv);
	switch (i) {
	  // KeyGroup F1_F4
	  case 6:
		rgb_matrix_set_color(i, 0, 0, 0);
		break;
      case 12:
		rgb_matrix_set_color(i, 85, 0, 0);
		break;
      case 18:
		rgb_matrix_set_color(i, 170, 0, 0);
		break;
      case 23:
		rgb_matrix_set_color(i, 255, 0, 0);
		break;

      // KeyGroup F5_F8
	  case 28:
		rgb_matrix_set_color(i, 0, 0, 0);
		break;
      case 34:
		rgb_matrix_set_color(i, 0, 85, 0);
		break;
      case 39:
		rgb_matrix_set_color(i, 0, 171, 0);
		break;
      case 44:
		rgb_matrix_set_color(i, 0, 255, 0);
		break;

  	  // KeyGroup F9_F12
      case 50:
		rgb_matrix_set_color(i, 0, 0, 0);
		break;
      case 56:
		rgb_matrix_set_color(i, 0, 0, 85);
		break;
      case 61:
		rgb_matrix_set_color(i, 0, 0, 171);
		break;
      case 66:
		rgb_matrix_set_color(i, 0, 0, 255);
		break;

  	  // KeyGroup COLOR_1
      case 7:
		((rgb.r >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 13:
		((rgb.r >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 19:
		((rgb.r >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 24:
		((rgb.r >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 29:
		((rgb.r >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 35:
		((rgb.r >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 40:
		((rgb.r >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 45:
		((rgb.r >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;

  	  // KeyGroup COLOR_2
      case 8:
		((rgb.g >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 14:
		((rgb.g >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 20:
		((rgb.g >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 25:
		((rgb.g >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 30:
		((rgb.g >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 36:
		((rgb.g >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 41:
		((rgb.g >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 46:
		((rgb.g >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;

  	  // KeyGroup COLOR_3
      case 9:
		((rgb.b >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 15:
		((rgb.b >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 21:
		((rgb.b >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 26:
		((rgb.b >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 31:
		((rgb.b >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 37:
		((rgb.b >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 42:
		((rgb.b >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 47:
		((rgb.b >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;

      default:
		rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
		break;

	} // switch i
  }
  return rgb_matrix_check_finished_leds(led_max);
}

// Solid color debug (RGB): allow figuring out ideal HSV without constantly
// reflashing the KB
static bool solid_color_debug_hsv(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_t rgb = hsv_to_rgb(rgb_matrix_config.hsv);
	switch (i) {
	  // KeyGroup F1_F4
	  case 6:
		rgb_matrix_set_color(i, 255, 0, 0);
		break;
      case 12:
		rgb_matrix_set_color(i, 127, 255, 0);
		break;
      case 18:
		rgb_matrix_set_color(i, 0, 255, 255);
		break;
      case 23:
		rgb_matrix_set_color(i, 127, 0, 255);
		break;

      // KeyGroup F5_F8
	  case 28:
		rgb_matrix_set_color(i, 255, 255, 255);
		break;
      case 34:
		rgb_matrix_set_color(i, 170, 255, 170);
		break;
      case 39:
		rgb_matrix_set_color(i, 84, 255, 84);
		break;
      case 44:
		rgb_matrix_set_color(i, 0, 255, 0);
		break;

  	  // KeyGroup F9_F12
      case 50:
		rgb_matrix_set_color(i, 0, 0, 0);
		break;
      case 56:
		rgb_matrix_set_color(i, 84, 84, 84);
		break;
      case 61:
		rgb_matrix_set_color(i, 170, 170, 170);
		break;
      case 66:
		rgb_matrix_set_color(i, 255, 255, 255);
		break;

  	  // KeyGroup COLOR_1
      case 7:
		((rgb_matrix_config.hsv.h >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 13:
		((rgb_matrix_config.hsv.h >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 19:
		((rgb_matrix_config.hsv.h >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 24:
		((rgb_matrix_config.hsv.h >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 29:
		((rgb_matrix_config.hsv.h >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 35:
		((rgb_matrix_config.hsv.h >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 40:
		((rgb_matrix_config.hsv.h >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 45:
		((rgb_matrix_config.hsv.h >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;

  	  // KeyGroup COLOR_2
      case 8:
		((rgb_matrix_config.hsv.s >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 14:
		((rgb_matrix_config.hsv.s >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 20:
		((rgb_matrix_config.hsv.s >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 25:
		((rgb_matrix_config.hsv.s >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 30:
		((rgb_matrix_config.hsv.s >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 36:
		((rgb_matrix_config.hsv.s >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 41:
		((rgb_matrix_config.hsv.s >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 46:
		((rgb_matrix_config.hsv.s >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;

  	  // KeyGroup COLOR_3
      case 9:
		((rgb_matrix_config.hsv.v >> 7) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 15:
		((rgb_matrix_config.hsv.v >> 6) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 21:
		((rgb_matrix_config.hsv.v >> 5) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 26:
		((rgb_matrix_config.hsv.v >> 4) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 31:
		((rgb_matrix_config.hsv.v >> 3) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 37:
		((rgb_matrix_config.hsv.v >> 2) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 42:
		((rgb_matrix_config.hsv.v >> 1) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;
      case 47:
		((rgb_matrix_config.hsv.v >> 0) & 1) ? rgb_matrix_set_color(i, RGB_GREEN) : rgb_matrix_set_color(i, RGB_RED);
		break;

      default:
		rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
		break;

	} // switch i
  }
  return rgb_matrix_check_finished_leds(led_max);
}


// GMK pulse A: static color for GMK pulse keycaps
static bool gmk_pulse_a(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_PULSE_BLUE(i);
    // rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  }
  return rgb_matrix_check_finished_leds(led_max);
}

// GMK Gateway A: static colors for GMK gateway keycaps
// ---
// RGB led number layout, function of the key
//  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
//  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Home       71, led 13
//  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
//  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
//  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
//  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
//  87, led 07                                                                                                                                                                      88, led 18
//  91, led 08                                                                                                                                                                      92, led 19

static bool gmk_gateway_a(effect_params_t* params) {
  	RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // Left side
    RGB_GATEWAY_ORANGE(67); // Left LED 01
    RGB_GATEWAY_ORANGE(70); // Left LED 02
    RGB_GATEWAY_ORANGE(73); // Left LED 03
    RGB_GATEWAY_ORANGE(76); // Left LED 04
    RGB_GATEWAY_ORANGE(80); // Left LED 05
    RGB_GATEWAY_ORANGE(83); // Left LED 06
    RGB_GATEWAY_ORANGE(87); // Left LED 07
    RGB_GATEWAY_ORANGE(91); // Left LED 08

    // Right side
    RGB_GATEWAY_BLUE(68); // Right LED 12
    RGB_GATEWAY_BLUE(71); // Right LED 13
    RGB_GATEWAY_BLUE(74); // Right LED 14
    RGB_GATEWAY_BLUE(77); // Right LED 15
    RGB_GATEWAY_BLUE(81); // Right LED 16
    RGB_GATEWAY_BLUE(84); // Right LED 17
    RGB_GATEWAY_BLUE(88); // Right LED 18
    RGB_GATEWAY_BLUE(92); // Right LED 19

    // TOP Line keys
    RGB_GATEWAY_ORANGE(0); // ESC
    RGB_GATEWAY_ORANGE(6); // F1
    RGB_GATEWAY_ORANGE(12); // F2
    RGB_GATEWAY_ORANGE(18); // F3
    RGB_GATEWAY_ORANGE(23); // F4
    RGB_GATEWAY_BLUE(28); // F5
    RGB_GATEWAY_BLUE(34); // F6
    RGB_GATEWAY_BLUE(39); // F7
    RGB_GATEWAY_BLUE(44); // F8
	RGB_GATEWAY_BLUE(50); // F9
	RGB_GATEWAY_BLUE(56); // F10
	RGB_GATEWAY_BLUE(61); // F11
	RGB_GATEWAY_BLUE(66); // F12
	RGB_GATEWAY_BLUE(69); // Prt

	// Right Keys
	RGB_GATEWAY_BLUE(72); // Home
	RGB_GATEWAY_BLUE(75); // PgUp
	RGB_GATEWAY_BLUE(86); // PgDown
	RGB_GATEWAY_BLUE(82); // End

	// Arrows
	RGB_GATEWAY_BLUE(94); // Up
	RGB_GATEWAY_BLUE(95); // Left
	RGB_GATEWAY_BLUE(97); // Down
	RGB_GATEWAY_BLUE(79); // Right

	// Numbers line
	RGB_GATEWAY_ORANGE(1); // ~
	RGB_GATEWAY_ORANGE(7); // 1
	RGB_GATEWAY_ORANGE(13); // 2
	RGB_GATEWAY_ORANGE(19); // 3
	RGB_GATEWAY_ORANGE(24); // 4
	RGB_GATEWAY_ORANGE(29); // 5
	RGB_GATEWAY_BLUE(35); // 6
	RGB_GATEWAY_BLUE(40); // 7
	RGB_GATEWAY_BLUE(45); // 8
	RGB_GATEWAY_BLUE(51); // 9
	RGB_GATEWAY_BLUE(57); // 0
	RGB_GATEWAY_BLUE(62); // -_
	RGB_GATEWAY_BLUE(78); // =+
	RGB_GATEWAY_BLUE(85); // BackSpc

	// First Letters line
	RGB_GATEWAY_ORANGE(2); // Tab
	RGB_GATEWAY_ORANGE(8); // Q
	RGB_GATEWAY_ORANGE(14); // W
	RGB_GATEWAY_ORANGE(20); // E
	RGB_GATEWAY_ORANGE(25); // R
	RGB_GATEWAY_ORANGE(30); // T
	RGB_GATEWAY_BLUE(36); // Y
	RGB_GATEWAY_BLUE(41); // U
	RGB_GATEWAY_BLUE(46); // I
	RGB_GATEWAY_BLUE(52); // O
	RGB_GATEWAY_BLUE(58); // P
	RGB_GATEWAY_BLUE(63); // [{
	RGB_GATEWAY_BLUE(89); // ]}
	RGB_GATEWAY_BLUE(93); // \|

	// Second Letters line
	RGB_GATEWAY_ORANGE(3); // Caps
	RGB_GATEWAY_ORANGE(9); // A
	RGB_GATEWAY_ORANGE(15); // S
	RGB_GATEWAY_ORANGE(21); // D
	RGB_GATEWAY_ORANGE(26); // F
	RGB_GATEWAY_ORANGE(31); // G
	RGB_GATEWAY_BLUE(37); // H
	RGB_GATEWAY_BLUE(42); // J
	RGB_GATEWAY_BLUE(47); // K
	RGB_GATEWAY_BLUE(53); // L
	RGB_GATEWAY_BLUE(59); // ;:
	RGB_GATEWAY_BLUE(64); // '"
	RGB_GATEWAY_BLUE(96); // Enter

	// Third Letters line
	RGB_GATEWAY_ORANGE(4); // L_Shift
	RGB_GATEWAY_ORANGE(10); // Z
	RGB_GATEWAY_ORANGE(16); // X
	RGB_GATEWAY_ORANGE(22); // C
	RGB_GATEWAY_ORANGE(27); // V
	RGB_GATEWAY_ORANGE(32); // B
	RGB_GATEWAY_BLUE(38); // N
	RGB_GATEWAY_BLUE(43); // M
	RGB_GATEWAY_BLUE(48); // ,<
	RGB_GATEWAY_BLUE(54); // .<
	RGB_GATEWAY_BLUE(60); // .<
	RGB_GATEWAY_BLUE(90); // Sh_R

	// Last line
	RGB_GATEWAY_ORANGE(5); // Ct_L
	RGB_GATEWAY_ORANGE(11); // Win_L
	RGB_GATEWAY_ORANGE(17); // Alt_L
	RGB_GATEWAY_WHITE(33); // Space
	RGB_GATEWAY_BLUE(49); // Alt_R
	RGB_GATEWAY_BLUE(55); // Fn
	RGB_GATEWAY_BLUE(65); // Ct_R

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
