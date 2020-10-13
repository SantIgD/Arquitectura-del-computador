#include <stdio.h>


/*
    is_one :: long int ->int-> int
    
    Indica si el bit b-ésimo del entero n es 1 o 0, teniendo en cuenta
    que el bit 0 corresponde a b_0 .

    Si el bit b-ésimo del entero n es 1, retorna 1 sino 0.
*/
int is_one(long n, int b){
    
    n = n >> b; // Dejamos en la posicion 0 el bit numero b
    n = n & 1;  // Mascara que deja prendido solo el bit numero 0
                // Si el bit numero b es 1, entonces n=1 sino n=0;
    return n;
}

int main() {

    int continuar=1;
    long valor;
    int  bit;
    
    while(continuar == 1){

        printf("Ingrese numero: ");
        scanf("%ld",&valor);
        printf("Ingrese numero de bit a verificar: ");
        scanf("%d",&bit);

        if(is_one(valor,bit)==1){
            printf("El bit numero %d de el numero %ld se encuentra en 1",bit,valor);
        }else{

            printf("El bit numero %d de el numero %ld se encuentra en 0",bit,valor);
        }
        
        printf("\nIngrese 1 si desea continuar realizando el proceso, sino cualquier otra letra: ");
        scanf("%d",&continuar);
    }
   return 0;
}


