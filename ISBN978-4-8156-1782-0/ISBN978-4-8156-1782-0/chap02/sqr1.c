#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double sqr(double x)
{
	return x * x;
}

int main()
{
	double x;
	printf("実数値：");
	scanf("%lf", &x);

	printf("2乗は%.3f\n", sqr(x));


}