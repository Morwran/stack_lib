/*
  ******************************************************************************
  * @file           : main.c
  * @brief         Testing of STACK
  ******************************************************************************
 *  Created on: 29.08.2020
 *      Author: kvb
 *      mail: mat3x@mail.ru
 */

#include "stack.h"
#include "stdio.h"

/** @brief Testing structure*/
typedef struct{
	float ch11;
	float ch12;
	float ch21;
	float ch22;

}adc_smpl_t;

/** @brief Structure of STACK*/
stack_t stack;

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void){

	adc_smpl_t Din[4]={\
			{1,2,3,4},\
			{5,6,7,8},\
			{9,10,11,12},\
			{13,14,15,16},\
	};


	for(uint8_t i=0;i<sizeof(Din)/sizeof(adc_smpl_t);i++)
		printf("Data for testing: N%u: %f %f %f %f\n",i,Din[i].ch11,Din[i].ch12,Din[i].ch21,Din[i].ch22);

	if(!(stack_init(&stack, 4, sizeof(adc_smpl_t)))){
		printf("mem err\n");
		return 0;
	}

	printf("stack st start: wr %u e: %u f: %u\n",stack.sp,stack_isEmpty(&stack),stack_isFull(&stack));

	for(uint8_t j=0;j<3;j++){
		for(uint8_t i=0;i<4;i++){
			if(!stack_isFull(&stack))
				stack_push(&stack,(void*)&Din[i]);

			printf("fifo wr%u: sp: %u fs: %u e: %u f: %u\n",i,stack.sp,stack.full_size,\
					stack_isEmpty(&stack),stack_isFull(&stack));

		}

		adc_smpl_t d;

		while(!stack_isEmpty(&stack)){
			stack_pop(&stack,(void*)&d);

			printf("st stack rd: %u e: %u f: %u\n",stack.sp,stack_isEmpty(&stack),stack_isFull(&stack));

			printf("Data reading from STACK: %f %f %f %f\n",d.ch11,d.ch12,d.ch21,d.ch22);
		}


		printf("=====================================================\n");
	}

	printf("Test passed!\n");

	stack_clr(&stack);

	return 0;
}
