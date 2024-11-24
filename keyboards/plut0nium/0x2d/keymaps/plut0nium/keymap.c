/** 
 * Copyright 2022 - Charles Fourneau
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

enum layer_names {
    _COLEMAK,
    _QWERTY,
    _FNUM,
    _SYM,
    _NAV
};

#define DF_CLMK DF(_COLEMAK)
#define DF_QWTY DF(_QWERTY)
#define MO_FNUM MO(_FNUM)
#define TT_FNUM TT(_FNUM)
#define MO_SYM  MO(_SYM)
#define MO_NAV  MO(_NAV)

#define MT_RSPC MT(MOD_RALT, KC_SPC)
#define MT_LCTL MT(MOD_LCTL, KC_DEL)
#define MT_RSFT MT(MOD_RSFT, KC_QUOT)

/* Layouts */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_hhkb_2u(    /* COLEMAK */
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        MT_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSFT,
                 KC_LGUI, KC_LALT, MO_NAV,  TT_FNUM, KC_MUTE,    MT_RSPC,       MO_SYM,  KC_DOWN, KC_RGHT
    ),

    [_QWERTY] = LAYOUT_hhkb_2u(    /* QWERTY - TODO */
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_LCTL, KC_LGUI, KC_LALT, MO_FNUM, KC_SPC,     KC_SPC,        KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_FNUM] = LAYOUT_hhkb_2u(    /* Fn & Numbers */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_F11,  KC_F12,  _______, _______, _______, _______, KC_PLUS, KC_MINS, KC_ASTX, _______, KC_EQL,
                 _______, _______, _______, _______, _______,      _______,     _______, _______, _______
    ),
    
    [_SYM] = LAYOUT_hhkb_2u(    /* Symbols */
        KC_GRV,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
                 _______, _______, _______, _______, _______,      _______,     _______, _______, _______
    ),

    [_NAV] = LAYOUT_hhkb_2u(    /* Navigation */
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAD,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,
        _______, BL_DEC,  BL_TOGG, BL_STEP, BL_INC,  _______, _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, RESET,
                 _______, _______, _______, _______, _______,      _______,     _______, _______, _______
    ),

    // [_LAYER] = LAYOUT_hhkb_2u(    /* Layer template */
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //              _______, _______, _______, _______, _______,      _______,     _______, _______, _______
    // ),
};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch(biton32(layer_state)){
        case _NAV:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        default:
            if (clockwise){
                tap_code(KC_WH_U);
            } else{
                tap_code(KC_WH_D);
            }
        }
    }

    return true;
}
#endif // ENCODER_ENABLE
