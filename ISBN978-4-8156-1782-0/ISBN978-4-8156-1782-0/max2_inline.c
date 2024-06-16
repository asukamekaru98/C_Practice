#include<stdio.h>

inline int max2(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	printf("%d", max2(1, 2));
}