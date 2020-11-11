#include <setjmp.h>
#include <stdio.h>

extern jmp_buf b;

int calculo(char c) {
	if (c=='T') {
		longjmp2(b,1);
	}else{ 
        printf("No se ejecuto longjmp\n");

    }
	return 0; 	
}