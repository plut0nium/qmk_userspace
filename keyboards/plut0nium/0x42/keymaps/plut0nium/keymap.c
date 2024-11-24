/** 
 * Copyright 2020 - Charles Fourneau
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

#include "plut0nium.h"

/* Define layer names */
enum layer_names {
    _COLEMAK,
    _QWERTY,
    _NUM,
    _FN
};

/* Layer change */
#define DF_CLMK DF(_COLEMAK)
#define DF_QWTY DF(_QWERTY)
#define MO_NUM  MO(_NUM)
#define MO_FN   MO(_FN)

/* split space */
//#define MT_LSPC MT(MOD_LCTL, KC_SPC)
#define LT_LSPC LT(_FN, KC_SPC)
#define MT_RSPC MT(MOD_RALT, KC_SPC)
#define MT_LCTL MT(MOD_LCTL, KC_DEL)

/* Layouts */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_hhkb_2u(    /* COLEMAK-DHm */
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
        MT_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_HOME, KC_PGUP, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_END,  KC_PGDN, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_MUTE, KC_LGUI, KC_LALT, MO_NUM,     LT_LSPC,            MT_RSPC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),

    [_QWERTY] = LAYOUT_hhkb_2u(    /* QWERTY - TODO */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_MUTE, KC_LGUI, KC_LALT, KC_SPC,     KC_SPC,            LT_LSPC,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),

    [_NUM] = LAYOUT_hhkb_2u(    /* Numpad & symbols */
        KC_GRV,  _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_BSLS,
        _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_1,    KC_2,    KC_3,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, KC_EQL,  KC_0,    _______, _______, KC_PLUS, _______,
                 _______, _______, _______, _______,    _______,             _______,    _______, _______, _______, _______
    ),
    
    [_FN] = LAYOUT_hhkb_2u(    /* FN */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, DF_QWTY, DF_CLMK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, BL_STEP, BL_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______,
                 _______, BL_TOGG, BL_UP,   _______,     _______,            _______,    _______, _______, _______, _______
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch(biton32(layer_state)){
        case _FN:
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
            break;
        default:
            if (clockwise){
                tap_code(KC_VOLU);
            } else{
                tap_code(KC_VOLD);
            }
        }
    }

    return true;
}
#endif // ENCODER_ENABLE
