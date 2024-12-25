#ifndef TESTS_H
#define TESTS_H

#include "stdio.h"
#include "stdlib.h" 
#include "CPU.h"
#include <assert.h>



/* TEST DEFINITIONS*/

// TYPEDEF INT TESTS
#define uint8SIZE  1
#define uint16SIZE 2
#define uint32SIZE 4

void TYPEDEF_BASE_TEST (int aSize , int exSize){
	   if( aSize != exSize  ){ 
              
	       printf("[!] TEST TYPEDEF_TEST NOT THE CORRECT SIZE failed \n"); 
               exit(-1);  
	       } 

	}


void UINT8_TEST() { TYPEDEF_BASE_TEST(sizeof(uint8)  ,uint8SIZE);}


void UINT16_TEST() {  TYPEDEF_BASE_TEST(sizeof(uint16) ,uint16SIZE);}

void UINT32_TEST() {  TYPEDEF_BASE_TEST( sizeof(uint32),uint32SIZE);}

void TYPEDEF_TEST(){ 
 UINT8_TEST();
 UINT16_TEST();
 UINT32_TEST();
 printf("[+] TYPEDEF TESTS SUCCSESSFULLY\n");
}


/* instruction tests  */

void add_TEST(){
 CPU cpu;
 RAM ram;
 uint16 instr, retValue, r1v,r2v,expectedValue;
 instr=retValue=0;
 r1v = 10;
 r2v = 20;
 expectedValue = r1v + r2v;
 
 cpu.init(&ram);
 
 // lets create an instruction that should be evaluated some of this test code might change
 /*
 OPCODE: 0001
 DR: 0 -> RD_0
 SR1: R_3
 SR2: R_2
 */
// instruction not in intermediate mode
 instr = (OP_ADD<<12) | (R_R0 << 9) | (R_R2 << 6) | (R_R3 << 0);
 // emulate values in the following registers
 cpu.setReg(R_R2, r1v);
 cpu.setReg(R_R3, r2v);

 cpu.ADD(&instr);

 retValue = cpu.getReg(R_R0);
 
 assert(retValue == expectedValue);
 printf("[+] ADD_INSTR test succsessfull!\n");


 // TODO test intermediate mode
 
}


#endif 
