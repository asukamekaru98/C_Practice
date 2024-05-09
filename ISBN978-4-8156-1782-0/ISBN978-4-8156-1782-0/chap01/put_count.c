#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void put_count(void)
{
	static int count = 0;
	printf("put_count:%d‰ñ–Ú\n", ++count);
}

int main()
{
	int n;

	printf("ŒÄ‚Ño‚µ‰ñ”F");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		put_count();
	}

}