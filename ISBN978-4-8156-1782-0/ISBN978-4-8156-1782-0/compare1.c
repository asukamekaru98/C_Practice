#include<stdio.h>

int main()
{
	int m1 = -1;
	unsigned p1 = 1;

	printf("m1 < p1 �� -1 < 1U ��%s\n", m1 < p1 ? "�^" : "�U");
	printf("m1 < (int)p1 �� -1 < (int)1U ��%s\n", m1 < (int)p1 ? "�^" : "�U");
}