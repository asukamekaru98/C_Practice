#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double sqr(double x)
{
	return x * x;
}

int main()
{
	double x;
	printf("�����l�F");
	scanf("%lf", &x);

	printf("2���%.3f\n", sqr(x));


}