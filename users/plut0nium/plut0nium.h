#pragma once

#include QMK_KEYBOARD_H

#define KC_EUR ALGR(KC_5)
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_ASTX KC_ASTERISK

/* User functions */
bool process_record_user(uint16_t keycode, keyrecord_t *record);

