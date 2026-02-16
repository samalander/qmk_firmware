/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#ifdef RGBLIGHT_TIMEOUT
    static uint16_t idle_timer = 0;
    static uint8_t halfmin_counter = 0;
    static bool rgblight_on = true;
#endif

enum layer_names {
    _BASE = 0,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN
};

// Home-row Modifiers Left
#define HRM_Z MT(MOD_LGUI, KC_Z)
#define HRM_X MT(MOD_LALT, KC_X)
#define HRM_C MT(MOD_LCTL, KC_C)
#define HRM_D MT(MOD_LSFT, KC_D)
#define HRM_W MT(MOD_RALT, KC_W)
// Home-row Modifiers Right
#define HRM_H MT(MOD_RSFT, KC_H)
#define HRM_COMM MT(MOD_RCTL, KC_COMM)
#define HRM_DOT MT(MOD_LALT, KC_DOT)
#define HRM_SLSH MT(MOD_RGUI, KC_SLSH)
#define HRM_Y MT(MOD_RALT, KC_Y)

// Layer switching
#define LS_NAV LT(_NAV, KC_SPC)
#define LS_MOUSE LT(_MOUSE, KC_TAB)
#define LS_MEDIA LT(_MEDIA, KC_ESC)
#define LS_NUM LT(_NUM, KC_BSPC)
#define LS_SYM LT(_SYM, KC_ENT)
#define LS_FUN LT(_FUN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_EQL,    KC_Q,    HRM_W,   KC_F,    KC_P,     KC_B,                        KC_J,    KC_L,    KC_U,    HRM_Y,   KC_SCLN, KC_MINS,
    KC_LBRC,   KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LPRN,   HRM_Z,   HRM_X,   HRM_C,   HRM_D,    KC_V,                        KC_K,    HRM_H,   HRM_COMM,HRM_DOT, HRM_SLSH,KC_BSLS,
                                          LS_MEDIA, LS_MOUSE, LS_NAV,    LS_NUM, LS_SYM,  LS_FUN
  ),

  [_NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, QK_BOOT, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, CW_TOGG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
                                        XXXXXXX, XXXXXXX, _______,      KC_BSPC, KC_ENT,  KC_DEL
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
    XXXXXXX, QK_BOOT, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,      MS_BTN1, MS_BTN2, MS_BTN3
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
    XXXXXXX, QK_BOOT, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                        RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        XXXXXXX, RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD,
                                        _______, XXXXXXX, XXXXXXX,      KC_MPLY, KC_MSTP, KC_MUTE
  ),

  [_NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, QK_BOOT, XXXXXXX,
    KC_RBRC, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_RPRN, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
                                        KC_DOT,  KC_MINS, KC_0,         _______, XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
                                        KC_LPRN, KC_UNDS, KC_RPRN,      XXXXXXX, _______, XXXXXXX
  ),

  [_FUN] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SYRQ,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, QK_BOOT, DT_UP,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, DT_DOWN,
                                        KC_APP,  KC_TAB, KC_SPC,        XXXXXXX, XXXXXXX, _______
  )

};

#ifdef OLED_ENABLE

static void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _FUN:
            oled_write_ln_P(PSTR("Functions"), false);
            break;
    }
}

char     key_name;
uint16_t last_keycode;
uint8_t  last_row;
uint8_t  last_col;

static const char PROGMEM code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

static const char *depad_str(const char *depad_str, char depad_char) {
    while (*depad_str == depad_char)
        ++depad_str;
    return depad_str;
}

static void oled_render_keylog(void) {
    oled_write_char('0' + last_row, false);
    oled_write_P(PSTR("x"), false);
    oled_write_char('0' + last_col, false);
    oled_write_P(PSTR(", k"), false);
    const char *last_keycode_str = get_u16_str(last_keycode, ' ');
    oled_write(depad_str(last_keycode_str, ' '), false);
    oled_write_P(PSTR(":"), false);
    oled_write_char(key_name, false);
    oled_advance_page(true);
}

// static void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }

__attribute__((weak)) void oled_render_logo(void) {
    // clang-format off
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    // clang-format on
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

#ifdef RGBLIGHT_TIMEOUT
void matrix_scan_user(void) {
    // idle_timer needs to be set one time
    if (idle_timer == 0) idle_timer = timer_read();

    if (rgblight_on && timer_elapsed(idle_timer) > 30000) {
        halfmin_counter++;
        idle_timer = timer_read();
    }

    if (rgblight_on && halfmin_counter >= RGBLIGHT_TIMEOUT * 2) {
        rgblight_disable_noeeprom();
        rgblight_on = false;
        halfmin_counter = 0;
    }
}
#endif // RGBLIGHT_TIMEOUT
