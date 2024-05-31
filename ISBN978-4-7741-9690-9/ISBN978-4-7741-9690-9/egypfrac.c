#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()
{
	int m, n, q;

	printf(" •ªŽq m = ");
	scanf("%d", &m);

	printf(" •ªŽq n = ");
	scanf("%d", &n);

	printf("%d/%d = ", m, n);

	while (n % m != 0) {
		q = n / m + 1;
		printf("1/%d + ", q);
		m = m * q - m;
		n *= q;
	}
	printf("1/%d\n", n / m);
}