#include <stdio.h>

/*    UBICACION                     ESPACIO
    7FFDE5413084: f  (short f)     -> 2 Bytes  
    7FFDE5413088: d  (long d)      -> 4 Bytes
    7FFDE5413090: e  (char e)      -> 1 Bytes
    7FFDE5413094: c  (char c)      -> 1 Bytes
    7FFDE5413098: b  (int b)       -> 2 Bytes
    7FFDE541309C: a  (int a)       -> 2 Bytes 
    7FFDE54130B0: g  (int g)       -> 2 Bytes
    7FFDE54130B8: h  (int h)       -> 2 Bytes
    7FFDE54130C8: Tope de pila

          TOPE DE PILA otra compilacion = 7fffffffdc68
*/

int f(char a, int b, char c, long d,
char e, short f, int g, int h){   
        printf("a: %p\n", &a);
        printf("b: %p\n", &b);
        printf("c: %p\n", &c);
        printf("d: %p\n", &d);
        printf("e: %p\n", &e);
        printf("f: %p\n", &f);
        printf("g: %p\n", &g);
        printf("h: %p\n", &h);
        return 0;
}

int main(void){

    return f('1', 2, '3', 4, '5', 6, 7, 8);
}