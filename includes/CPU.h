#ifndef CPU_H
#define CPU_H
#include "VM.h"
#include "instructions.h"





class CPU{
    private:    
    /* private methods*/
    uint16 reg[R_COUNT];
    struct RAM* ram = nullptr;
    int running = 0;
    void run();
    uint16 fetch();
    void updateFlag(uint16);
    void cleanUp();

    // memory accsess
    uint16 mem_read(uint16);
    uint16 mem_write(uint16, uint16);

   
    public:
    // fuck i really have implement setters for writing tests...
    void setReg(uint16,uint16);
    uint16 getReg(uint16);
    void init(struct RAM* ram);
    void abort();
    void trap_routines(uint16*);
    /*instructions for now they are private but this will change */

    void ADD(uint16*);
    void LDI(uint16*);
    void AND(uint16*);
    void BR(uint16*);
    void NOT(uint16*);
    void JMP(uint16*);
    void JSRR(uint16*);
    void LD(uint16*);
    void LDR(uint16*);
    void LEA(uint16*);
    void ST(uint16 *);
    void STI(uint16 *);
    void STR(uint16 *);


    /* Tap Routines*/
    void TRAP_getc(void);
    void TRAP_out(void);
    void TRAP_puts(void);
    void TRAP_in(void);
    void TRAP_putsP(void);
    void TRAP_halt(void);

};


#endif