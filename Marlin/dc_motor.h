/****************************************************************************
 *  dc_motor.h
 *
 *  Header file for dc_motor.cpp
 *
 *  Author: Ricky Rininger
 *  Date:   5 Dec, 2017
 *
 ***************************************************************************/

#include <avr/io.h>

#ifndef DC_MOTOR_H
#define DC_MOTOR_H

//===========================================================================
// Pin Definitions
//===========================================================================

// Constant Definitions

// Port Definitions
#define DC_MOTOR_DIR_PORT               (PORTG)
#define DC_MOTOR_PWM_PORT               (PORTG)
#define DC_MOTOR_EN_PORT                (PORTJ)
#define DC_MOTOR_FLT_PORT               (PORTJ)
#define DC_MOTOR_CS_PORT                (PORTF)

// DDR Definitions
#define DC_MOTOR_DIR_DDR                (DDRG)
#define DC_MOTOR_PWM_DDR                (DDRG)
#define DC_MOTOR_EN_DDR                 (DDRJ)
#define DC_MOTOR_FLT_DDR                (DDRJ)
#define DC_MOTOR_CS_DDR                 (DDRF)

// Pin Definitions
#define DC_MOTOR_DIR                    (1 << 4)
#define DC_MOTOR_PWM                    (1 << 3)
#define DC_MOTOR_EN                     (1 << 2)
#define DC_MOTOR_FLT                    (1 << 3)
#define DC_MOTOR_CS                     (1 << 3)

//===========================================================================
// Function Prototypes
//===========================================================================


#endif // SOLENOIDS_H

