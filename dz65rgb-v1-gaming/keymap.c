#include QMK_KEYBOARD_H

enum dz65rgb_layers {
    _BL,  // base layer (qwerty)
    _GL,  // gaming layer (with a few keys blocked)
    _FL,  // function/control layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_65_ansi(
        KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT,  TG(_GL),  MO(_FL),  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
    [_GL] = LAYOUT_65_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_GRV,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  XXXXXXX,  XXXXXXX,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_FL] = LAYOUT_65_ansi(
        XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_PSCR,
        XXXXXXX,  RGB_TOG,  RGB_MOD,  RGB_RMOD, RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  RGB_SPI,  RGB_SPD,  XXXXXXX,  RESET,    XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            EEP_RST,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};

void rgb_matrix_min_sat_noeeprom(void) {
    rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), 0x00, rgb_matrix_get_val());
}

void rgb_matrix_mid_sat_noeeprom(void) {
    rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), 0x7F, rgb_matrix_get_val());
}

void rgb_matrix_max_sat_noeeprom(void) {
    rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), 0xFF, rgb_matrix_get_val());
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_min_sat_noeeprom();
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _GL:
        rgb_matrix_max_sat_noeeprom();
        break;
    case _FL:
        rgb_matrix_mid_sat_noeeprom();
        break;
    default: //  for any other layers, or the default layer
        rgb_matrix_min_sat_noeeprom();
        break;
    }

    return state;
}
