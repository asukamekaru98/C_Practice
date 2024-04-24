#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

void div(int a, int b)
{
	assert(b != 0);

	printf("%d‚ğ%d‚ÅŠ„‚Á‚½ãÄ‚Í%d‚Åè—]‚Í%d‚Å‚·\n", a, b, a / b, a % b);
}

int main() {
	int a, b;

	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	div(a, b);

}