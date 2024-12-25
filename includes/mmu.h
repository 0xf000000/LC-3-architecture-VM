#ifndef MMU_H
#define MMU_H

#include "VM.h"
// defines the mmu responsible for reading and writing to/from the ram
class mmu{

    private:
    struct RAM* ram = nullptr;


    public:
    mmu(struct RAM* ram);

 // memory accsess
    uint16 mem_read(uint16);
    uint16 mem_write(uint16, uint16);

};


#endif 