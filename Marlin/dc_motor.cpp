/****************************************************************************
 *  dc_motor.cpp
 *
 *  Source file for dc motor control
 *
 *  Author: Ricky Rininger
 *  Date:   5 Dec, 2017
 *
 ***************************************************************************/

#include "dc_motor.h"

//===========================================================================
//  Functions
//===========================================================================

/*
 *  Initialize DC motor control
 */
void dc_motor_init(void) {
    // Set output levels
    DC_MOTOR_DIR_PORT |= DC_MOTOR_DIR;
    DC_MOTOR_PWM_PORT &= ~DC_MOTOR_PWM;
    DC_MOTOR_EN_PORT &= ~DC_MOTOR_EN;

    // Set pin directions (outputs)
    DC_MOTOR_DIR_DDR |= DC_MOTOR_DIR;
    DC_MOTOR_PWM_DDR |= DC_MOTOR_PWM;
    DC_MOTOR_EN_DDR |= DC_MOTOR_EN;

    // Set pin directions (inputs)
    DC_MOTOR_FLT_DDR &= ~DC_MOTOR_FLT;
    DC_MOTOR_CS_DDR &= ~DC_MOTOR_CS;

    timers_init();

}

/*
 *  Enable DC motor
 */
void dc_motor_enable(void) {
    DC_MOTOR_EN_PORT |= DC_MOTOR_EN;
}

/*
 *  Disable DC motor
 */
void dc_motor_disable(void) {
    DC_MOTOR_EN_PORT &= ~DC_MOTOR_EN;
}

/*
 *  Set PWM duty cycle
 */
void dc_motor_set_pwm_duty(uint8_t duty_cycle) {
    timer_set_pwm_duty(DC_MOTOR_TIMER, duty_cycle);
}

