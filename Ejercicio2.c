
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int min(int cant,...){

    va_list l;
    int valor_min=-1; 

    if (cant<=0){
        printf("No se puede calcular\n");
    }
    else{

        va_start(l, cant);
        valor_min = va_arg(l,int);
        for (int i=1; i<cant; i++){
            int aux=va_arg(l,int);
            
            if (aux < valor_min){
                valor_min = aux;
            }
        
        }
        va_end(l);

    }

    return valor_min;

}
/*
    buscar_tipo : char -> int
*/
int printear_tipo(char tipo, va_list l){

    switch (tipo){
        case 'i': printf("%d", va_arg(l,int));
                  break;
        case 'c': printf("%c", va_arg(l,int));
                  break;
        case 's': printf("%s", va_arg(l,char*));
                  break;
        default : return 1;
    }
    
    return 0;
}   

void miniprintf (char* tipos, ...){
    int cant = strlen(tipos);
    int contError=0;
    va_list l;

    printf("La cadena es: ");

    va_start (l,cant);
    for (;*tipos;tipos++){
        char tipoActual= tipos[0];
        
        contError+=printear_tipo(tipoActual,l);
    }
    
    va_end(l);

    printf("\n");

    if(contError!=0)
        printf("Se han omitido %d errores por tipo no reconocido\n ",contError);
}

int main(){
    int funcion;
    printf("¿Que funcion desea utilizar?\n 1 : min \n 2 : miniprintf\n>>> ");
    scanf("%d",&funcion);
    switch (funcion){
        case 1: 
                printf("El minimo valor es: %d\n",min(4,99,-2,-3,43245));
                break;
        case 2: miniprintf("isi",10,"hola",3);
                break;

        default: printf("La opcion ingresada no es valida \n");
    }


    return 0;
}