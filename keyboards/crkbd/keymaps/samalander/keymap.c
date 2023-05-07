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
#include <stdio.h>

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
#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_R MT(MOD_LALT, KC_R)
#define HRM_S MT(MOD_LCTL, KC_S)
#define HRM_T MT(MOD_LSFT, KC_T)
#define HRM_X MT(MOD_RALT, KC_X)
// Home-row Modifiers Right
#define HRM_N MT(MOD_RSFT, KC_N)
#define HRM_E MT(MOD_RCTL, KC_E)
#define HRM_I MT(MOD_LALT, KC_I)
#define HRM_O MT(MOD_RGUI, KC_O)
#define HRM_DT MT(MOD_RALT, KC_DOT)

// Layer switching
#define LS_NAV LT(_NAV, KC_SPC)
#define LS_MOUSE LT(_MOUSE, KC_TAB)
#define LS_MEDIA LT(_MEDIA, KC_ESC)
#define LS_NUM LT(_NUM, KC_BSPC)
#define LS_SYM LT(_SYM, KC_ENT)
#define LS_FUN LT(_FUN, KC_DEL)

// Tap Dance declarations
enum {
    TD_BRC = 0,
    TD_QG,
    TD_PRN,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for left bracket, twice for right bracket
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    // Tap once for single quote, twice for backtick
    [TD_QG] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRV),
    // Tap once for left parenthesis, twice for right parenthesis
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_EQL,    KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
    TD(TD_BRC),HRM_A,   HRM_R,   HRM_S,   HRM_T,    KC_G,                        KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,   TD(TD_QG),
    TD(TD_PRN),KC_Z,    HRM_X,   KC_C,    KC_D,     KC_V,                        KC_K,    KC_H,    KC_COMM, HRM_DT,  KC_SLSH, KC_BSLS,
                                          LS_MEDIA, LS_MOUSE, LS_NAV,    LS_NUM, LS_SYM,  LS_FUN
  ),

  [_NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
                                        XXXXXXX, XXXXXXX, _______,      KC_BSPC, KC_ENT,  KC_DEL
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,      KC_BTN1, KC_BTN2, KC_BTN3
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, DT_PRNT, DT_DOWN, DT_UP,   XXXXXXX, XXXXXXX,
                                        _______, XXXXXXX, XXXXXXX,      KC_MPLY, KC_MSTP, KC_MUTE
  ),

  [_NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                         XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
                                        KC_DOT,  KC_MINS, KC_0,         _______, XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
                                        KC_LPRN, KC_UNDS, KC_RPRN,      XXXXXXX, _______, XXXXXXX
  ),

  [_FUN] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SYRQ,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
                                        KC_APP,  KC_TAB, KC_SPC,        XXXXXXX, XXXXXXX, _______
  )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_T:
        case HRM_N:
            if (g_tapping_term > 20) {
                return g_tapping_term - 20;
            }
            return 0;
        default:
            return g_tapping_term;
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
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


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef OLED_ENABLE
        set_keylog(keycode, record);
    #endif // OLED_ENABLE
    #ifdef RGBLIGHT_TIMEOUT
        if (rgblight_on == false) {
            rgblight_enable_noeeprom();
            rgblight_on = true;
        }
        idle_timer = timer_read();
        halfmin_counter = 0;
    #endif // RGBLIGHT_TIMEOUT
  }
  return true;
}

#ifdef RGBLIGHT_TIMEOUT
void matrix_scan_user(void) {
    // idle_timer needs to be set one time
    if (idle_timer == 0) idle_timer = timer_read();

    if ( rgblight_on && timer_elapsed(idle_timer) > 30000) {
        halfmin_counter++;
        idle_timer = timer_read();
    }

    if ( rgblight_on && halfmin_counter >= RGBLIGHT_TIMEOUT * 2) {
        rgblight_disable_noeeprom();
        rgblight_on = false;
        halfmin_counter = 0;
    }
}
#endif // RGBLIGHT_TIMEOUT
