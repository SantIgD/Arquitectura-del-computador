#include <stdio.h>


/*
    is_one :: long, int -> int
    
    Indica si el bit b del entero n es 1 o 0, teniendo en cuenta
    que el bit 0 corresponde a b_0 .

    Si el bit b del entero n es 1, retorna 1 sino 0.
*/
int is_one(unsigned long n, int b){
    
    n = n >> b; // Dejamos en la posicion 0 el bit numero b
    n = n & 1;  // Mascara que deja prendido solo el bit numero 0
                // Si el bit numero b es 1, entonces n=1 sino n=0;
    return n;
}

void print_bin(unsigned long n){

    printf("El numero %d en binario 64 bits es: \n",n);

    for (int i=0; i < 64; i++){
        if (i%8 == 0){
            printf(" ");
        }
        
        printf("%d",is_one(n,63-i));

        
    }

}

int main() {

    unsigned long numero;
    printf("Ingrese el numero a convertir: ");
    scanf("%ul",&numero);

    print_bin(numero);
    

   return 0;
}


