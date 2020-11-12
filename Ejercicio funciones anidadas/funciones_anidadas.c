#include <stdio.h>

void p1(){
	int a;
	void p2(){
		int b;
		void p3(){
			int c;
            c=b*a;
			printf("%d\n", c );
		}
		b=a+1;
		p3();
	}
	a=5;
	p2();
}

int main(){
    p1();
    return 0;
}