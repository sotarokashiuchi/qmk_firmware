// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// tap danceの宣言
enum {
    TD_FORWARD_NEXT,
    TD_BACK_PREV,
};

enum layer {
    _BASE = 0,
    _L1,
    _L2,
    _L3,
};

// tap danceの定義
tap_dance_action_t tap_dance_actions[] = {
    [TD_FORWARD_NEXT]  = ACTION_TAP_DANCE_DOUBLE(KC_MEDIA_FAST_FORWARD, KC_MEDIA_NEXT_TRACK),
    [TD_BACK_PREV]  = ACTION_TAP_DANCE_DOUBLE(KC_MEDIA_REWIND, KC_MEDIA_PREV_TRACK),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_L1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * └───┴───┴───┘
     */
    [_BASE] = LAYOUT_ortho_3x2(
        TD(TD_BACK_PREV),   KC_MEDIA_PLAY_PAUSE,   TD(TD_FORWARD_NEXT),
        KC_MUTE,   MO(_L1),   KC_SYSTEM_SLEEP
    ),
    [_L1] = LAYOUT_ortho_3x2 (
        KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
    [_L2] = LAYOUT_ortho_3x2(
        KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
    [_L3] = LAYOUT_ortho_3x2(
        KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS
    )
};
