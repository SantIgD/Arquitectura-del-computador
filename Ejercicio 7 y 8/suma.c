#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
float a[]={1.3,2.5,3.5,4.1,0.1};
float b[]={1.3,2.0,3.5,4.0,0.34};     
int len=5;


void sum(float* a, float* b,int len);

void sum_simd(float* a, float* b,int len);

void print_arreglo(float* arreglo,char c){

     int i;
     printf("%c={",c);

     for(i=0;i<(len-1);i++){
         printf("%.2f,",arreglo[i]);
    }
    printf("%.2f",arreglo[(len-1)]);

    printf("}\n");

}

void generar_arreglo(float* arreglo,int longitud){

     for(int i=0;i<longitud;i++){
        arreglo[i]=1.0;
     }
}


int main(){
    char c;

    //Ejercicio 7----------------------------------------------

    printf("\nEl resultado de sumar los flotantes 1 a 1:\n\n  ");

    print_arreglo(a,'a');

    printf("+\n  ");

    print_arreglo(b,'b');

    printf("----------------------------------\n  ");

    sum(a,b,len);
    
    print_arreglo(a,'a');

    printf("\nIngrese una tecla para continuar \n");
    
    c = getchar();

    printf("\nEl resultado de sumar los flotantes de a 4:\n\n  ");

    print_arreglo(a,'a');

    printf("+\n  ");

    print_arreglo(b,'b');

    printf("----------------------------------\n  ");

    sum_simd(a,b,len);
    
    print_arreglo(a,'a');
    
    printf("\nIngrese una tecla para continuar \n");
    c = getchar();
    c = getchar();
    //----------------------------------------------------------

    //Ejercicio 8-----------------------------------------------

    int longitud = 200000000;
    printf("Comparacion en tiempo de calculo de la suma de arreglos de flotantes packed y 1 a 1 con arreglos de longitud %d\n",longitud);
    float *memA = malloc(longitud * sizeof(float)+15);
    unsigned long d1 = ((unsigned long) (memA)+15) & (~ 0x0F);  // pongo en 0 los primeros 4 bits
    float* d = (float *)d1;

    float *memB = malloc(longitud * sizeof(float)+15);
    unsigned long e1 = ((unsigned long) (memB)+15) & (~ 0x0F);  // pongo en 0 los primeros 4 bits
    float* e = (float *)e1;
    

    

    struct timespec tiSum,tfSum,tiSumSimd,tfSumSimd;
    double  tiempoSum=0;
    double tiempoSumSimd=0; 

      generar_arreglo(d,longitud);
      generar_arreglo(e,longitud);

      clock_gettime(CLOCK_REALTIME, &tiSum);
      sum(d,e,longitud);
      clock_gettime(CLOCK_REALTIME, &tfSum);

      generar_arreglo(d,longitud);

      clock_gettime(CLOCK_REALTIME, &tiSumSimd);
      sum_simd(d,e,longitud);
      clock_gettime(CLOCK_REALTIME, &tfSumSimd);

      tiempoSum += ( tfSum.tv_sec - tiSum.tv_sec )
                + ( tfSum.tv_nsec - tiSum.tv_nsec ) * pow(10,-9);

      tiempoSumSimd += ( tfSumSimd.tv_sec - tiSumSimd.tv_sec )
                + ( tfSumSimd.tv_nsec - tiSumSimd.tv_nsec ) * pow(10,-9);
    
    free(memA);
    free(memB);

    
    printf("\n\nEl proceso tardo:\n [sum]: %.9f segundos\n [sumSimd]: %.9f segundos\n\n"
    ,tiempoSum,tiempoSumSimd);
    return 0;
}
