
//  * This file is part of the Tinymovr-Firmware distribution
//  * (https://github.com/yconst/tinymovr-firmware).
//  * Copyright (c) 2020 Ioannis Chatzikonstantinou.
//  * 
//  * This program is free software: you can redistribute it and/or modify  
//  * it under the terms of the GNU General Public License as published by  
//  * the Free Software Foundation, version 3.
//  *
//  * This program is distributed in the hope that it will be useful, but 
//  * WITHOUT ANY WARRANTY; without even the implied warranty of 
//  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
//  * General Public License for more details.
//  *
//  * You should have received a copy of the GNU General Public License 
//  * along with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef MOTOR_MOTOR_H_
#define MOTOR_MOTOR_H_

#define MIN_PHASE_RESISTANCE ( 0.005f )
#define MAX_PHASE_RESISTANCE ( 1.0f )

#define MIN_PHASE_INDUCTANCE ( 2e-6f )
#define MAX_PHASE_INDUCTANCE ( 5000e-6f )

#include "src/common.h"

typedef enum {
    MOTOR_ERR_NO_ERROR        					   = 0x0000,
    MOTOR_ERR_PHASE_RESISTANCE_OUT_OF_RANGE        = 0x0001,
	MOTOR_ERR_PHASE_INDUCTANCE_OUT_OF_RANGE        = 0x0002,
	MOTOR_ERR_INVALID_POLE_PAIRS	               = 0x0004
} MotorError;

struct MotorConfig
{
	uint8_t pole_pairs;
	float phase_resistance;
	float phase_inductance;

	bool resistance_calibrated;
	bool inductance_calibrated;
	bool poles_calibrated;

	bool phases_swapped;
	bool is_gimbal;
};

void Motor_Init(void);

PAC5XXX_RAMFUNC uint8_t Motor_GetPolePairs(void);
PAC5XXX_RAMFUNC uint8_t Motor_FindPolePairs(uint16_t ticks, float start_ticks, float end_ticks, float e_angle);
PAC5XXX_RAMFUNC void Motor_SetPolePairs(uint8_t pairs);

PAC5XXX_RAMFUNC float Motor_GetPhaseResistance(void);
PAC5XXX_RAMFUNC void Motor_SetPhaseResistance(float R);

PAC5XXX_RAMFUNC float Motor_GetPhaseInductance(void);
PAC5XXX_RAMFUNC void Motor_SetPhaseInductance(float L);

PAC5XXX_RAMFUNC bool motor_phases_swapped(void);
PAC5XXX_RAMFUNC void motor_set_phases_swapped(bool swapped);

PAC5XXX_RAMFUNC bool motor_is_calibrated(void);

PAC5XXX_RAMFUNC bool motor_is_gimbal(void);
PAC5XXX_RAMFUNC void motor_set_is_gimbal(bool gimbal);

struct MotorConfig* Motor_GetConfig(void);
void Motor_RestoreConfig(struct MotorConfig* config_);

#endif /* MOTOR_MOTOR_H_ */
