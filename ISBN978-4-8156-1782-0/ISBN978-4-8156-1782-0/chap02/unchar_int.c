#include<stdio.h>
#include<limits.h>

int main(void)
{
	unsigned char ch = UCHAR_MAX;

	printf("chの値は%dです。\n", ch);

	int x = ch + 1;

	printf("\nx = ch + 1;\n");
	printf("xの値は%dです。\n",x);

	x = ++ch;

	printf("\nx = ++ch;\n");
	printf("xの値は%dです。\n", x);
}