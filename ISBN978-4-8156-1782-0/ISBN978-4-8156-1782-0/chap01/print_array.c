#include<stdio.h>

#define print_array(a,n) (print_array)(#a,a,n)

void(print_array)(const char* name, const int a[], int n)
{
	printf("%s = {", name);
	for(int i = 0; i < n - 1; i++) {
		printf("%d,", a[i]);

	}
	if (n > 0) {
		printf("%d", a[n - 1]);
	}
	printf("}");
}

int main(void)
{
	int x[] = { 1,2,3 };
	int y[] = { 2,4,6,8,10 };

	print_array(x, sizeof(x) / sizeof(x[0]));
	putchar('\n');
	print_array(y, sizeof(y) / sizeof(y[0]));
	putchar('\n');

	(print_array)("x", x, sizeof(x) / sizeof(x[0]));
	putchar('\n');
	(print_array)("y", y, sizeof(y) / sizeof(y[0]));
	putchar('\n');
}