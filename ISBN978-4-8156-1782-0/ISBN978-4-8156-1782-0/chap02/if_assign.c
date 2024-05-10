#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a,b;

	printf("a‚Ì’l : ");
	scanf("%d", &a);
	printf("b‚Ì’l : ");
	scanf("%d", &b);

	if (a = b) {
		printf("## a = %d\n## b = %d\n", a, b);
	}
	else {
		printf("$$ a = %d\n$$ b = %d\n", a, b);
	}
}