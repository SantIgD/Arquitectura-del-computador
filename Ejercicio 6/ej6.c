#include <stdio.h>
int resolver_matriz_2x2(float* x,float* y ,float a,float b,float c,float d,float e,float f);

int testear_NaN();

int testear_inf();

int testear_casos();

int main(){


    if(testear_NaN()==0 && testear_inf()==0){
        testear_casos();
        return 0;
    }
    return -1;
        
    

    //printf("Resultado: %f\nx=%.2f\ny=%.2f\n",a,x,y);
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
        
        printf("El programa filtra las entradas en inf correctamente\n");
        return 0;
    }else{
        printf("El programa no fiiltra las entradas en inf correctamente\n");
        return -1;
    }
}

int testear_casos(){

    float a = 0.0;
    float b = 2.0;
    float c = 0.0;
    float d = 1.0;
    float e = 3.0;
    float f = 4.0;

    float x;
    float y;

    printf("\nCaso 2:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0 && x==4 && y==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        return -1;
    }

    a=4.0;
    b=0.0;
    c=16.0;
    d=1.0;
    e=5.0;
    f=29.0;


    printf("\nCaso 3:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0 && x==4 && y==5){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        return -1;
    }

    a=3.0;
    b=15.5;
    c=34.0;
    d=0.0;
    e=57.0;
    f=114.0;


    printf("\nCaso 4:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0 && x==1 && y==2){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        return -1;
    }

    a=4.0;
    b=3.0;
    c=0.0;
    d=7.0;
    e=0.0;
    f=1.0;


    printf("\nCaso 5:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }

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
    a=4.0;
    b=0.0;
    c=32.0;
    d=0.0;
    e=5.0;
    f=45.0;


    printf("\nCaso 6:");
    if(resolver_matriz_2x2(&x,&y,a,b,c,d,e,f)==0){
        printf("\nLa matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nFue solucionada correctamente\n",a,b,c,d,e,f);
        printf("\nLa respuesta fue: (x,y) = (%.2f,%.2f)\n",x,y);
    }else{
        printf("\nLa matriz\n La matriz\n %.2f x + %.2f y = %.2f\n %.2f x + %.2f y = %.2f\nNo Fue solucionada correctamente\n",a,b,c,d,e,f);
        
        return -1;
    }

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

}
