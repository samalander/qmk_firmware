#include QMK_KEYBOARD_H


#define _COLEMAKDH 0
#define _NAV 1
#define _NUMBERS 2

// Tap Dance declarations
enum {
    TD_01PRN,
    TD_02BRC,
    TD_03BSG,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Left Parentheses, twice for Right Parentheses
    [TD_01PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    // Tap once for Left Bracket, twice for Right Bracket
    [TD_02BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    // Tap once for Backslash, twice for Grave
    [TD_03BSG] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_GRV),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAKDH] = LAYOUT(
  //┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐                           ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
     KC_ESC,      KC_1,        KC_2,        KC_3,        KC_4,        KC_5,                                    KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_EQL,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤                           ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_TAB,      KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,                                    KC_J,        KC_L,        KC_U,        KC_Y,        KC_SCLN,     KC_MINS,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤                           ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_BSPC,     LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),KC_G,                                    KC_M,        LSFT_T(KC_N),LCTL_T(KC_E),LALT_T(KC_I),LGUI_T(KC_O),KC_QUOT,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┼────────────┐ ┌────────────┼────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_LSPO,     KC_Z,        KC_X,        KC_C,        KC_D,        KC_V,        KC_DEL,        TD(TD_03BSG),KC_K,        KC_H,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_RSPC,
  //└────────────┴────────────┴────────────┴────┬───────┴────┬───────┴────┬───────┴────┬───────┘ └───────┬────┴───────┬────┴───────┬────┴───────┬────┴────────────┴────────────┴────────────┘
                                                 TD(TD_02BRC),TT(1),       KC_SPC,                        KC_ENT,      TT(2),       TD(TD_01PRN)
                                             // └────────────┴────────────┴────────────┘                 └────────────┴────────────┴────────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐                           ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
     RGB_TOG,     RGB_MOD,     RGB_VAI,     RGB_HUI,     RGB_SAI,     RGB_SPI,                                 DM_REC1,     DM_PLY1,     DM_PLY2,     DM_REC2,     DM_RSTP,     RESET,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤                           ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_NO,       RGB_RMOD,    RGB_VAD,     RGB_HUD,     RGB_SAD,     RGB_SPD,                                 KC_NO,       KC_HOME,     KC_PGDN,     KC_PGUP,     KC_END,      KC_NO,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤                           ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_PSCR,     KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     KC_CAPS,                                 KC_VOLU,     KC_LEFT,     KC_DOWN,     KC_UP,       KC_RGHT,     KC_NO,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┼────────────┐ ┌────────────┼────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_NO,       KC_NO,       KC_NO,       KC_MEH,      KC_HYPR,     KC_NO,       KC_NO,         DT_UP,       KC_VOLD,     KC_MRWD,     KC_MUTE,     KC_MPLY,     KC_MFFD,     KC_NO,
  //└────────────┴────────────┴────────────┴────┬───────┴────┬───────┴────┬───────┴────┬───────┘ └───────┬────┴───────┬────┴───────┬────┴───────┬────┴────────────┴────────────┴────────────┘
                                                 KC_NO,       KC_TRNS,     KC_NO,                         DT_DOWN,     DT_PRNT,     KC_NO
                                             // └────────────┴────────────┴────────────┘                 └────────────┴────────────┴────────────┘
  ),

  [_NUMBERS] = LAYOUT(
  //┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐                           ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
     KC_NO,       KC_NO,       KC_NO,       KC_LBRC,     KC_RBRC,     KC_NO,                                   KC_NO,       KC_LCBR,     KC_RCBR,     KC_BSLS,     KC_PIPE,     KC_NO,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤                           ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_TILD,     KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,                                 KC_CIRC,     KC_AMPR,     KC_ASTR,     KC_LPRN,     KC_RPRN,     KC_PLUS,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤                           ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_GRV,      LGUI_T(KC_1),LALT_T(KC_2),LCTL_T(KC_3),LSFT_T(KC_4),KC_5,                                    KC_6,        LSFT_T(KC_7),LCTL_T(KC_8),LALT_T(KC_9),LGUI_T(KC_0),KC_EQL,
  //├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┼────────────┐ ┌────────────┼────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
     KC_F12,      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_NO,         KC_NO,       KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,
  //└────────────┴────────────┴────────────┴────┬───────┴────┬───────┴────┬───────┴────┬───────┘ └───────┬────┴───────┬────┴───────┬────┴───────┬────┴────────────┴────────────┴────────────┘
                                                 KC_NO,       KC_NO,       KC_NO,                         KC_NO,       KC_TRNS,     KC_NO
                                             // └────────────┴────────────┴────────────┘                 └────────────┴────────────┴────────────┘
  )
};
