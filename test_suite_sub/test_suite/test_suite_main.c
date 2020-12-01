#include <sdk/config.h>
#include <nuttx/config.h>
#include <nuttx/irq.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include <arch/board/board.h>
#include <arch/chip/pin.h>

int test_suite_main(int argc, char *argv[])
{
  int loop;
  uint32_t pin_sw_left = 39;
  uint32_t pin_sw_right = 29;
  uint32_t pin_led_g = 47;
  uint32_t pin_led_y = 46;
  printf("start TEST_SUITE for SPRESENSE Evaluation Board.\n");
  
  board_gpio_config(pin_sw_left, 0, true, false, PIN_FLOAT); 
  board_gpio_config(pin_sw_right, 0, true, false, PIN_FLOAT);
  board_gpio_config(pin_led_g, 0, false, false, PIN_FLOAT);
  board_gpio_config(pin_led_y, 0, false, false, PIN_FLOAT);

  for (loop = 0; loop < 16; loop++) {
    printf("[%d] GPIO_L=%d, _R=%d\n", loop, board_gpio_read(pin_sw_left), board_gpio_read(pin_sw_right));
    switch(loop % 4) {
      case 0:
        board_gpio_write(pin_led_g, 0);
        board_gpio_write(pin_led_y, 0);
        break;
      case 1:
        board_gpio_write(pin_led_g, 1);
        board_gpio_write(pin_led_y, 0);
        break;
      case 2:
        board_gpio_write(pin_led_g, 1);
        board_gpio_write(pin_led_y, 1);
        break;
      case 3:
        board_gpio_write(pin_led_g, 0);
        board_gpio_write(pin_led_y, 1);
        break;
    }
    sleep(1);
  }

  

  return 0;
}
