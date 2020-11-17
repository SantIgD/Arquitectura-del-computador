#include <stdio.h>
#include "tests.c"
#include <stdlib.h>

int resolver_matriz_2x2(float* x,float* y ,float a,float b,float c,float d,float e,float f);


int main(){
    int a;

   if(testear()==0){
       // Funciona con los casos probados
       system("clear");
       printf("El programa funciona con los casos previstos\n");
   }else{
       printf("\nEl programa no funciona con los casos previstos\n");
       return -1;
   }


    return 0;


        
}




