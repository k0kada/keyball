/*
Copyright 2021 @Yowkees

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

#include "pointing_device.h"
#include "oledkit.h"
#include "keymap_jp.h"

enum keymap_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _BALL,
};

/////////////////////////////////////////////////////////////////////////////
// Special key codes for shorthand

// clang-format off

// layer
#define KC_L_SPC LT(_LOWER, KC_SPC)
#define KC_A_EN LT(_BALL, KC_LANG2)   // cmd or adjust 
#define KC_R_JA LT(_RAISE, KC_LANG1)   // cmd or adjust 

// shift_t
// #define KC_S_EN LSFT_T(KC_LANG2)
#define KC_ALT_ESC ALT_T(KC_ESC)

// original
// #define KC_AL_CP MT(MOD_LALT, KC_CAPS)  // alt or caps lock
#define KC_G_BS MT(MOD_LGUI, KC_BSPC)   // command or back space
// #define KC_G_DEL MT(MOD_LGUI, KC_DEL)   // command or delete
#define KC_A_BS LT(_BALL, KC_BSPC)    // adjust or back space
#define KC_A_DEL LT(_BALL, KC_DEL)    // adjust or delete
#define KC_CTLTB CTL_T(KC_TAB)
// clang-format on

// clang-format off


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_right_ball(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_BTN2,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_BTN1,                         KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_QUOT,
  //|--------+--------+--------+--------+--------+--------'                    |--------+--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, JP_TILD,
  //|--------+--------+--------+--------+--------+-------+--------.            `--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_G_BS,     KC_A_EN,  KC_L_SPC,  KC_CTLTB, KC_ALT_ESC,           KC_ENT,    KC_R_JA,        KC_RGUI, KC_MEH,   KC_ESC
  //`--------+--------'  `--------'  `--------' `--------+--------'              `--------+--------'      `--------+--------+--------'
  ),

  [_RAISE] = LAYOUT_right_ball(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_EXLM,   JP_AT, KC_HASH,  KC_DLR, KC_PERC, _______,                      JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      JP_MINS, JP_PLUS, JP_LCBR, JP_RCBR, JP_PIPE,  JP_GRV,
  //|--------+--------+--------+--------+--------+--------'                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                               JP_UNDS,  JP_EQL, JP_LBRC, JP_RBRC, JP_BSLS, JP_TILD,
  //|--------+--------+--------+--------+--------+-------+--------.            `--------+--------+--------+--------+--------+--------|
      _______, _______,     KC_ENT,   KC_A_DEL,    KC_SPC, _______,                _______, _______,        _______, _______, _______
  //`--------+--------'  `--------'  `--------' `--------+--------'              `--------+--------'      `--------+--------+--------'
  ),

  [_LOWER] = LAYOUT_right_ball(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_1,     KC_2,    KC_3,    KC_4,    KC_5, _______,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_BTN3, _______,
  //|--------+--------+--------+--------+--------+--------'                    |--------+--------+--------+--------+--------+--------|
        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, _______,
  //|--------+--------+--------+--------+--------+-------+--------.            `--------+--------+--------+--------+--------+--------|
      _______, KC_PERC,    _______,    _______,   _______, _______,                KC_A_BS, _______,        _______, _______, _______
  //`--------+--------'  `--------'  `--------' `--------+--------'              `--------+--------'      `--------+--------+--------'
  ),

  [_BALL] = LAYOUT_right_ball(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,KC_BTN1,KC_BTN2,KC_BTN3,                     KC_BTN1,KC_BTN2,KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------'                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------+--------.            `--------+--------+--------+--------+--------+--------|
      _______, KC_PERC,    _______,    _______,   _______, _______,                KC_A_BS, _______,        _______, _______, _______
  //`--------+--------'  `--------'  `--------' `--------+--------'              `--------+--------'      `--------+--------+--------'
  ),

};

// shfft + jp対応
static bool process_jp_symbols_impl(uint16_t keycode, bool pressed) {
    if (!pressed) {
        return true;
    }
    uint8_t shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
    if (!shift) {
        return true;
    }
    uint16_t s;
    switch (keycode) {
        // Replace Shift-Symbols like ANSI for JIS.
        case JP_2:    s = JP_AT; break;
        case JP_6:    s = JP_CIRC; break;
        case JP_7:    s = JP_AMPR; break;
        case JP_8:    s = JP_ASTR; break;
        case JP_9:    s = JP_LPRN; break;
        case JP_0:    s = JP_RPRN; break;
        case JP_GRV:  s = JP_TILD; break;
        case JP_EQL:  s = JP_PLUS; break;
        case JP_MINS: s = JP_UNDS; break;
        case JP_QUOT: s = JP_DQUO; break;
        case JP_SCLN: s = JP_COLN; break;
        default: return true;
    }
    unregister_mods(shift);
    tap_code16(s);
    register_mods(shift);
    return false;
}

bool process_jp_symbols(uint16_t keycode, keyrecord_t *record) {
    return process_jp_symbols_impl(keycode, record->event.pressed);
}

void tap_code16jp(uint16_t keycode) {
    if (process_jp_symbols_impl(keycode, true)) {
        tap_code16(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_jp_symbols(keycode, record);
}


// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BALL:
            keyball_set_scroll_mode(true);
            break;
        default:
            keyball_set_scroll_mode(false);
            break;
    }
    return state;
}

#ifdef OLED_ENABLE

void oledkit_render_info_user(void) {
    const char *n;
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            n = PSTR("Default");
            break;
        case _RAISE:
            n = PSTR("Raise");
            break;
        case _LOWER:
            n = PSTR("Lower");
            break;
        case _BALL:
            n = PSTR("Adjust");
            break;
        default:
            n = PSTR("Undefined");
            break;
    }
    oled_write_P(PSTR("Layer: "), false);
    oled_write_ln_P(n, false);

    keyball_oled_render_ballinfo();
    keyball_oled_render_keyinfo();
}

#endif
