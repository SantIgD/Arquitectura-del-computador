#include <stdio.h>




void intercambiar_valores(int a, int b, int c){
    
    printf("Valores ingresados:\n a:%d \n b:%d\n c:%d",a,b,c);

    a = a ^ b; 
    b = b ^ a;     // b = b ^ (a ^ b) =  (b ^ b) ^ a = 0 ^ a = a
    a = a ^ b ^ c; // a =  (a ^ b) ^ a ^ c = b ^ (a ^ a) ^ c = (b ^ 0) ^ c = b ^ c
    c = a ^ c;     // c = (b ^ c) ^ c = b ^ (c ^ c) = b ^ 0 = b
    a = a ^ c;     // a = (b ^ c) ^ b = c ^ (b ^ b) = c ^ 0 = c  

    printf("\nValores intercambiados:\n a:%d \n b:%d\n c:%d",a,b,c);
}

int main() {

    int a,b,c;
    printf("Ingrese el numero a: ");
    scanf("%d",&a);

    printf("Ingrese el numero b: ");
    scanf("%d",&b);
    
    printf("Ingrese el numero c: ");
    scanf("%d",&c);

    intercambiar_valores(a,b,c);

    return 0;
}