/*
 * dshot.h
 *
 *  Created on: Jan 28, 2026
 *      Author: Bacnk
 */

#ifndef SRC_DSHOT_H_
#define SRC_DSHOT_H_
#include <stdbool.h>
#include <math.h>		// lrintf
#include "tim.h"
#define TIMER_CLOCK				840000000

typedef struct
{
    TIM_HandleTypeDef *htim;
    uint32_t channel;
} Motor_t;
/* Definition */
#define MHZ_TO_HZ(x) 			((x) * 1000000)
#define DSHOT600_HZ     		MHZ_TO_HZ(12)
#define DSHOT300_HZ     		MHZ_TO_HZ(6)
#define DSHOT150_HZ     		MHZ_TO_HZ(3)
#define MOTOR_BIT_0            	7
#define MOTOR_BIT_1            	14
#define MOTOR_BITLENGTH        	20

#define DSHOT_FRAME_SIZE       	16
#define DSHOT_DMA_BUFFER_SIZE   18 /* resolution + frame reset (2us) */

#define DSHOT_MIN_THROTTLE      48
#define DSHOT_MAX_THROTTLE     	2047
#define DSHOT_RANGE 			(DSHOT_MAX_THROTTLE - DSHOT_MIN_THROTTLE)
/* Enumeration */
typedef enum
{
    DSHOT150,
    DSHOT300,
    DSHOT600
} dshot_type_e;
/* Functions */
void dshot_init(dshot_type_e dshot_type);
void dshot_write(uint16_t* motor_value);
#endif /* SRC_DSHOT_H_ */
