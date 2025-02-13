/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "features/custom_shift_keys.h"
#include QMK_KEYBOARD_H

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

enum layers{
    QWERTY,
    DVORAK_PROGRAMMER,
    WIN_FN,
    SPECIAL,
};

enum {
    TD_E_DIA = 0
};

// Tap Dance Actions
void tap_dance_implementation(tap_dance_state_t *state, void *user_data) {
        switch (state->count) {
        case 1:  // Single tap: é
            SEND_STRING("é");  // Sends Unicode for 'é'
            break;
        case 2:  // Double tap: ě
            SEND_STRING("ě");  // Sends Unicode for 'ě'
            break;
        default:
            break;
    }
}

// Define Tap Dance Actions
tap_dance_action_t tap_dance_actions[] = {
    [TD_E_DIA] = ACTION_TAP_DANCE_FN(tap_dance_implementation), // Using custom function
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOLLAR, KC_TILDE},
  {KC_AMPERSAND, KC_1},
  {KC_LEFT_BRACKET, KC_2},
  {KC_LEFT_CURLY_BRACE, KC_3 },
  {KC_RIGHT_CURLY_BRACE, KC_4},
  {KC_LEFT_PAREN, KC_5},
  {KC_EQUAL, KC_6},
  {KC_ASTR, KC_7},
  {KC_RIGHT_PAREN, KC_8},
  {KC_PLUS, KC_9},
  {KC_RIGHT_BRACKET, KC_0},
  {KC_EXLM, KC_PERC},
  {KC_HASH, KC_GRV},
  {KC_AT, KC_CIRC},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),MO(WIN_FN),KC_RCTL),

    [DVORAK_PROGRAMMER] = LAYOUT_61_ansi(
      KC_DOLLAR, KC_AMPR,  KC_LBRC,  KC_LCBR,  KC_RCBR,  KC_LPRN,  KC_EQL,  KC_ASTR,  KC_RPRN,  KC_PLUS,  KC_RBRC,  KC_EXLM,  KC_HASH,  KC_ESC,
      KC_TAB,    KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,    KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_AT,    KC_BSLS,
      KC_BSPC,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,    KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,            KC_ENT,
      KC_LSFT,   KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,    KC_M,     KC_W,     KC_V,     KC_Z,                       KC_UP,
      KC_LCTL,   KC_LWIN,  TG(SPECIAL),                              KC_SPC,                                MO(WIN_FN),   KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [SPECIAL] = LAYOUT_61_ansi(
      KC_DOLLAR, KC_AMPR,  KC_LBRC,  KC_LCBR,  KC_RCBR,  KC_LPRN,  KC_EQL,  KC_ASTR,  KC_RPRN,  KC_PLUS,  KC_RBRC,  KC_EXLM,  KC_HASH,  KC_ESC,
      KC_TAB,    KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,    KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_AT,    KC_BSLS,
      KC_BSPC,   KC_A,     KC_O,     TD(TD_E_DIA),     KC_U,     KC_I,     KC_D,    KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,            KC_ENT,
      KC_LSFT,   KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,    KC_M,     KC_W,     KC_V,     KC_Z,                       KC_UP,
      KC_LCTL,   KC_LWIN,  _______,                              KC_SPC,                                MO(WIN_FN),   KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [WIN_FN] = LAYOUT_61_ansi(
        KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  KC_APP,   KC_SCRL,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    KC_PSCR,  KC_PGDN,  KC_END,             _______,
        _______,            _______,  BL_DOWN,  _______,  _______,  _______,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
};

const custom_shift_key_t custom_meta_keys[] = {
  {KC_AMPERSAND, KC_1},
  {KC_LEFT_BRACKET, KC_2},
  {KC_LEFT_CURLY_BRACE, KC_3 },
  {KC_RIGHT_CURLY_BRACE, KC_4},
  {KC_LEFT_PAREN, KC_5},
  {KC_EQUAL, KC_6},
  {KC_ASTR, KC_7},
  {KC_RIGHT_PAREN, KC_8},
  {KC_PLUS, KC_9},
  {KC_RIGHT_BRACKET, KC_0},
};
uint8_t NUM_CUSTOM_META_KEYS =
    sizeof(custom_meta_keys) / sizeof(custom_shift_key_t);

bool process_meta_combination(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (get_mods() == MOD_BIT(KC_LWIN)) {
            for (int i = 0; i < NUM_CUSTOM_META_KEYS; ++i) {
                if (keycode == custom_meta_keys[i].keycode) {
                    tap_code16(custom_meta_keys[i].shifted_keycode);
                    return false;
                }
            }
        }
    }

    return true;
}

typedef struct {
  uint16_t keycode;
  uint16_t alter_keycode;
  uint16_t shifted_keycode;
} custom_key_t;

const custom_key_t custom_ralt_keys[] = {
  {KC_UP, KC_MS_UP, KC_MS_WH_UP},
  {KC_DOWN, KC_MS_DOWN, KC_MS_WH_DOWN},
  {KC_LEFT, KC_MS_LEFT, KC_MS_WH_LEFT },
  {KC_RIGHT, KC_MS_RIGHT,KC_MS_WH_RIGHT },
  {KC_ENT, KC_MS_BTN1,KC_MS_BTN2 },
  {KC_BSLS, KC_MS_BTN3, KC_MS_BTN3}
};
uint8_t NUM_custom_ralt_keys =
    sizeof(custom_ralt_keys) / sizeof(custom_key_t);

bool process_ralt_combination(uint16_t keycode, keyrecord_t *record) {
  static uint16_t registered_keycode = KC_NO;

  if (registered_keycode != KC_NO) {
    unregister_code16(registered_keycode);
    registered_keycode = KC_NO;
  }

    if (record->event.pressed) {
        const uint8_t mods = get_mods();


        if ((mods & MOD_BIT(KC_RALT)) != 0) {
            bool shift_pressed = mods & MOD_BIT(KC_LSFT);

            for (int i = 0; i < NUM_custom_ralt_keys; ++i) {
                if (keycode == custom_ralt_keys[i].keycode) {
                    registered_keycode = custom_ralt_keys[i].alter_keycode;

                    if (shift_pressed) {
                        registered_keycode = custom_ralt_keys[i].shifted_keycode;
                    }

                    register_code16(registered_keycode);
                    return false;
                }
            }
        }
    }

    return true;

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  if (!process_meta_combination(keycode, record)) { return false; }
  if (!process_ralt_combination(keycode, record)) { return false; }
  return true;
}

