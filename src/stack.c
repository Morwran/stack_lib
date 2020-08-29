/*
  **********************************************************************************************************
  * @file   : stack.c
  * @brief  : Library containing functions for working with STACK.
  * This library has been successfully tested on x86 PC and MCU boards such as STM32 (Cortex M3 and M7 core)
  * and Xilinx Spartan6 (Microblaze core).
  **********************************************************************************************************
 *  Created on: 29.08.2020
 *      Author: kvb
 *      mail: mat3x@mail.ru
 */

#include "stack.h"
#include "string.h"
#include "stdlib.h"

/**
  * @brief STACK structure initialization
  * @param stack_t * buf - Pointer to the FIFO structure.
  * @param uint16_t num_blocks - number of data blocks
  * @param uint16_t block_size - size of one data block
  * @retval _Bool - True/False (1,0). True if STACK initialization was successful.
  */
_Bool stack_init(stack_t * buf, uint16_t num_blocks, uint8_t block_size)
{

	uint16_t full_size = (num_blocks*block_size);

	if(!full_size)
		return 0;

	buf->head =NULL;
	if(!(buf->head = (uint8_t*)malloc(full_size))){
		return 0;
	}

	buf->sp = 0;

	buf->block_size = block_size;
	buf->full_size = full_size;

	return 1;
}


/**
  * @brief Push one block of data into STACK
  * @param stack_t * buf - Pointer to the STACK structure.
  * @param void* data - Pointer to input data
  * @retval None.
  */
void stack_push(stack_t * buf, void* data)
{

	memcpy(&buf->head[buf->sp],data,buf->block_size);
	buf->sp+=buf->block_size;

}

/**
  * @brief Pop one block of data from STACK
  * @param stack_t * buf - Pointer to the STACK structure.
  * @param void* data - Pointer to output data
  * @retval None.
  */
void stack_pop(stack_t * buf,void* data)
{
	buf->sp-=buf->block_size;
	memcpy(data,&buf->head[buf->sp],buf->block_size);


}
/**
  * @brief Clear STACK memory
  * @param stack_t * buf - Pointer to the STACK structure.
  * @retval None.
  */
void stack_clr(stack_t * buf)
{
	free(buf->head);
	buf->sp = 0;
	buf->full_size = 0;
}

/**
  * @brief Checking if STACK is empty or not
  * @param stack_t * buf - Pointer to the STACK structure.
  * @retval _Bool - True/False (1,0). True if STACK is empty.
  */
_Bool stack_isEmpty(stack_t * buf)
{
	if(!buf->sp)
		return 1;

	return 0;
}

uint16_t stack_cnt(stack_t * buf)
{

	return (buf->sp/buf->block_size);
}

/**
  * @brief Checking if STACK is full or not
  * @param stack_t * buf - Pointer to the STACK structure.
  * @retval _Bool - True/False (1,0). True if STACK is full.
  */
_Bool stack_isFull(stack_t * buf)
{


	if(buf->sp==buf->full_size || (buf->full_size-buf->sp)<buf->block_size)
		return 1;

	return 0;
}
