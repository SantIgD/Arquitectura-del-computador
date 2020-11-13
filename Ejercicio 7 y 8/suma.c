#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <math.h>

float a[]={1.3,2.5,3.5,4.1,0.1};
float b[]={1.3,2.0,3.5,4.0,0.34};     
int len=5;


void sum(float* a, float* b,int len);

void sum_simd(float* a, float* b,int len);

int main(){
    
    struct timespec start,finish;
    int i;

    

    printf("El resultado de sumar los flotantes:\n\n  a={");

    for(i=0;i<(len-1);i++){
         printf("%.2f,",a[i]);
    }
    printf("%.2f",a[(len-1)]);

    printf("}\n+\n  b={");

    for(i=0;i<(len-1);i++){
         printf("%.2f,",b[i]);
    }
    printf("%.2f",b[(len-1)]);

    printf("}\n------------------------------------\n  a={");

    clock_gettime(CLOCK_REALTIME, &start);
    sum_simd(a,b,len);
    clock_gettime(CLOCK_REALTIME, &finish);

    for(i=0;i<(len-1);i++){

         printf("%.2f,",a[i]);
    }
    printf("%.2f",a[(len-1)]);
    printf("}\n\n");

    double  accum = ( finish.tv_sec - start.tv_sec )
                + ( finish.tv_nsec - start.tv_nsec ) * pow(10,-9);
    
    printf("El proceso tardo %.9f segs\n",accum);
   
    return 0;
}


    /*
   
    */
