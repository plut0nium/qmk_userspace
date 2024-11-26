#pragma once

#include QMK_KEYBOARD_H

/* Custom keycodes defined for US Intl. */
#define KX_EURO ALGR(KC_5)
#define KX_CAD  LALT(LCTL(KC_DEL))

/* Accented/special chars */
#define KX_EACT ALGR(KC_E)
#define KX_ESZT ALGR(KC_S)
#define KX_OE   ALGR(KC_K)
#define KX_AE   ALGR(KC_Z)
#define KX_CEDL ALGR(KC_COMM)
#define KX_MU   ALGR(KC_M)

/* Macros */
enum custom_keycodes {
    KX_EGRV = SAFE_RANGE,
    KX_AGRV,
    KX_UGRV,
    KX_OCIR,
    KX_ICIR,
    KX_ECIR,
    KX_ACIR,
    KX_UCIR,
};



/* User functions */
bool process_record_user(uint16_t keycode, keyrecord_t *record);

