#include <stdio.h>
#include "guindows.h"

task t1, t2,t3, taskmain;

void ft1(){
	double d;
    printf("[dir] t1: &d= %p\n",&d);
	for(d=-1;;d+=0.001) {
		printf("t1: d=%f\n", d);
		TRANSFER(t1,t2);
	}
}

void ft2(){
	int i=10;
    printf("[dir] t2: &i= %p\n",&i);
	for(i=0;i<10000;i++) {
		printf("t2: i=%d\n", i);
		TRANSFER(t2,t3);
	}
	//TRANSFER(t2, taskmain);
}


void ft3(void){
  unsigned j=10;
  printf("[dir] t3: &j= %p\n",&j);
  scanf("%d",&j);
  for (j = 0; j < 5000; j++) {
    printf("t3: j=%u\n", j);
    TRANSFER(t3, t1);
    }
  TRANSFER(t3, taskmain);
}


int main(){
	stack(t1,ft1);
	stack(t2,ft2);
    stack(t3,ft3);
	TRANSFER(taskmain,t1);
	return 0;
}
