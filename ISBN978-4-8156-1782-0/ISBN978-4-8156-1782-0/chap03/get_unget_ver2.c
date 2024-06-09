#include<ctype.h>
#include<stdio.h>

#define BUFSIZE 256 //バッファの大きさ

static char buffer[BUFSIZE];
static int buf_no = 0;
static int front = 0;
static int rear = 0;

int getchr()
{
	if (buf_no <= 0) {
		// バッファが空なら
		return getchar(); //キーボードから呼んで返す
	}
	else {
		buf_no--;
		int temp = buffer[front++];

		if (front == BUFSIZE) {
			front = 0;
		}
		return temp;
	}
}

int ungetchr(int ch)
{
	if (buf_no >= BUFSIZE) {
		//バッファが満杯なら
		return EOF; //これ以上押し戻せない
	}
	else {
		buf_no++;
		buffer[rear++] = ch;
		if (rear == BUFSIZE) {
			rear = 0;
		}
		return 0;
	}
}

int getnum()
{
	int c = 0;
	int x = 0;
	int ch;

	while ((ch = getchr()) != EOF && isdigit(ch)) {
		x = x * 10 + ch - '0';
		c++;
	}
	if (ch != EOF) ungetchr(ch);

	if (c) printf("%d\n", x * 2);

	return ch;
}

int getnnum()
{
	int ch;

	while ((ch = getchr()) != EOF && !isdigit(ch))
	{
		putchar(ch);
	}

	if (ch != EOF) ungetchr(ch);

	putchar('\n');

	return ch;
}

int main()
{
	while (getnum() != EOF)
	{
		if (getnnum() == EOF) {
			break;
		}
	}
}
