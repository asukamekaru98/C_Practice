#define _CRT_SECURE_NO_WARNINGS

#define max 10
#include <stdio.h>
#include "sum.h"

int main()
{
	int n;

	do {
		printf("1~%d�̐����l�F", max);
		scanf("%d", &n);
	} while (n < 1 || n > max);

	printf("1~%d�̘a��%d�ł�\n", n, sum(n));

	return 0;
}
