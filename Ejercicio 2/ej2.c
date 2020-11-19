#include <stdio.h>
#include <math.h>

#define EXP(X) ((*(int *) (&X) >> 23) & 0xff)

#define FRACCION(Y)  ((*(int *) (&Y)) & 0x7fffff)

int my_isnan(float n){

    if(EXP(n)==255 && FRACCION(n) != 0){
        return 1;
    }else{
        return 0;
    }
    
}

int my_isnan2(float n){

    if(n == n){
        return 0;
    }else{
        return 1;
    }
    
}


int main(void){
    
    float g = 0.0;
    float f = 0.0 / g;
    float b = 3.0/g;
    printf("f: %f\n", f);
    // ADVERTENCIA: ‘NAN’ es una extensi´on de GCC.
    if (f == NAN) {
    printf("Es NAN\n");
    }
    if (isnan(f) && my_isnan2(f) && my_isnan(f)) {
        printf("isNaN/my_isnan/my_isnan2 dicen que si\n");
        }

    if (b == INFINITY){
        printf("Es infinito\n\n");  // Entra aqui, por lo tanto no ocurre lo mismo
    }

    printf("Calculando con infinitos\n\nInfinito + 0 = %f\n",b+g);
    printf("Infinito - 10.0 = %f\n",b+(-10.0)); // Sumar un numero positivo/negativo a +infinito 
    printf("0 - Infinito = %f\n",-b+g);         // devuelve +infinito
    printf("100 - Infinito = %f\n",-b+100.0);

    if ((g-b) == -INFINITY){
        printf("\nEs menos infinito\n\n");  // Entra aqui, por lo tanto no ocurre lo mismo
    }

    return 0;
}
