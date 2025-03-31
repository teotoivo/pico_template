#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  const uint led_pin = 15; // <-- onboard LED for test
  uint count = 0;

  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);

  stdio_init_all();

  while (true) {
    gpio_put(led_pin, true);
    printf("Blinking! %u\r\n", ++count);
    sleep_ms(1000);
    gpio_put(led_pin, false);
    sleep_ms(1000);
  }
}
