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
qk_tap_dance_action_t tap_dance_actions[] = {
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
    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
