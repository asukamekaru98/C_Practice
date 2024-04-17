#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"max2x1.h"

int main(void)
{
	int x, y;

	printf("x‚Ì’l : "); scanf("%d", &x);
	printf("y‚Ì’l : "); scanf("%d", &y);

	printf("max2(x,y) = %d\n", max2(x, y));

	return 0;
}
