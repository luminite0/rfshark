/*
 * Example code for my CC1101 driver written in C for the Raspberry Pi Pico.
 *
 * Copyright (C) 2024 falconite40 <falconite400@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "cc1101.h"

void test_get_part_num(CC1101 *cc1101) {
    gpio_put(cc1101->cs_pin, 0);
    uint8_t data = 0b00000000 | 0x30;
    spi_write_blocking(cc1101->spi_bus, 0, data);
}

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }

    CC1101 *cc1101_0 = cc1101_init(2, 3, 4, 5);
    CC1101 *cc1101_1 = cc1101_init(18, 19, 16, 17);

    while (true) {
        //cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

        print_part_num(cc1101_0);
        print_part_num(cc1101_1);

        /*
        sleep_ms(500);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(500);*/
    }
}