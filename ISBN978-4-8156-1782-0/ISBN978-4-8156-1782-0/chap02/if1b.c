#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n;

	printf("nの値 : ");
	scanf("%d", &n);

	if (n == 0) {
		puts("0");
	}
	else {
		puts("0じゃない");
	}
}