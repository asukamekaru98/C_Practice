#include<stdio.h>

#define DEBUG 1

int main() {
	int a = 5;
	int x = 1;

#if DEBUG == 1
	a = x;
#endif

	printf("a�̒l��%d�ł�\n", a);


}