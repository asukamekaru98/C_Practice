#include <stdio.h>

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

int main(void)
{
	int a = 5;
	int b = 1;

	printf("a = %d b = %d\n", a, b);

	swap(&a, &b);

	printf("a = %d b = %d\n", a, b);
}