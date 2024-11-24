#include "plut0nium.h"

#define MOD_MASK_RALT MOD_BIT(KC_RALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_A:
    case KC_U:
    case KC_I:
        /*
         * Replace default AltGr + A -> Á -> À
         *                         U -> Ú -> Ù
         *                         I -> Í -> È
         */
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_RALT) {
                uint8_t _kc_new = (keycode == KC_I) ? KC_E : keycode; // <- only 1 alternative - FIX ME
                uint8_t _mods_tmp = get_mods();
                if (_mods_tmp & MOD_MASK_SHIFT) {
                    clear_mods(); // AltGr + Shift
                    tap_code(KC_GRV);
                    set_mods(_mods_tmp & MOD_MASK_SHIFT); // only LSFT|RSFT
                    tap_code(_kc_new); // -> À/Ù/È
                } else {
                    clear_mods(); // AltGr
                    tap_code(KC_GRV);
                    tap_code(_kc_new); // -> à/ù/è
                }
                set_mods(_mods_tmp); // restore mods for next keypress
                return false;
            }
            // if no RALT -> process normally (-> return true)
        }
        break;
    }

    return true;
}

