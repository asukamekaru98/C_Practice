#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n;

	printf("nの値 : ");
	scanf("%d", &n);

	if (n) {
		puts("0じゃない");
	}
	else {
		puts("0");
	}
}