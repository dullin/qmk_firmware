/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_canadian_multilingual.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNC_NUM
};

enum planck_keycodes {
  BACKLIT = SAFE_RANGE,
  US_OPEN_BRACE,
  US_CLOSE_BRACE,
  US_BACKSLASH,
  US_QUOT,
  US_COMMA,
  US_DOT,
  US_BACKTICK
};

enum unicode_names {
    C_CEDILLE_LOWER,
    C_CEDILLE_UPPER,
    E_AIGU_LOWER,
    E_AIGU_UPPER, 
    A_HAT_LOWER,
    A_HAT_UPPER,
    E_HAT_LOWER,
    E_HAT_UPPER,
    I_HAT_LOWER,
    I_HAT_UPPER,
    O_HAT_LOWER,
    O_HAT_UPPER,
    U_HAT_LOWER,
    U_HAT_UPPER,
    A_GRAVE_LOWER,
    A_GRAVE_UPPER,
    E_GRAVE_LOWER,
    E_GRAVE_UPPER,
    U_GRAVE_LOWER,
    U_GRAVE_UPPER,
    E_TREMA_UPPER,
    E_TREMA_LOWER,
    I_TREMA_UPPER,
    I_TREMA_LOWER,
    U_TREMA_UPPER,
    U_TREMA_LOWER 
};

const uint32_t PROGMEM unicode_map[] = {
    [C_CEDILLE_LOWER] = 0x00E7,  // ç
    [C_CEDILLE_UPPER] = 0x00C7,  // Ç
    [E_AIGU_LOWER]  = 0x00E9, // é
    [E_AIGU_UPPER]  = 0x00C9, // É
    [E_AIGU_LOWER]  = 0x00E9, // 
    [E_AIGU_UPPER]  = 0x00C9, // 
    [A_HAT_LOWER] = 0x00E2, // 
    [A_HAT_UPPER] = 0x00C2, // 
    [E_HAT_LOWER] = 0x00EA, // 
    [E_HAT_UPPER] = 0x00CA, // 
    [I_HAT_LOWER] = 0x00EE, // 
    [I_HAT_UPPER] = 0x00CE, // 
    [O_HAT_LOWER] = 0x00F4, // 
    [O_HAT_UPPER] = 0x00D4, // 
    [U_HAT_LOWER] = 0x00FB, // 
    [U_HAT_UPPER] = 0x00DB, // 
    [A_GRAVE_LOWER] = 0x00E0, // 
    [A_GRAVE_UPPER] = 0x00C0, // 
    [E_GRAVE_LOWER] = 0x00E8, // 
    [E_GRAVE_UPPER] = 0x00C8, // 
    [U_GRAVE_LOWER] = 0x00F9, // 
    [U_GRAVE_UPPER] = 0x00D9, // 
    [E_TREMA_LOWER] = 0x00EB, // 
    [E_TREMA_UPPER] = 0x00CB, // 
    [I_TREMA_LOWER] = 0x00EF, // 
    [I_TREMA_UPPER] = 0x00CF, // 
    [U_TREMA_LOWER] = 0x00FC, // 
    [U_TREMA_UPPER] = 0x00DC // 
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNC_NUM MO(_FUNC_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    MT(MOD_LSFT | MOD_LALT, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT) ,
    KC_LCTL, KC_LALT, FUNC_NUM, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    KC_TAB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_GRV, KC_LPRN,   KC_RPRN,    KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_HOME,    KC_PGDOWN, KC_PGUP, KC_END
),

[_FUNC_NUM] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,   KC_P7, KC_P8,  KC_P9, KC_PMNS, _______,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______,   KC_P4, KC_P5,  KC_P6, KC_PPLS, _______,
    _______, KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   _______, KC_P1, KC_P2, KC_P3,  KC_PAST, KC_PENT, 
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,  KC_PDOT, KC_PSLS, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, UC_M_WC, _______, RESET  , _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, KC_SYSTEM_SLEEP, _______, _______, _______, _______, _______, _______,  UC_M_LN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, UC_M_MA, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, XP(E_HAT_LOWER,E_HAT_UPPER), XP(E_TREMA_LOWER,E_TREMA_UPPER), _______, XP(U_HAT_LOWER,U_HAT_UPPER), XP(U_GRAVE_LOWER,U_GRAVE_UPPER), XP(I_HAT_LOWER,I_HAT_UPPER), XP(O_HAT_LOWER,O_HAT_UPPER), _______, _______,
    _______, XP(A_HAT_LOWER,A_HAT_UPPER), _______, _______, _______, _______, _______, XP(U_TREMA_LOWER,U_TREMA_UPPER), XP(I_TREMA_LOWER,I_TREMA_UPPER), XP(C_CEDILLE_LOWER, C_CEDILLE_UPPER), XP(E_GRAVE_LOWER,E_GRAVE_UPPER), XP(A_GRAVE_LOWER,A_GRAVE_UPPER),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XP(E_AIGU_LOWER, E_AIGU_UPPER), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case KC_COMM:
      //return custom_keycode_on_modifiers(MOD_BIT(KC_LSHIFT), -1, record,  CA_LABK);
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
