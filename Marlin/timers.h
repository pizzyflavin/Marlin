/*
 * timers.h
 *
 * Header file for times.cpp
 * Contains function prototypes for all functions in timers module
 *
 */

#ifndef TIMERS_H
#define TIMERS_H

#include <avr/io.h>

// Initialize timers 1, 3, 4, 5 to normal mode with no clock prescale
void timers_init();

void timer_set_freq(uint8_t timer, uint32_t freq);

// Set output compare register for given timer
void timer_set_count(uint8_t timer, uint16_t count);

void timer_enable(uint8_t timer);

void timer_disable(uint8_t timer);

void timer_set_pwm_duty(uint8_t timer, uint8_t duty_cycle);


#endif // TIMERS_H

