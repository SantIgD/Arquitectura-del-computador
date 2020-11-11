#include <setjmp.h>
#include <stdio.h>

jmp_buf b;

int main(int argc, char **argv) {
	int a=1;
	int res;
	if ((res=setjmp2(b))==0) {
		printf("Haciendo calculo...\n");
		calculo(argv[1][0]); 
	} else {	
		printf("error\n");
	}
	return 0; 	
	
}
