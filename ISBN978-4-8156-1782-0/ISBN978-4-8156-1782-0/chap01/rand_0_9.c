#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int rand_0_9() {
	static int prev = -1;
	int crnt;

	do {
		crnt = rand() % 10;
	} while (crnt == prev);

	prev = crnt;
	return crnt;
}

int main() {
	int n;
	srand(time(NULL));

	printf("—”‚ğ¶¬‚·‚é‰ñ”F");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", rand_0_9());
	}
}