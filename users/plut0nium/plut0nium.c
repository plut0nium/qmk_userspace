#include "plut0nium.h"

/* Custom Mod mask for RAlt (AltGr) */
#define MOD_MASK_RALT MOD_BIT(KC_RALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t _base_kc;
    uint16_t _dead_kc;

    switch (keycode) {
    case KX_EGRV:
        _base_kc = KC_E;
        _dead_kc = KC_GRV;
        break;
    case KX_AGRV:
        _base_kc = KC_A;
        _dead_kc = KC_GRV;
        break;
    case KX_UGRV:
        _base_kc = KC_U;
        _dead_kc = KC_GRV;
        break;
    case KX_OCIR:
        _base_kc = KC_O;
        _dead_kc = KC_CIRC;
        break;
    case KX_ICIR:
        _base_kc = KC_I;
        _dead_kc = KC_CIRC;
        break;
    case KX_ECIR:
        _base_kc = KC_E;
        _dead_kc = KC_CIRC;
        break;
    case KX_ACIR:
        _base_kc = KC_A;
        _dead_kc = KC_CIRC;
        break;
    case KX_UCIR:
        _base_kc = KC_U;
        _dead_kc = KC_CIRC;
        break;
    default:
        /* Not a registered macro */
        return true;
    }

    if (record->event.pressed) {
        uint8_t _mods_tmp = get_mods();
        clear_mods();
        tap_code16(_dead_kc);
        set_mods(_mods_tmp & MOD_MASK_SHIFT); // restore Shift
        tap_code(_base_kc);
        set_mods(_mods_tmp); // restore mods for next keypress
        return false;
    }

    return true;
}

