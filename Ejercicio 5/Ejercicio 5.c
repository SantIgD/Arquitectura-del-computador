#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define longitud 200

/*
    codificar_decodificar :: int->char* -> void

    Recibe una clave y una palabra a codificar/decodificar utilizando
    XOR(^) y sus propiedades
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

    //Codificamos la palabra
    codificar_decodificar(clave,palabra);
    printf("La palabra con la clave es: %s", &palabra);

    //Decodificamos la palabra
    codificar_decodificar(clave,palabra);
    printf("\nLa palabra decodificada: %s", &palabra);

    return 0;
}

/*

Primer pregunta:

No sería necesaria ninguna modificación la función es capaz tanto de 
codificar como de decodificar.

Segunda pregunta:

Utilizando diferentes claves la palabra se ira codificando cada vez más
ganando una codificación más profunda. Y que para decodificarla bastaría 
con volver a aplicar las claves utilizadas (en este caso no importa el orden 
ya que XOR tiene propiedades conmutativas y asociativas).

*/