#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

void div(int a, int b)
{
	assert(b != 0);

	printf("%dを%dで割った翔は%dで剰余は%dです\n", a, b, a / b, a % b);
}

int main() {
	int a, b;

	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	div(a, b);

}