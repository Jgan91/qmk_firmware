/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// Optimization to save memory
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Make it easier to work with tap hold
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 175
#define QUICK_TAP_TERM_PER_KEY
#define ONESHOT_TIMEOUT 1000
#define TAPPING_TOGGLE 1

// Configure leader key
#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING

// Configure combos
#define COMBO_TERM 30
#define EXTRA_SHORT_COMBOS
#define COMBO_STRICT_TIMER
#define COMBO_HOLD_TERM 175
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_SHOULD_TRIGGER

// Disable Alt Repeat
#define NO_ALT_REPEAT_KEY
// Timeout to produce an alternate repeat result
#define CUSTOM_ALT_REPEAT_KEY_TIMEOUT 1000

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    ifndef RGBLIGHT_LIMIT_VAL
#    	define RGBLIGHT_LIMIT_VAL 150
#    endif
#endif

