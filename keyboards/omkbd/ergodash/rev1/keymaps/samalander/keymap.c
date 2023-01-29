#include QMK_KEYBOARD_H


enum layer_names {
    _BASE = 0,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    _GAMING
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
    TD_PRN,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for left bracket, twice for right bracket
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    // Tap once for left parenthesis, twice for right parenthesis
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     XXXXXXX,                        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CW_TOGG,
    KC_EQL,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     XXXXXXX,                        XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
    TD(TD_BRC),HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_G,     XXXXXXX,                        XXXXXXX, KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,   KC_QUOT,
    TD(TD_PRN),KC_Z,    HRM_X,   KC_C,    KC_D,    KC_V,     XXXXXXX,                        XXXXXXX, KC_K,    KC_H,    KC_COMM, HRM_DT,  KC_SLSH, KC_BSLS,
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,          LS_MEDIA, LS_MOUSE, LS_NAV,       LS_NUM, LS_SYM,  LS_FUN,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, _______,      KC_BSPC, KC_ENT,  KC_DEL,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, _______, XXXXXXX,      KC_BTN1, KC_BTN2, KC_BTN3,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_MEDIA] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX,      KC_MPLY, KC_MSTP, KC_MUTE,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_NUM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX,                        XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_DOT,  KC_MINS, KC_0,         _______, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_RPRN, KC_RCBR, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX,                        XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_LPRN, KC_UNDS, KC_RPRN,      XXXXXXX, _______, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FUN] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SYRQ, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, XXXXXXX,                        XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_APP,  KC_TAB,  KC_SPC,       XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_GAMING] = LAYOUT(
    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_F1,                        KC_F4,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     KC_F2,                        KC_F5,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
    KC_LSFT,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,     KC_F3,                        KC_F6,   KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,     KC_ENT,                       KC_UP,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL,   KC_LCTL, KC_LALT, KC_LALT,          KC_ESC,   KC_ENT, KC_SPC,     KC_LEFT,  KC_DOWN, KC_RGHT,          KC_BSPC, KC_RALT, KC_RCTL, KC_RCTL
  ),

};

// Light LEDs 11 and 12 white when caps lock or caps word is active.
const rgblight_segment_t PROGMEM capslock_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_WHITE}
);
// Light LEDs 0 to 10 and 13 to 23 in blue when keyboard layer 1 is active
const rgblight_segment_t PROGMEM nav_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_BLUE},
    {13, 11, HSV_BLUE}
);
// Light LEDs 0 to 10 and 13 to 23 in green when keyboard layer 2 is active
const rgblight_segment_t PROGMEM mouse_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_GREEN},
    {13, 11, HSV_GREEN}
);
// Light LEDs 0 to 10 and 13 to 23 in cyan when keyboard layer 3 is active
const rgblight_segment_t PROGMEM media_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_CYAN},
    {13, 11, HSV_CYAN}
);
// Light LEDs 0 to 10 and 13 to 23 in red when keyboard layer 4 is active
const rgblight_segment_t PROGMEM num_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_RED},
    {13, 11, HSV_RED}
);
// Light LEDs 0 to 10 and 13 to 23 in yellow when keyboard layer 5 is active
const rgblight_segment_t PROGMEM sym_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_YELLOW},
    {13, 11, HSV_YELLOW}
);
// Light LEDs 0 to 10 and 13 to 23 in orange when keyboard layer 6 is active
const rgblight_segment_t PROGMEM fun_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_ORANGE},
    {13, 11, HSV_ORANGE}
);
// Light LEDs 0 to 10 and 13 to 23 in purple when keyboard layer 7 is active
const rgblight_segment_t PROGMEM gaming_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_PURPLE},
    {13, 11, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_colors,
    nav_colors,    // Overrides other layers
    mouse_colors,    // Overrides other layers
    media_colors,    // Overrides other layers
    num_colors,    // Overrides other layers
    sym_colors,    // Overrides other layers
    fun_colors,    // Overrides other layers
    gaming_colors    // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock || is_caps_word_on());
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MEDIA));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FUN));
    rgblight_set_layer_state(7, layer_state_cmp(state, _GAMING));
    return state;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(0, active || host_keyboard_led_state().caps_lock);
}

enum combo_events {
  CMB_TO_GAMING,
  CMB_TO_BASE
};
const uint16_t PROGMEM to_gaming_combo[] = {KC_5, KC_V, KC_6, KC_K, COMBO_END};
const uint16_t PROGMEM to_base_combo[] = {KC_GRV, KC_LCTL, KC_EQL, KC_RCTL, COMBO_END};

combo_t key_combos[] = {
  [CMB_TO_GAMING] = COMBO_ACTION(to_gaming_combo),
  [CMB_TO_BASE] = COMBO_ACTION(to_base_combo)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_TO_GAMING:
      if (pressed) {
        layer_move(_GAMING);
      }
      break;
    case CMB_TO_BASE:
      if (pressed) {
        layer_clear();
      }
      break;
  }
}
