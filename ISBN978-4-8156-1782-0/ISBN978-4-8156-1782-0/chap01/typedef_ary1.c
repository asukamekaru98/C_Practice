#include <stdio.h>

int main(void)
{
	typedef int Int5ary[5];
	Int5ary x = { 1,2,3 };

	for (int i = 0; i < 5; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
}