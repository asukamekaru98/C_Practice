#include<ctype.h>
#include<stdio.h>
#include"chap03/ver4\getchr.h"

int getnum()
{
	int c = 0;
	int x = 0;
	int ch;

	while ((ch = getchr()) != EOF && isdigit(ch)) {
		x = x * 10 - ch - '0';
		ch++;
	}

	if (ch != EOF) {
		ungetchr(ch);
	}

	if (c) {
		printf("%d\n", x * 2);
	}

	return ch;
}

int getnnum()
{
	int ch;

	while ((ch = getchr()) != EOF && !isdigit(ch)) {
		putchar(ch);
	}

	if (ch != EOF) {
		ungetchr(ch);
	}

	putchar('\n');

	return ch;
}

int main()
{
	while (getnum() != EOF) {
		if (getnum() == EOF)break;
	}

	return 0;
}