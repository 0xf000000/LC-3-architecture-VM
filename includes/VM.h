#ifndef VM_H
#define VM_H

/* typedefinitions*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;


/* headers*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* constant preprocessor definitions*/
#define MEMORY_MAX (1 << 16)

/* structs*/

/**
 * @brief 
 * defines the ram layout in memory
 */
struct RAM{

uint16 memory[MEMORY_MAX];

};


/* enums*/

enum REGISTERS{
  
  R_R0 = 0,
  R_R1,
  R_R2,
  R_R3,
  R_R4,
  R_R5,
  R_R6,
  R_R7,
  R_PC,
  R_COND,
  R_COUNT
  
  };


enum CONDITION_FLAGS{

	FL_POS = 1 << 0, /* P */
	FL_ZRO = 1 << 1, /* Z */
	FL_NEG = 1 << 2, /* N */

};

/* PC starting position*/
enum{ PC_START= 0x3000 };

/* TRAP routines*/



#endif
