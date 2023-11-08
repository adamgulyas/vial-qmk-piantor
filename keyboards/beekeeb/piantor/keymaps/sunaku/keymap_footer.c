#include "features/select_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_select_word(keycode, record, SELECT_WORD)) { return false; }
    // Your macros ...

    // handle sticky holding of Miryoku thumb cluster layer-taps as toggles
    if (keycode == STICKY_LAYER_TOGGLE && record->event.pressed) {
        default_layer_set(default_layer_state ? 0 : (1 << get_highest_layer(layer_state)));
    }

    return true;
}

#ifdef VIAL_ENABLE
  void
#else
  bool
#endif
