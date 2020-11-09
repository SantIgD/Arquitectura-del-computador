#include <stdlib.h>
#include <setjmp.h>


#define TPILA 4096
#define NPILAS 10

static void hace_stack(jmp_buf buf, void (*pf)(), unsigned prof, char *dummy) {
	if( dummy - (char *) &prof >= prof) {
		if (setjmp(buf)!=0) {
			pf(); abort();
		}
	} else hace_stack(buf, pf, prof, dummy);
}

void stack(jmp_buf buf, void (*pf)()) {
	static int ctas = NPILAS;
	char dummy;
	hace_stack(buf, pf, TPILA *ctas, &dummy);
	ctas--;
    
}

/*
# x    --> r.a stack
# x-8  --> rbp
# x-16 --> buf
# x-24 --> *pf
# x-32 --> ctas
# x-36 --> dummy -> desde aca contamos

# x-44 --> r.a hace_stack
# x-52 --> rbp
# x-60 --> buf
# x-68 --> pf
# x-76 --> prof=40960
# x-84 --> &dummy = x-36   => x-36 - (x-76) >= 40960 => 40960 - 40 >= 40960? no.

# x-92 --> r.a hace_stack
# x-100 --> rbp
# x-108 --> buf
# x-116 --> pf
# x-124 --> prof=40960
# x-1. --> &dummy = x-36   => x-36 - (x-124) >= 40960 => 40960 - 88 >= 40960? no.

*/