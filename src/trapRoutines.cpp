#include "trapRoutines.h"

/* here will be the trap routines for our cpu just beeing implemented so its a bit more diverse*/

/* trap routine that puts a new  NOTE: i think this here is wrong might need to fix it*/
void CPU::TRAP_puts(void)
{
    uint16* c = reg[R_PC] + ram->memory;

    while (*c)
    {
        putc((char)*c, stdout);
        ++c;
    }
    fflush(stdout);
}

/* load a single char into the r0 register from stdin*/
void CPU::TRAP_getc(void)
{

    this->reg[R_R0] = (uint16)getchar();

    updateFlag(R_R0);
}

void CPU::TRAP_out(void)
{

    putc((char)reg[R_R0], stdout);
    fflush(stdout);
}

void CPU::TRAP_in(void)
{
    printf("Enter a character: ");
    char c = getchar();
    putc(c, stdout);
    fflush(stdout);
    reg[R_R0] = (uint16)c;

    updateFlag(R_R0);
}

void CPU::TRAP_putsP(void)
{
   
    uint16 *c = reg[R_PC] + ram->memory;
   
    while (*c)
    {
        char char1 = *c & 0xFF;

        putc(char1, stdout);

        char1 = *c >> 8;

        if (char1)
        {
            putc(char1, stdout);
        }

        ++c;
    }
    fflush(stdout);
}

void CPU::TRAP_halt(void)
{

    puts("HALT");
    fflush(stdout);
    running = 0;
}