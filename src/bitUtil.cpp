#include "bitutil.h"


namespace bitUtils{
/**
 * @brief if were going to have a negative number that isnt extended up to 16 bits we will just extend the signs
 * 
 * @param x 
 * @param size 
 * @return uint16 
 */
uint16 sign_extend(uint16 x, uint8 size){

   if( (x >> (size -1)) & 1 ){
    x |= (0xFFFF << size);
   }


    return x;
}

/**
 * @brief basically big endian to little endian only for uin16 (word)
 * 
 * @param x 
 * @return uint16 
 */
uint16 swap16(uint16 x){

    return (x<<8) | (x>> 8);
}

}