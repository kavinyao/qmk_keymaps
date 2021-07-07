#include QMK_KEYBOARD_H

enum dz60_layers {
    _GL,  // gaming layer (qwerty with a few keys blocked)
    _BL,  // base layer (qwerty)
    _WL,  // work/coding layer (with layer tap on space)
    _FL,  // function layer
    _CL,  // control layer
};


// make long keycode macro shorter
#define MY_CAPS  LCTL_T(KC_GRV)
#define MY_SPC   LT(_FL, KC_SPC)

#define MY_UP    RSFT_T(KC_UP)
#define MY_DOWN  LT(_CL, KC_DOWN)
#define MY_RGHT  RCTL_T(KC_RGHT)
#define MY_LEFT  RGUI_T(KC_LEFT)

#define MY_DEFAULT_RGB_MODE  RGBLIGHT_MODE_BREATHING
#define MY_WORK_RGB_MODE     RGBLIGHT_MODE_TWINKLE
#define MY_GAMING_RGB_MODE   RGBLIGHT_MODE_RAINBOW_SWIRL


// NOTE: Using KC_TRANS on layers to be used as the default layer is safe
// because QMK always falls back to layer 0 if no keycode is found.
// Reference: https://www.reddit.com/r/olkb/comments/h95jk8/help_how_does_df_works_in_qmk/fux4bu4
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_GL] = LAYOUT_60_ansi_split_bs_rshift(
        KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
        KC_GRV,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  MY_UP,    DF(_BL),
        KC_LCTL,  XXXXXXX,  XXXXXXX,                                KC_SPC,                                 KC_RALT,  MY_LEFT,  MY_DOWN,  MY_RGHT
    ),
    [_BL] = LAYOUT_60_ansi_split_bs_rshift(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DF(_WL),
        _______,  KC_LGUI,  KC_LALT,                                _______,                                _______,  _______,  _______,  _______
    ),
    [_WL] = LAYOUT_60_ansi_split_bs_rshift(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MY_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DF(_GL),
        _______,  _______,  _______,                                MY_SPC,                                 _______,  _______,  _______,  _______
    ),
    [_FL] = LAYOUT_60_ansi_split_bs_rshift(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BSLS,
        KC_CAPS,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  XXXXXXX,  XXXXXXX,                                _______,                                _______,  _______,  _______,  _______
    ),
    [_CL] = LAYOUT_60_ansi_split_bs_rshift(
        XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  KC_PSCR,
        XXXXXXX,  RGB_TOG,  RGB_MOD,  RGB_RMOD, RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  RGB_SPI,  RGB_SPD,  XXXXXXX,  RESET,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            EEP_RST,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};


void rgblight_set_max_sat_noeeprom(void) {
    rgblight_sethsv_noeeprom(rgblight_get_hue(), 0xFF, rgblight_get_val());
}

void rgblight_set_min_sat_noeeprom(void) {
    rgblight_sethsv_noeeprom(rgblight_get_hue(), 0x00, rgblight_get_val());
}

void set_default_lighting(void) {
    rgblight_mode_noeeprom(MY_DEFAULT_RGB_MODE);
    rgblight_set_min_sat_noeeprom();
}

void set_work_lighting(void) {
    rgblight_mode_noeeprom(MY_WORK_RGB_MODE);
    rgblight_set_min_sat_noeeprom();
}

void set_gaming_lighting(void) {
    rgblight_mode_noeeprom(MY_GAMING_RGB_MODE);
    rgblight_set_max_sat_noeeprom();
}


// NOTE: Using keyboard_post_init_user() instead of matrix_init_user because
// the latter runs before RGB initialization.
// Reference: https://www.reddit.com/r/olkb/comments/9ny0jp/qmk_rgb_settings_done_in_matrix_init_user_are/e7qf83n
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    set_gaming_lighting();
}

// NOTE: Using default_layer_state_set_user() instead of layer_state_set_user()
// because the latter is triggered on all layer changes, including momentary
// ones, which causes RGB lighting reset after using MO().
uint32_t default_layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _WL:
        set_work_lighting();
        break;
    case _GL:
        set_gaming_lighting();
        break;
    case _BL:
        set_default_lighting();
        break;
    default:
        // for any other layer, do nothing
        break;
    }

    return state;
}
