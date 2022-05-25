void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index <= led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    if (layer == 1) rgb_matrix_set_color(index, RGB_GREEN);
                    else if (layer == 2) rgb_matrix_set_color(index, RGB_BLUE);
                    else if (layer == 3) rgb_matrix_set_color(index, RGB_RED);
                }
            }
        }
    }
}
