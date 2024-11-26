/** 
 * Copyright 2024 - Charles Fourneau
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

/* Layers */
enum layer_names {
    _COLEMAK,
    _QWERTY,
    _TYPO,
    _CODE,
    _FUNC,
    _NMPD
};

/* Base Layer change */
#define DF_CLMK DF(_COLEMAK)
#define DF_QWTY DF(_QWERTY)

/* Util Layers */
#define MO_FUNC MO(_FUNC)

/* Split Space */
#define LT_LSPC LT(_CODE, KC_SPC) /* Left space | Typo */
#define LT_RSPC LT(_TYPO, KC_SPC) /* Right space | Code */

/* Mod Taps */
#define MT_RSPC MT(MOD_RALT, KC_SPC)
#define MT_LCTL MT(MOD_LCTL, KC_DEL)

/* Layouts */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_hhkb_2u(    /* COLEMAK-DH */
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
        MT_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_PGDN, KC_PGUP, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_HOME, KC_END,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_MUTE, KC_LGUI, KC_LALT, MO_FUNC,    LT_LSPC,            LT_RSPC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),

    [_QWERTY] = LAYOUT_hhkb_2u(    /* QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_MUTE, KC_LGUI, KC_LALT, MO_FUNC,    KC_SPC,            KC_SPC,       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),

    [_TYPO] = LAYOUT_hhkb_2u(    /* Typographic symbols (mostly French + intl) */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KX_ACIR, _______, _______, _______, _______, _______, _______, _______, KX_UCIR, KX_UGRV, _______, KC_DQUO, _______,
        _______, KX_AGRV, _______, _______, _______, _______, _______, _______, KX_MU,   KX_EACT, KX_EGRV, KX_ICIR, KX_OCIR, _______,
        _______, KX_AE,   _______, KX_CEDL, _______, _______, _______, _______, _______, _______, KX_ECIR, _______, KX_OE,   _______,
                 _______, _______, _______, _______,    _______,             _______,    _______, _______, _______, _______
    ),

    [_CODE] = LAYOUT_hhkb_2u(    /* Programming symbols */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_CIRC, KC_LT,   KC_GT,   KC_DLR,  KC_PERC, _______, _______, KC_AT,   KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______,
        _______, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,  _______, _______, KC_BSLS, KC_MINS, KC_PLUS, KC_SLSH, KC_GRV,  _______,
        _______, KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH, _______, _______, KC_PIPE, KC_EXLM, KC_SCLN, KC_COLN, KC_QUES, _______,
                 _______, _______, _______, _______,    _______,             _______,    _______, _______, _______, _______
    ),
    
    [_FUNC] = LAYOUT_hhkb_2u(    /* Function */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, DF_QWTY, DF_CLMK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KX_CAD,  _______,
        _______, _______, BL_STEP, BL_DOWN, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______, _______, QK_BOOT, _______,
                 _______, BL_TOGG, BL_UP,   _______,     _______,            _______,    _______, _______, _______, _______
    ),

    [_NMPD] = LAYOUT_hhkb_2u(    /* Numpad & symbols */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL,  KC_0,    _______, _______, KC_PLUS, _______,
                 _______, _______, _______, _______,    _______,             _______,    _______, _______, _______, _______
    ),

//    [_EMPTY] = LAYOUT_hhkb_2u(    /* EMPTY (template) */
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                 _______, _______, _______, _______,    _______,             _______,    _______, _______, _______, _______
//    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch(get_highest_layer(layer_state)){
        case _FUNC:
            /* Adjust Brightness */
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
            break;
        default:
            /* Volume Up/Down */
            if (clockwise){
                tap_code(KC_VOLU);
            } else{
                tap_code(KC_VOLD);
            }
        }
    }

    return false;
}
#endif // ENCODER_ENABLE
