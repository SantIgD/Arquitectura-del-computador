#include <stdio.h>
unsigned long fact1(unsigned long);
unsigned long fact2(unsigned long);
int main(void)
{
	unsigned long x; // por lo tanto el factorial mas grande a calcular es 12! (el numero mas grande a representar es 2^32 - 1)
    printf ("Ingrese x para calcular x!: ");
	scanf("%lu", &x);
	printf("fact1: %lu! = %lu\n",x, fact1(x));
	printf("fact2: %lu! = %lu\n",x, fact2(x));
	return 0;
}