#include QMK_KEYBOARD_H

#include "os_detection.h"

#include "swapper.h"

#include "../definitions/keycodes.h"

static os_t os = {.type = OS_UNSURE};
static uint8_t detect_try_count = 0;

bool is_macos(void) {
    return os.type == OS_MACOS || os.type == OS_IOS;
}

swapper_t swapper = {.state = NONE};

void try_detect_os(void) {
    if (os.type != OS_UNSURE) {
        return;
    }

    if (os.type == OS_UNSURE && detect_try_count > 10) {
        os.type = OS_WINDOWS;
        return;
    }

    os.type = detected_host_os();
    
    detect_try_count++;
}

bool process_swapper(uint16_t keycode, keyrecord_t *record) {
    try_detect_os();
    bool isMacOS = is_macos();
    
    if (record != NULL && record->event.pressed) {
        return false;
    }
    
    // Finish swapper
    if (keycode != SWAPPER) {
      if (swapper.state != NONE) {
        unregister_mods(get_mods());
        swapper.state = NONE;
      }
      return false;
    }

    if (swapper.state == NONE) {
        swapper.state = SWAPPING_START;
    }
    
    // Start swapper
    switch (swapper.state) {
        case SWAPPING_START:
            if (isMacOS) {
                register_mods(MOD_LGUI);
            } else {
                register_mods(MOD_LALT);
            }
            swapper.state = SWAPPING_CONTINUE;
            break;
        default:
            break;
    }
    
    // Process swap action
    switch (swapper.state) {
      case SWAPPING_CONTINUE:
          tap_code(KC_TAB);
          break;
      default:
          break;
    }
    return false;
}
