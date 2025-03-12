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

#include "keymap_dvorak_programmer.h"

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


enum custom_keycodes {
  CAPS_CUSTOM = SAFE_RANGE,
  CZ_C,
  CZ_R,
  CZ_S,
  CZ_Z,
  CZ_A,
  CZ_Y,
  CZ_I,
  CZ_U,
  CZ_E,
  CZ_O,
  CZ_D,
  CZ_T,
  CZ_N,
};

enum layers{
    QWERTY,
    DVP,
    DVP_GB,
    FN,
    CZ,
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
  {DP_DLR, DP_TILD},
  {DP_AMPR, DP_1},
  {DP_LBRC, DP_2},
  {DP_LCBR, DP_3},
  {DP_RCBR, DP_4},
  {DP_LPRN, DP_5},
  {DP_EQL, DP_6},
  {DP_ASTR, DP_7},
  {DP_RPRN, DP_8},
  {DP_PLUS, DP_9},
  {DP_RBRC, DP_0},
  {DP_EXLM, DP_PERC},
  {DP_HASH, DP_GRV},
  {DP_SCLN, DP_COLN},
  {DP_COMM, DP_LABK},
  {DP_DOT, DP_RABK},
  {DP_SLSH, DP_QUES},
  {DP_AT, DP_CIRC},
  {DP_BSLS, DP_PIPE},
  {DP_MINS, DP_UNDS},
  {DP_QUOT, DP_DQUO},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 MO(FN),  KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [DVP] = LAYOUT_61_ansi(
      DP_DLR,    DP_AMPR,  DP_LBRC,  DP_LCBR,  DP_RCBR,  DP_LPRN,  DP_EQL,  DP_ASTR,  DP_RPRN,  DP_PLUS,  DP_RBRC,  DP_EXLM,  DP_HASH,  KC_ESC,
      KC_TAB,    DP_SCLN,  DP_COMM,  DP_DOT,   DP_P,     DP_Y,     DP_F,    DP_G,     DP_C,     DP_R,     DP_L,     DP_SLSH,  DP_AT,    DP_BSLS,
      KC_BSPC,   DP_A,     DP_O,     DP_E,     DP_U,     DP_I,     DP_D,    DP_H,     DP_T,     DP_N,     DP_S,     DP_MINS,            KC_ENT,
      KC_LSFT,   DP_QUOT,  DP_Q,     DP_J,     DP_K,     DP_X,     DP_B,    DP_M,     DP_W,     DP_V,     DP_Z,                       KC_UP,
      KC_LCTL,   KC_LWIN,  OSL(CZ),                              KC_SPC,                                MO(FN),   KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [DVP_GB] = LAYOUT_61_ansi(
      KC_DOLLAR, KC_AMPR,  KC_LBRC,  KC_LCBR,  KC_RCBR,  KC_LPRN,  KC_EQL,  KC_ASTR,  KC_RPRN,  KC_PLUS,  KC_RBRC,  KC_EXLM,  KC_HASH,  KC_ESC,
      KC_TAB,    KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,    KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_AT,    KC_BSLS,
      KC_BSPC,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,    KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,            KC_ENT,
      KC_LSFT,   KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,    KC_M,     KC_W,     KC_V,     KC_Z,                       KC_UP,
      KC_LCTL,   KC_LWIN,  OSL(CZ),                              KC_SPC,                                MO(FN),   KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [CZ] = LAYOUT_61_ansi(
      DP_DLR,    DP_AMPR,  DP_LBRC,  DP_LCBR,  DP_RCBR,  DP_LPRN,  DP_EQL,  DP_ASTR,  DP_RPRN,  DP_PLUS,  DP_RBRC,  DP_EXLM,  DP_HASH,  KC_ESC,
      KC_TAB,    DP_SCLN,  DP_COMM,  DP_DOT,   DP_P,     CZ_Y,     DP_F,    DP_G,     CZ_C,     CZ_R,     DP_L,     DP_SLSH,  DP_AT,    DP_BSLS,
      KC_BSPC,   CZ_A,     CZ_O,     CZ_E,     CZ_U,     CZ_I,     CZ_D,    DP_H,     CZ_T,     CZ_N,     CZ_S,     DP_MINS,            KC_ENT,
      KC_LSFT,   DP_QUOT,  DP_Q,     DP_J,     DP_K,     DP_X,     DP_B,    DP_M,     DP_W,     DP_V,     CZ_Z,                       KC_UP,
      KC_LCTL,   KC_LWIN,  KC_RALT,                              KC_SPC,                                MO(FN),   KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [FN] = LAYOUT_61_ansi(
        QK_BOOTLOADER,  DF(DVP),  DF(DVP_GB),  DF(QWERTY),  KC_FILE,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  KC_APP,   KC_SCRL,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    KC_PSCR,  KC_PGDN,  KC_END,             _______,
        _______,            _______,  BL_DOWN,  _______,  _______,  _______,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
};

void send_czech_letter(char* key, char* accent) {
    const uint8_t mods = get_mods();
    const uint8_t one_shot_mods = get_oneshot_mods();
    clear_mods();
    clear_oneshot_mods();

    bool shift_active = (( mods | one_shot_mods ) & MOD_MASK_SHIFT);

    bool should_shift = shift_active;

    SEND_STRING(SS_DOWN(X_RALT));
    send_string(accent);
    SEND_STRING(SS_UP(X_RALT));

    SEND_STRING(SS_DELAY(50));

    char* modifier_down = should_shift ? SS_DOWN(X_LSFT) : "";
    char* modifier_up = should_shift ? SS_UP(X_LSFT) : "";

    char* key_to_send = malloc(sizeof(modifier_down) + sizeof(modifier_up) + sizeof(key));

    strcpy(key_to_send, modifier_down);
    strcat(key_to_send, key);
    strcat(key_to_send, modifier_up);

    send_string(key_to_send);

    free(key_to_send);

    set_mods(mods);
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

bool process_czech_keyboard(uint16_t keycode, keyrecord_t *record) {
  static uint16_t registered_keycode = KC_NO;

  if (registered_keycode != KC_NO) {
    unregister_code16(registered_keycode);
    registered_keycode = KC_NO;
  }


 if (record->event.pressed) {
    const uint8_t mods = get_mods();
    bool ctrl_active = (mods & MOD_BIT(KC_LCTL)) != 0;

    switch (keycode) {
        case CZ_C:
          send_czech_letter("i", "i");
          return false;

        case CZ_R:
          send_czech_letter("o", "i");
          return false;

        case CZ_S:
          send_czech_letter(";", "i");
          return false;

        case CZ_Z:
          send_czech_letter("/", "i");
          return false;

        case CZ_A:
          send_czech_letter("a", "z");
          return false;

        case CZ_Y:
          send_czech_letter("t", "z");
          return false;

        case CZ_I:
          send_czech_letter("g", "z");
          return false;

        case CZ_U:
          if (ctrl_active) {
          send_czech_letter("f", "z");
          } else {
          send_czech_letter("f", "s");
          }
          return false;

        case CZ_E:
          if (ctrl_active) {
              send_czech_letter("d", "i");
          } else {
              send_czech_letter("d", "z");
          }
          return false;

        case CZ_O:
          send_czech_letter("s", "z");
          return false;

        case CZ_D:
          send_czech_letter("h", "i");
          return false;

        case CZ_T:
          send_czech_letter("k", "i");
          return false;

        case CZ_N:
          send_czech_letter("l", "i");
          return false;
    }
 }

 return true;
}

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
  //if (!process_ralt_combination(keycode, record)) { return false; }
  if (!process_czech_keyboard(keycode, record)) { return false; }
  return true;
}

