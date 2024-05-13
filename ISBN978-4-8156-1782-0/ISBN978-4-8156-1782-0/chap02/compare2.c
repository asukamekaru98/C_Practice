#include<stdio.h>

int main()
{
	int m1 = -1;
	unsigned p1 = 1;

	printf("m1 < p1 Ì -1 < 1U ‚Í %s\n", m1 < p1 ? "^" : "‹U");
	printf("(unsigned)m1 < p1 Ì (unsigned)-1 < 1U ‚Í %s\n", (unsigned)m1 < (unsigned) - 1 ? "^" : "‹U");
}