#include "instructions.h"

/* all instructions we will need*/





/* small abstraction so we have it a bit more organized*/
void CPU::ADD(uint16 *instr)
{
  /* destination register*/
  uint16 dr = (*instr >> 9) & 0x7;

  /*get first opperant*/
  uint16 r1 = (*instr >> 6) & 0x7;

  uint16 immFlag = (*instr >> 5) & 0x1;

  if (immFlag)
  {
    uint16 imm5 = bitUtils::sign_extend(*instr & 0x1F, 5);
    reg[dr] = reg[r1] + imm5;
  }
  else
  {
    uint16 r2 = *instr & 0x7;
    reg[dr] = reg[r1] + reg[r2];
  }

  updateFlag(dr);
}

// load Indirect into a specific register
void CPU::LDI(uint16 *instr)
{
  uint16 dr = (*instr >> 9) & 0x7;

  uint16 pc_offset = bitUtils::sign_extend(*instr & 0x1F, 9);

  this->reg[dr] = mem_read(mem_read(this->reg[R_PC + pc_offset]));
  updateFlag(dr);
}

void CPU::AND(uint16 *instr)
{
  uint16 dr = (*instr >> 9) & 0x7;

  uint16 r1 = (*instr >> 6) & 0x7;

  uint16 mediateFlag = ((*instr >> 5));

  if (mediateFlag & 0x1)
  {
    uint16 imm5 = bitUtils::sign_extend(*instr & 0x1F, 5);

    reg[dr] = reg[r1] & imm5;
  }
  else
  {
    uint16 r2 = *instr & 0x7;
    this->reg[dr] = reg[r1] & reg[r2];
  }
}

void CPU::BR(uint16 *instr)
{
  uint16 pc_offset = bitUtils::sign_extend(*instr & 0x1FF, 9);
  uint16 cond_flag = (*instr >> 9) & 0x7;

  if (cond_flag & reg[R_COND])
  {
    reg[R_PC] += pc_offset;
  }
}

void CPU::NOT(uint16 *instr)
{
  uint16 dr = (*instr >> 9) & 0x7;

  uint16 sr = (*instr >> 6) & 0x7;

  this->reg[dr] = ~reg[sr];

  updateFlag(dr);
}

// jumps to specified addr
void CPU::JMP(uint16 *instr)
{
  uint16 jumpAddr = (*instr >> 6) & 0x7;

  reg[R_PC] = reg[jumpAddr];
}

void CPU::JSRR(uint16 *instr)
{
  uint16 condFlag = (*instr >> 11) & 0x1;
  reg[R_R7] = reg[R_PC];

  if (condFlag)
  {
    uint16 imm1 = bitUtils::sign_extend(*instr & 0x7FF, 11);
    reg[R_PC] += imm1;
  }
  else
  {
    uint16 sr1 = (*instr >> 6) & 0x7;

    reg[R_PC] = sr1;
  }
}
// load shit
void CPU::LD(uint16 *instr)
{
  uint16 dr = (*instr >> 9) & 0x7;

  uint16 pcOffset = bitUtils::sign_extend(*instr & 0x1FF, 9);

  reg[dr] = mem_read(reg[R_PC] + pcOffset);

  updateFlag(dr);
}

void CPU::LDR(uint16 *instr)
{
  uint16 dr = (*instr >> 9) & 0x7;
  uint16 baseReg = (*instr >> 6) & 0x7;
  uint16 offset6 = bitUtils::sign_extend(*instr & 0x3F, 6);

  reg[dr] = mem_read(reg[baseReg] + offset6);
}

/* Load effective address*/
void CPU::LEA(uint16 *instr){
  uint16 r0 = (*instr >> 9 ) & 0x7;
  uint16 pc_offset = bitUtils::sign_extend(*instr & 0x1FF, 9 );

  reg[r0] = reg[R_PC] + pc_offset;
  updateFlag(r0);

} 


//STORE
void CPU::ST(uint16 *addr){
  uint16 r0 = (*addr >> 9 ) & 0x7;
  uint16 pc_offset = bitUtils::sign_extend( *addr & 0x1FF, 9 );

  mem_write(mem_read(reg[R_PC] +  pc_offset), reg[r0]);

}

// store indirect
void CPU::STI(uint16 *addr){
  uint16 r0 = (*addr >> 9) & 0x7;
  
  uint16 pc_offset = bitUtils::sign_extend( *addr & 0x1FF, 9);

  mem_write(mem_read(reg[R_PC] + pc_offset), reg[r0]);
}


void CPU::STR(uint16 *addr){

  uint16 r0 = (*addr >> 9) & 0x7;
  uint16 r1 = (*addr >> 6) & 0x7;

  uint16 offset = bitUtils::sign_extend(*addr & 0x3F, 6);

  mem_write(reg[r1] + offset, reg[r0]);

}



