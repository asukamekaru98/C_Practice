#include<stdio.h>

int main(void) {
	typedef int IntAry[];
	IntAry a = { 1,2,3 };
	IntAry b = { 1,2,3,4,5 };

	for (int i = 0; i < 3; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}

	for (int i = 0; i < 5; i++) {
		printf("b[%d] = %d\n", i, b[i]);
	}
}