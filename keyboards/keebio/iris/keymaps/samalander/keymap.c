#include QMK_KEYBOARD_H


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
  [_BASE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CW_TOGG,
    KC_EQL,  KC_Q,    HRM_W,   KC_F,    KC_P,    KC_B,                                             KC_J,    KC_L,    KC_U,    HRM_Y,   KC_SCLN, KC_MINS,
    KC_LBRC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LPRN, HRM_Z,   HRM_X,   HRM_C,   HRM_D,   KC_V,    LS_MEDIA,                        LS_FUN, KC_K,    HRM_H,   HRM_COMM,HRM_DOT, HRM_SLSH,KC_BSLS,
                                                 LS_MEDIA,LS_MOUSE,LS_NAV,        LS_NUM,  LS_SYM, LS_FUN
  ),

  [_NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                                          KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, CW_TOGG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                         KC_DEL, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
                                                 XXXXXXX, XXXXXXX, _______,       KC_BSPC, KC_ENT, KC_DEL
  ),

  [_MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                                          KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                        MS_BTN3, XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
                                                 XXXXXXX, _______, XXXXXXX,      MS_BTN1, MS_BTN2, MS_BTN3
  ),

  [_MEDIA] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                                          RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, _______,                        KC_MUTE, XXXXXXX, DT_PRNT, DT_DOWN, DT_UP,   XXXXXXX, XXXXXXX,
                                                 _______, XXXXXXX, XXXXXXX,      KC_MPLY, KC_MSTP, KC_MUTE
  ),

  [_NUM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                                          XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, QK_BOOT, XXXXXXX,
    KC_RBRC, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_RPRN, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_DOT,                         XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
                                                 KC_DOT,  KC_MINS, KC_0,         _______, XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_RPRN, KC_RCBR,                                          XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_LPRN,                        XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
                                                 KC_LPRN, KC_UNDS, KC_RPRN,      XXXXXXX, _______, XXXXXXX
  ),

  [_FUN] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SYRQ,                                          XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_APP,                         _______, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
                                                 KC_APP,  KC_TAB, KC_SPC,        XXXXXXX, XXXXXXX, _______
  ),
};
