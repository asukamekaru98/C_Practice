#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


double power(double x, int n);

int main()
{
	double x;
	int k, n;

	printf("実数x : ");
	scanf("%lf", &x);

	printf("実数k : ");
	scanf("%d", &k);

	printf("実数n : ");
	scanf("%d", &n);

	printf("xのn乗 = %f\n", power(x, n));
	printf("kのn乗 = %f\n", power(k, n));
}

double power(double x, int n)
{
	double tmp = 1.0;

	for (int i = 1;i <= n; i++) {
		tmp *= x;
	}
	return tmp;
}