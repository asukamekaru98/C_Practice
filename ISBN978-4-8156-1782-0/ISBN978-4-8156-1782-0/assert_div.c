#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

void div(int a, int b)
{
	assert(b != 0);

	printf("%d��%d�Ŋ������Ă�%d�ŏ�]��%d�ł�\n", a, b, a / b, a % b);
}

int main() {
	int a, b;

	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	div(a, b);

}