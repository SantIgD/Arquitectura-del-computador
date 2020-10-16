#include <stdio.h>
//unsigned long fact1(unsigned long);
unsigned long fact2(unsigned long);
int main(void)
{
	unsigned long x;
    printf ("Ingrese x para calcular x!: ");
	scanf("%lu", &x);
	//printf("fact1: %lu\n", fact1(x));
	printf("fact2: %lu! = %lu\n",x, fact2(x));
	return 0;
}