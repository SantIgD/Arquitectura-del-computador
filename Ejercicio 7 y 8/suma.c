#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <math.h>

float a[]={1.3,2.5,3.5,4.1,0.1};
float b[]={1.3,2.0,3.5,4.0,0.34};     
int len=5;

int longitud = 1000000;


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

void generar_arreglo(float* arreglo){

     for(int i=0;i<longitud;i++){
        arreglo[i]=1.0;
     }
}


int main(){
    

    //Ejercicio 7----------------------------------------------

    printf("\nEl resultado de sumar los flotantes:\n\n  ");

    print_arreglo(a,'a');

    printf("+\n  ");

    print_arreglo(b,'b');

    printf("----------------------------------\n  ");

    sum_simd(a,b,len);
    
    print_arreglo(a,'a');

    //----------------------------------------------------------

    //Ejercicio 8-----------------------------------------------

    float d[longitud];
    float e[longitud];

    struct timespec tiSum,tfSum,tiSumSimd,tfSumSimd;
    generar_arreglo(d);
    generar_arreglo(e);

    clock_gettime(CLOCK_REALTIME, &tiSum);
    sum(d,e,longitud);
    clock_gettime(CLOCK_REALTIME, &tfSum);

    generar_arreglo(d);

    clock_gettime(CLOCK_REALTIME, &tiSumSimd);
    sum_simd(d,e,longitud);
    clock_gettime(CLOCK_REALTIME, &tfSumSimd);



    double  tiempoSum = ( tfSum.tv_sec - tiSum.tv_sec )
                + ( tfSum.tv_nsec - tiSum.tv_nsec ) * pow(10,-9);

    double  tiempoSumSimd = ( tfSumSimd.tv_sec - tiSumSimd.tv_sec )
                + ( tfSumSimd.tv_nsec - tiSumSimd.tv_nsec ) * pow(10,-9);
    
    printf("\n\nEl proceso tardo:\n [sum]: %.9f segundos\n [sumSimd]: %.9f segundos\n\n"
    ,tiempoSum,tiempoSumSimd);
   
    return 0;
}
