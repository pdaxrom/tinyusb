/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */

#include "bsp/board_api.h"
#include "board.h"
#include <libdragon.h>

/*
//--------------------------------------------------------------------+
// Forward USB interrupt events to TinyUSB IRQ Handler
//--------------------------------------------------------------------+
void __attribute__ ((interrupt(USB_UBM_VECTOR))) USB_UBM_ISR(void)
{
  tud_int_handler(0);
}
*/

//--------------------------------------------------------------------+
// MACRO TYPEDEF CONSTANT ENUM
//--------------------------------------------------------------------+

//uint32_t wait = 0;

void board_init(void)
{
//FIXME: sashz

}

//--------------------------------------------------------------------+
// Board porting API
//--------------------------------------------------------------------+

void board_led_write(bool state)
{
//FIXME: sashz
(void)state;

}

uint32_t board_button_read(void)
{
//FIXME: sashz

//  return ((P1IN & BIT1) >> 1) == BUTTON_STATE_ACTIVE;
    return 0;
}

int board_uart_read(uint8_t * buf, int len)
{
//FIXME: sashz
(void)buf;

  return len;
}

int board_uart_write(void const * buf, int len)
{
//FIXME: sashz
(void)buf;

  return len;
}

#if CFG_TUSB_OS  == OPT_OS_NONE
/*
volatile uint32_t system_ticks = 0;
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) TIMER0_A0_ISR (void)
{
  system_ticks++;
  // TAxCCR0 CCIFG resets itself as soon as interrupt is invoked.
}

uint32_t board_millis(void)
{
  uint32_t systick_mirror;

  // 32-bit update is not atomic on MSP430. We can read the bottom 16-bits,
  // an interrupt occurs, updates _all_ 32 bits, and then we return a
  // garbage value. And I've seen it happen!
  TA0CCTL0 &= ~CCIE;
  systick_mirror = system_ticks;
  TA0CCTL0 |= CCIE;

  return systick_mirror;
}
 */
#endif
