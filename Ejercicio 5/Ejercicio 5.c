#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define longitud 200

/*
    codificar_decodificar : int, char* -> void
    Recibe la clave y la palabra a codificar/decodificar ya que 
    por propiedad de xor, (a xor b) xor b = a. 
*/

void codificar_decodificar(int clave,char* palabra){

    int largo =strlen(palabra);

    for (int i = 0; i < largo; i++){
        palabra[i] = palabra[i] ^ clave;
    } 
    
}

int main(int argc, char *argv[]) {

    int clave = atoi(argv[1]);

    char palabra[longitud];

    printf("Ingrese la palabra a codificar: ");
    scanf("%[^\n]",&palabra);

    codificar_decodificar(clave,palabra);
    printf("La palabra con la clave es: %s", &palabra);

    codificar_decodificar(clave,palabra);
    printf("\nLa palabra decodificada: %s", &palabra);

    return 0;
}