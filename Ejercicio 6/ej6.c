#include <stdio.h>
int resolver_matriz_2x2(float* x,float* y ,float a,float b,float c,float d,float e,float f);

int main(){
    float a = 1.0/0;
    float b = a*0;
    float c = 1.0/0;
    float d = 1.0/0;
    float e=1;
    float f=1;

    float* x;
    float* y;
    
    a = resolver_matriz_2x2(x,y,a,b,c,d,e,f);

    printf("%f\n",a);
}