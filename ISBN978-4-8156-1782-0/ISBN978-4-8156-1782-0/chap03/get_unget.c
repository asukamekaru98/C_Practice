#include<stdio.h>

#define BUFSIZE 256 //バッファの大きさ

char buffer[BUFSIZE];
int buf_no = 0;
int front = 0;
int rear = 0;

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