#include <stdio.h>
int resolver_matriz_2x2(float* x,float* y ,float a,float b,float c,float d,float e,float f);

int main(){

    float a = 0.0;
    float b = 2.0;
    float c = 3.0;
    float d = 1.0;
    float e=0.0;
    float f=4.0;

    float x=2;
    float y=2;
        
    a = resolver_matriz_2x2(&x,&y,a,b,c,d,e,f);

    printf("Resultado: %f\nx=%.2f\ny=%.2f\n",a,x,y);
}