#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


double power(double x, int n);

int main()
{
	double x;
	int k, n;

	printf("����x : ");
	scanf("%lf", &x);

	printf("����k : ");
	scanf("%d", &k);

	printf("����n : ");
	scanf("%d", &n);

	printf("x��n�� = %f\n", power(x, n));
	printf("k��n�� = %f\n", power(k, n));
}

double power(double x, int n)
{
	double tmp = 1.0;

	for (int i = 1;i <= n; i++) {
		tmp *= x;
	}
	return tmp;
}