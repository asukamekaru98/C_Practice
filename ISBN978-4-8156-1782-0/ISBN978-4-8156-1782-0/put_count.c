#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void put_count(void)
{
	static int count = 0;
	printf("put_count:%d���\n", ++count);
}

int main()
{
	int n;

	printf("�Ăяo���񐔁F");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		put_count();
	}

}