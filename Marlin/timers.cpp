/*
 * timers.cpp
 *
 * Contains functions for controlling timer operation.
 *
 * Timer0 is 8-bit only!
 *
 * Ricky Rininger December 2017
 *
 * (c) 2017 Voxel8, Inc.
 */

#include <avr/interrupt.h>

#include "timers.h"

//=====================================
// Functions
//=====================================

void timers_init() {
    // Initialize control registers to 0
//    TCCR0A = 0;
//    TCCR0B = 0;
   // TCCR1A = 0;
   // TCCR1B = 0;
    TCCR3A = 0;
    TCCR3B = 0;
   // TCCR4A = 0;
   // TCCR4B = 0;
   // TCCR5A = 0;
   // TCCR5B = 0;
    // Timer Control Registers:

    // Timer0 is 8-bit, only for impeller motor
//    TCCR0A = (_BV(WGM01)); // Set to CTC mode
//    TCCR0B = (_BV(CS00)); // No clk prescale
//    OCR0A = 0xFF; // initialize OCR to max -> slowest RPM

    // Set some timers to CTC mode with no clk prescale (f_clk/1)
    // CSn2:0 = 1, WGMn3:0 = 4
  //  TCCR1B = (_BV(WGM12) | _BV(CS10));
  //  OCR1A = 0xFFFF;

    // Timer 3 - Set to Fast PWM mode with top as ICR3
    TCCR3A = (_BV(WGM31) | _BV(COM3A1));
    TCCR3B = (_BV(WGM33) | _BV(WGM32) | _BV(CS30)); // Set WGM bits, Only Set CS30 for no prescaling (FCLK/1)
    ICR3 = 0x0320;// 800 with no prescale in Fast PWM = 20 kHz
    OCR3A = 160; // Initially zero duty cycle (400 for testing)

    // Timer 4
  // TCCR4B = (_BV(WGM42) | _BV(CS40));
  //  OCR4A = 0xFFFF;
    // Timer 5
  //  TCCR5B = (_BV(WGM52) | _BV(CS50));
  //  OCR5A = 0xFFFF;
    // Timer Interrupt Enable for OCnA in each timer
//    TIMSK0 = (_BV(OCIE0A));
   // TIMSK1 = (_BV(OCIE1A));
   // TIMSK3 = (_BV(OCIE3A));
   // TIMSK4 = (_BV(OCIE4A));
   // TIMSK5 = (_BV(OCIE5A));
}

void timer_enable(uint8_t timer) {
    switch (timer) {
        case 1:
    //        TIMSK1 |= (_BV(OCIE1A));
            break;
        case 3:
            TIMSK3 |= (_BV(OCIE3A));
            break;
        case 4:
     //       TIMSK4 |= (_BV(OCIE4A));
            break;
        case 5:
     //       TIMSK5 |= (_BV(OCIE5A));
            break;
        default:
            break;
    }
}

void timer_disable(uint8_t timer) {
    switch (timer) {
        case 1:
      //      TIMSK1 &= ~(_BV(OCIE1A));
            break;
        case 3:
            TIMSK3 &= ~(_BV(OCIE3A));
            break;
        case 4:
       //     TIMSK4 &= ~(_BV(OCIE4A));
            break;
        case 5:
        //    TIMSK5 &= ~(_BV(OCIE5A));
            break;
        default:
            break;
    }

}

void timer_set_freq(uint8_t timer, uint32_t freq) {
    uint16_t count = F_CPU / (2 * freq);
    timer_set_count(timer, count);
}

/*
 * Sets specified timer output compare register to specified count
 */
void timer_set_count(uint8_t timer, uint16_t count) {
    // For some reason, OCR must be > 40
    //if (count <= 40) {
    //    count = 41;
    //}
    switch(timer) {
        // Timer 0
        case 0:
 //           if (count > 0xFF) {
 //               count = 0xFF;
 //           }
 //           OCR0A = count;
            break;
        // Timer 1
        case 1:
         //   OCR1A = count;
            break;
        // Timer 3
        case 3:
            OCR3A = count;
            break;
        // Timer 4
        case 4:
         //   OCR4A = count;
            break;
        // Timer 5
        case 5:
          //  OCR5A = count;
            break;
        default:
            break;
    }
}

/*
 *  Set duty cycle (0-100) on specified timer
 */
void timer_set_pwm_duty(uint8_t timer, uint8_t duty_cycle) {

}

