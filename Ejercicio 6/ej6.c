#include <stdio.h>
#include "tests.c"
#include <stdlib.h>

int solve( float *x, float *y,float a, float b, float c, float d, float e, float f);

int main(){
   int a;

   printf("Si desea ejecutar los test ingrese 1, sino cualquier tecla...");
   scanf("%d",&a);

   if(a==1){

      if(testear()==0){
       // Funciona con los casos probados
       system("clear");
       printf("El programa funciona correctamente con los casos previstos\n");
      }else{
       printf("\nEl programa no funciona correctamente con los casos previstos\n");
       return -1;
      }
   }

    return 0;     
}




