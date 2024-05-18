#include <stdio.h>

int add(x, y);
int x, y;
{
	return x + y;
}

main()
{
	int a, b;

	printf("a: ");
	scanf("%d", &a);

	printf("b: ");
	scanf("%d", &b);

	printf("a + b = %d\n", add(a, b));
}