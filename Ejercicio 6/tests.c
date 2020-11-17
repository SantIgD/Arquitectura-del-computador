#include <stdio.h>
#include "tests.h"
#include <stdlib.h>
#include <unistd.h>

int resolver_matriz_2x2(float* x,float* y ,float a,float b,float c,float d,float e,float f);

int testear_NaN();

int testear_inf();

int testear_casos();


int testear(){
    int a=0;
    int b=0;

    system("clear");
    printf("Verificando NaNs e infinitos...\n");
    
    sleep(1);
    a=testear_NaN();
    sleep(1);
    b=testear_inf();
    sleep(1);

     
     if(a==0 && b==0){

        a=testear_casos();
        system("clear");

        if(a==0){

          printf("Casos verificados correctamente\n\nIngrese una tecla para proseguir con casos particulares \n");
          
          scanf("%d",&a);
          return 0;  
        }
        
    }
    return -1;
}


int testear_NaN(){


    float a = 0.0;
    float b = 2.0;
    float c = 0.0;
    float d = 1.0;
    float e = 3.0;
    float f = 4.0;

    float x;
    float y;

    if (resolver_matriz_2x2(&x,&y,0.0/0.0,b,c,d,e,f) == -1 && resolver_matriz_2x2(&x,&y,a,0.0/0.0,c,d,e,f)== -1
        && resolver_matriz_2x2(&x,&y,a,b,0.0/0.0,d,e,f)== -1 && resolver_matriz_2x2(&x,&y,a,b,c,0.0/0.0,e,f)== -1
        && resolver_matriz_2x2(&x,&y,a,b,c,d,0.0/0.0,f)== -1 && resolver_matriz_2x2(&x,&y,a,b,c,d,e,0.0/0.0)== -1){
        
        printf("El programa filtra las entradas en NaN correctamente\n");
        return 0;
    }else{
        printf("El programa no fiiltra las entradas en NaN correctamente\n");
        return -1;
    }
}


int testear_inf(){


    float a = 0.0;
    float b = 2.0;
    float c = 0.0;
    float d = 1.0;
    float e = 3.0;
    float f = 4.0;

    float x;
    float y;

    if (resolver_matriz_2x2(&x,&y,1.0/0.0,b,c,d,e,f) == -1 && resolver_matriz_2x2(&x,&y,a,-1.0/0.0,c,d,e,f)== -1
        && resolver_matriz_2x2(&x,&y,a,b,1.0/0.0,d,e,f)== -1 && resolver_matriz_2x2(&x,&y,a,b,c,-1.0/0.0,e,f)== -1
        && resolver_matriz_2x2(&x,&y,a,b,c,d,1.0/0.0,f)== -1 && resolver_matriz_2x2(&x,&y,a,b,c,d,e,-1.0/0.0)== -1){
        
        printf("El programa filtra las entradas en inf correctamente.\n");
        return 0;
    }else{
        printf("El programa no filtra las entradas en inf correctamente\n");
        return -1;
    }
}

int testear_casos(){
    system("clear");
    printf("\nTesteando casos...\n");
    sleep(1);
    float a,b,c,d,e,f,x,y;

    a=1.0;
    b=2.0;
    c=3.0;
    d=4.0;
    e=5.0;
    f=6.0;


    printf("\nCaso 1:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%f",&a);
    
    system("clear");
    a = 0.0;
    b = 2.0;
    c = 0.0;
    d = 1.0;
    e = 3.0;
    f = 4.0;
    

    printf("\nCaso 2:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0 && x==4 && y==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    
    system("clear");
    a=4.0;
    b=0.0;
    c=16.0;
    d=1.0;
    e=5.0;
    f=29.0;


    printf("\nCaso 3:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0 && x==4 && y==5){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=3.0;
    b=15.5;
    c=34.0;
    d=0.0;
    e=57.0;
    f=114.0;


    printf("\nCaso 4:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0 && x==1 && y==2){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=4.0;
    b=3.0;
    c=0.0;
    d=7.0;
    e=0.0;
    f=1.0;


    printf("\nCaso 5:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=0.0;
    b=4.0;
    c=32.0;
    d=5.0;
    e=0.0;
    f=45.0;


    printf("\nCaso 6:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=4.0;
    b=0.0;
    c=32.0;
    d=0.0;
    e=5.0;
    f=45.0;


    printf("\nCaso 7:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");


    a=0.0;
    b=3.0;
    c=4.0;
    d=0.0;
    e=3.0;
    f=4.0;


    printf("\nCaso 8:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=5.0;
    b=0.0;
    c=5.0;
    d=5.0;
    e=0.0;
    f=3.0;


    printf("\nCaso 9:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=0.0;
    b=0.0;
    c=0.0;
    d=1.0;
    e=1.0;
    f=2.0;


    printf("\nCaso 10:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");
    
    a=5.0;
    b=1.0;
    c=5.0;
    d=0.0;
    e=0.0;
    f=3.0;


    printf("\nCaso 11:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=0.0;
    b=0.0;
    c=3.0;
    d=0.0;
    e=0.0;
    f=0.0;


    printf("\nCaso 12:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=0.0;
    b=0.0;
    c=0.0;
    d=0.0;
    e=1.0;
    f=3.0;


    printf("\nCaso 13:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=0.0;
    b=0.0;
    c=0.0;
    d=1.0;
    e=0.0;
    f=3.0;


    printf("\nCaso 14:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");

    a=0.0;
    b=1.0;
    c=0.0;
    d=0.0;
    e=0.0;
    f=3.0;


    printf("\nCaso 15:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar al siguiente caso ");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    system("clear");
    
    a=2.0;
    b=0.0;
    c=0.0;
    d=0.0;
    e=0.0;
    f=3.0;


    printf("\nCaso 16:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==-1){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nEs singular\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }
    printf("\nIngrese una tecla para continuar con el programa");
    scanf("%*[^\n]%*c");  // limpia el buffer
    scanf("%f",&a);
    

    return 0;



}