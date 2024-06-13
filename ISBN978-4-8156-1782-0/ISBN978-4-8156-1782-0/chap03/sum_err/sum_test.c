#define _CRT_SECURE_NO_WARNINGS

#define max 10
#include <stdio.h>
#include "sum.h"

int main()
{
	int n;

	do {
		printf("1~%d‚Ì®”’lF", max);
		scanf("%d", &n);
	} while (n < 1 || n > max);

	printf("1~%d‚Ì˜a‚Í%d‚Å‚·\n", n, sum(n));

	return 0;
}
