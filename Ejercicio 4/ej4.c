#include <stdio.h>

unsigned int campesino_ruso(unsigned int i, unsigned int j);

unsigned int campesino_ruso1(unsigned int i, unsigned int j)
{
unsigned int res = 0;
while (j > 1) {
if (j & 1) {
res += i;
j -= 1;
} else {
i *= 2;
j /= 2;
}
}
return res + i;
}
int i=20;
int j=45;
int main(){

    int resp = campesino_ruso(i,j);
    int resp1 = campesino_ruso1(i,j);
    printf("[Funcion de asm(arm)]%d x %d = %d\n",i,j, resp);
    printf("[Funcion de c]%d x %d = %d\n",i,j,resp1);
}