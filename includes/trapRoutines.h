#ifndef TRAP_ROUTINES_H
#define TRAP_ROUTINES_H

#include "CPU.h"
#include "VM.h"
#include "bitutil.h"
#include <stdio.h>


/* trap routines*/
enum{

  TRAP_GETC = 0x20,  /* get character from keyboard, not echoed onto the terminal */
    TRAP_OUT = 0x21,   /* output a character */
    TRAP_PUTS = 0x22,  /* output a word string */
    TRAP_IN = 0x23,    /* get character from keyboard, echoed onto the terminal */
    TRAP_PUTSP = 0x24, /* output a byte string */
    TRAP_HALT = 0x25   /* halt the program */


};







#endif