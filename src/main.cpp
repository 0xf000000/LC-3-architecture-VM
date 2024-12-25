#include "VM.h"
#include "test.h"
#include "CPU.h"
#include "bitutil.h"

/* reads the ldc9 image into our cpu TODO*/
static bool read_image(const char* path){ return true; }



static void read_image_file(FILE* file, struct RAM* ram){
// first 16 bits of file specify where programm should start
uint16 origin = 0;
fread(&origin,sizeof(origin), 1, file);

origin = bitUtils::swap16(origin);

uint16 max_read = MEMORY_MAX - origin;

uint16* memPointer = ram->memory + origin;




}

int main(int argc, char** argv){
CPU cpu;
RAM ram;

TYPEDEF_TEST();
add_TEST();

if(argc < 2){
printf("usage: VM [image-file1] ...\n");

exit(2);
}


for(int j = 1; j < argc; j++){


if(!read_image(  argv[j])){

  printf("[-] failed to load image: %s\n", argv[j]);
  exit(1);
}

}



}

