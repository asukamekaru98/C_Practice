#include<stdio.h>

int main()
{
	int m1 = -1;
	unsigned p1 = 1;

	printf("m1 < p1 �� -1 < 1U �� %s\n", m1 < p1 ? "�^" : "�U");
	printf("(unsigned)m1 < p1 �� (unsigned)-1 < 1U �� %s\n", (unsigned)m1 < (unsigned) - 1 ? "�^" : "�U");
}