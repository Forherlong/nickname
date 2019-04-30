#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mersenne_twister.h"

/**
 * @param out 
 * @param outLength
 * @return code
 */
int mersenneTwisterRandom(char *randomResult, int randomResultLength) {
    int retArrayLen = strlen(randomResult);
    if(retArrayLen < randomResultLength) {
        return 1;
    }

    for(int loop =0; loop < randomResultLength; ++loop) {
        
    }

}