#include <stdio.h>
#include "ieee754.h"

#define EXP(X) ((*(int *) (&X) >> 23) & 0xff)

#define FRACCION(Y)  ((*(int *) (&Y)) & 0x7fffff)

int main(){
    float f=0.3;
    union ieee754_float u;
    u.f=f;
    printf("\n[Macro] Exponente de F: %d\n", EXP(f));
    printf("[IEEE754]Exponente de F: %d\n\n",u.ieee.exponent);

    printf("[Macro]Fraccion de F: %d\n", FRACCION(f));    
    printf("[IEEE754]Fraccion de F: %d\n\n", u.ieee.mantissa);
}
