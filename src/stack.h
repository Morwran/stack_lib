/*
 * stack.h
 *
 *  Created on: 29.08.2020
 *      Author: kvb
 */

#ifndef STACK_H_
#define STACK_H_

#include "stdint.h"

/** @brief Structure of STACK*/
typedef struct{
	uint8_t *head; //pointer to memory
	uint16_t sp; //stack pointer
	uint16_t full_size;
	uint16_t block_size;
}stack_t;

_Bool stack_init(stack_t * buf, uint16_t num_blocks, uint8_t block_size);
void stack_push(stack_t * buf, void* data);
void stack_pop(stack_t * buf,void* data);
void stack_clr(stack_t * buf);
_Bool stack_isEmpty(stack_t * buf);
_Bool stack_isFull(stack_t * buf);

#endif /* STACK_H_ */
