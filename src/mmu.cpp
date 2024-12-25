#include "mmu.h"


/* implementations for the memory management unit... i programmed to mutch java in my live so i kinda do that rn again*/
mmu::mmu(struct RAM *ram)
{
    if (!ram)
    {
        printf("[-] mmu: pointer to ram struct is null\n");
        exit(EXIT_FAILURE);
    }

    this->ram = ram;
}

