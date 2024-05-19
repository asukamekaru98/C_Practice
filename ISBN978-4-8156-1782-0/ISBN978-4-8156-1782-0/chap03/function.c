#include<stdio.h>

void iprint(), lprint(), fprint(), dprint();

int main(void)
{
	int a = 11111;
	long b = 44444;
	float c = 55555;
	double d = 666666;

	puts("-- a(int) --");
	iprint(a);
	lprint(a);

	puts("\n-- b(long) --");
	iprint(b);
	lprint(b);

	puts("\n-- c(float) --");
	fprint(c);
	dprint(c);

	puts("\n-- d(double) --");
	fprint(d);
	dprint(d);


}

void iprint(x)
int x;
{
	printf("iprint -> %d\n", x);
}

void lprint(x)
long x;
{
	printf("lprint -> %ld\n", x);
}

void fprint(x)
float x;
{
	printf("lprint -> %.1f\n", x);
}

void dprint(x)
double x;
{
	printf("dprint -> %.1f\n", x);
}