#include<stdio.h>
#include<limits.h>

int main(void)
{
	unsigned char ch = UCHAR_MAX;

	printf("ch�̒l��%d�ł��B\n", ch);

	int x = ch + 1;

	printf("\nx = ch + 1;\n");
	printf("x�̒l��%d�ł��B\n",x);

	x = ++ch;

	printf("\nx = ++ch;\n");
	printf("x�̒l��%d�ł��B\n", x);
}