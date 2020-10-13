#include <stdio.h>


/*
    is_one :: long int->int -> int
    
    Indica si el bit b-ésimo del entero n es 1 o 0, teniendo en cuenta
    que el bit 0 corresponde a b_0 .

    Si el bit b-ésimo del entero n es 1, retorna 1 sino 0.
*/
int is_one(unsigned long long n, int b){
    
    n = n >> b; // Dejamos en la posicion 0 el bit numero b
    n = n & 1;  // Mascara que deja prendido solo el bit numero 0
                // Si el bit numero b es 1, entonces n=1 sino n=0;
    return n;
}

/*
    print_bin :: unsigned long long -> void
    
    Imprime un entero sin signo de 64 bits en binario
*/

void print_bin(unsigned long long n){

    printf("El numero %llu en binario 64 bits es: \n",n);

    for (int i=0; i < 64; i++){
        if (i%8 == 0){          // Espacio cada 1 byte
            printf(" ");
        }
        
        printf("%d",is_one(n,63-i));  // Mostramos el bit en la posicion 63-i, ya que en pantalla
                                      // lo generamos de izquierda a derecha      
    }

}

int main() {

    unsigned long long numero;
    printf("Ingrese el numero a convertir: ");
    scanf("%llu",&numero);

    print_bin(numero);
    

   return 0;
}


