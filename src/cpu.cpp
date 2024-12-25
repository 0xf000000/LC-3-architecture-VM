#include "bitutil.h"
#include "CPU.h"
#include "trapRoutines.h"

void CPU::init(struct RAM *ram)
{
  // do we even need to check for 0 its on the stack idk..
  if (ram == NULL)
  {
    printf("[-] ram pointer is NULL cannot operate without ram\n");
    exit(EXIT_FAILURE);
  }

  this->ram = ram;

  cleanUp();
}

void CPU::cleanUp(){
  if( ram == nullptr){
    printf("[!] tried to cleanup ram without passing a existing ram struct! abort ...");
    exit(EXIT_FAILURE);
  }
  
  // cleaning ram 
  for(int i = 0; i < MEMORY_MAX; i++){
    this->ram->memory[i] = 0;
  }

  // clearing registers
  for(int j = 0; j < R_COUNT; j++){
    this->ram->memory[j] = 0;
  }

}

// stops execution
void CPU::abort()
{

  cleanUp();

  running = 0;
}

void CPU::run()
{

  /* set Z flag at the start*/
  this->reg[R_COND] = FL_ZRO;

  this->reg[R_PC] = PC_START;

  running = 1;

  /* executing loop basically here there getting all exec*/
  while (running)
  {

    uint16 instr = fetch();

    uint16 op = instr >> 12;
    switch (op)
    {

    case OP_ADD:
      ADD(&instr);
      break;
    case OP_AND:
      AND(&instr);
      break;
    case OP_NOT:
      NOT(&instr);
      break;
    case OP_BR:
      BR(&instr);
      break;
    case OP_JMP:
      JMP(&instr);
      break;
    case OP_JSR:
     JSRR(&instr);
      break;
    case OP_LD:
      LD(&instr);
      break;

    case OP_LDI:
      LDI(&instr);
      break;

    case OP_LDR:
      LDR(&instr);
      break;
    case OP_LEA:
      LEA(&instr);
      break;

    case OP_ST:
       ST(&instr);
      break;

    case OP_STI:
      STI(&instr);
      break;

    case OP_STR:
      STR(&instr);
      break;
    case OP_TRAP:
      trap_routines(&instr);
      break;

    case OP_RES:
    case OP_RTI:

    default:
      abort();
      // BAD OPCODE

      break;
    }
  }
}

/** were just doin the traps inside here think thats a bit more covered now */
void CPU::trap_routines(uint16* instr){
    reg[R_R7] = reg[R_PC];

    switch( *instr & 0xFF){
      
      case TRAP_GETC:
        TRAP_getc();
        break;

      
      case TRAP_OUT:
        TRAP_out();
        break;
      

      case TRAP_PUTS:
        TRAP_puts();
        break;

      
      case TRAP_IN:
        TRAP_in();
        break;
      
      case TRAP_PUTSP:
        TRAP_putsP();
        break;
      

      case TRAP_HALT:
        TRAP_halt();
        break;
      

      
    }
}

/*fetches from the programm*/
uint16 CPU::fetch()
{

  uint16 instr = mem_read(reg[R_PC]++);

  return instr;
}
/** setter for tests... */
void CPU::setReg(uint16 dr, uint16 value)
{
  if (dr > R_COUNT )
  {
    // no
    return;
  }
  

  this->reg[dr] = value;
}

/* gets the value of the current register.
  to abort just because dr parameter value seems overkill but i wanna catch bugs as fast as i can so maby im doing something funky w that shit soo yeah
*/
uint16 CPU::getReg(uint16 dr)
{
  uint16 regValue;
  
  if(dr > R_COUNT){
    printf("[!] getter tried to accsess non existent register value abort ...\n");
    exit(-1);
  }

  regValue = this->reg[dr];

  return regValue;
}

// TODO
uint16 CPU::mem_read(uint16 address)
{

  return 0;
}

 uint16 CPU::mem_write(uint16 src, uint16 dest){
  
  return 0;
 }

void CPU::updateFlag(uint16 r)
{

  if (reg[r] == 0)
  {
    this->reg[R_COND] = FL_ZRO;
  }
  else if (reg[r] >> 15)
  {

    this->reg[R_COND] = FL_NEG;
  }
  else
  {

    this->reg[R_COND] = FL_POS;
  }
}
