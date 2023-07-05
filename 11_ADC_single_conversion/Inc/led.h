/*
 * led.h
 *
 *  Created on: Jul 1, 2023
 *      Author: st
 */

#ifndef LED_H_
#define LED_H_
#include <stdint.h>

#define USER_LED1     (1U<<0)   // Green led
#define USER_LED2     (1U<<7)   // Blue led
#define USER_LED3     (1U<<14)  // Blue led

#define   GREEN_LED   USER_LED1
#define   BLUE_LED    USER_LED2
#define   RED_LED     USER_LED3

#define GPIOB_CLK_EN    (1U<<1)

typedef uint32_t ledType;

void user_leds_init(void);
void all_leds_on(void);
void all_leds_off(void);
void all_led_toggle(void);
void led_toggle(ledType led);
void led_on(ledType led);
void led_off(ledType led);

#endif /* LED_H_ */
