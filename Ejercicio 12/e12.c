#include <stdio.h>
#include "guindows.h"

task t1, t2,t3, taskmain;

void ft1(){
	double d;
    printf("[dir] t1: &d= 0x%lX\n sizeof double: %d\n",&d,sizeof(d));
	for(d=-1;;d+=0.001) {
		printf("t1: d=%f\n", d);
		TRANSFER(t1,t2);
	}
}

void ft2(){
	int i;
    printf("[dir] t2: &i= 0x%lX\n  sizeof int: %d\n",&i,sizeof(i));
	for(i=0;i<10000;i++) {
		printf("t2: i=%d\n", i);
		TRANSFER(t2,t3);
	}
	//TRANSFER(t2, taskmain);
}


void ft3(void){
  unsigned j;
  printf("[dir] t3: &j= 0x%lX\n sizeof unsigned: %d\n",&j,sizeof(j));
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
	printf("SizeofChar: %d\n",sizeof(char));
	TRANSFER(taskmain,t1);
	return 0;
}
