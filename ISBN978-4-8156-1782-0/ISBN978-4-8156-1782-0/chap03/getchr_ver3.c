#include <stdio.h>

#define BUFSIZE 256

char buffer[BUFSIZE];
int buf_no = 0;
int front = 0;
int rear = 0;

int getchr()
{
	if (buf_no <= 0) {
		return getchr();
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