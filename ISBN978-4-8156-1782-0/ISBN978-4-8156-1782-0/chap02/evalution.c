#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x, y;

	printf("x:");
	scanf("%d", &x);

	printf("y:");
	scanf("%d", &y);

	printf("x < y : %d\n", x < y);
	printf("x <= y : %d\n", x <= y);
	printf("x > y : %d\n", x > y);
	printf("x >= y : %d\n", x >= y);
	printf("x == y : %d\n", x == y);
	printf("x != y : %d\n", x != y);
}