/*
 * systick.h
 *
 *  Created on: Jul 2, 2023
 *      Author: st
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

void systickDelayMs(int delay);
void systick_1hz_interrupt(void);

#endif /* SYSTICK_H_ */
