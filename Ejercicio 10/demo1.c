#include <setjmp.h>
#include <stdio.h>

jmp_buf b;


int main() {
	int a=1;
	int res;
	if ((res=setjmp2(b))==0) {
		printf("Haciendo calculo...\n");
		a--;	
		if (a==0) longjmp2(b,10);
		printf("%d\n",1/a);
	} else {	
		printf("error\n");
	}
	return 0; 	
	
}
