#include<stdio.h>

#define DEBUG 1

int main() {
	int a = 5;
	int x = 1;

#if DEBUG == 1
	a = x;
#endif

	printf("aの値は%dです\n", a);


}