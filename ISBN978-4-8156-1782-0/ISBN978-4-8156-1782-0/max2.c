#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define max2(a,b) ((a) > (b) ? (a) : (b))

int (max2)(int a, int b)
{
	putchar('\a');
	return a > b ? a : b;
}

int main() {
	int x, y;

	printf("x�̒l�F"); scanf("%d", &x);
	printf("y�̒l�F"); scanf("%d", &y);

	printf("max2(x,y) = %d\n\n",max2(x,y));
	printf("(max2)(x,y) = %d\n",(max2)(x,y));
}