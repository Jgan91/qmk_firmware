#pragma once

#include QMK_KEYBOARD_H

typedef struct {
    os_variant_t type;
} os_t;

typedef enum {
    NONE,
    SWAPPING_START,
    SWAPPING_CONTINUE,
} swapper_state_t;

typedef struct {
    uint8_t state;
} swapper_t;

bool is_macos(void);
bool process_swapper(uint16_t keycode, keyrecord_t *record);
