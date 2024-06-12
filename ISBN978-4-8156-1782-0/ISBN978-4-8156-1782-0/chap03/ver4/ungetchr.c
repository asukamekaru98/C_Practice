#include<stdio.h>
#include"chap03/getchr.h"
#include"chap03/_getchr.h"

char __buffer[__BUFSIZE];
int __buf_no = 0;
int __front = 0;
int __rear = 0;

int ungetchr(int ch)
{
	if (__buf_no >= __BUFSIZE) {
		return EOF;
	}
	else {
		__buf_no++;
		__buffer[__rear++] = ch;
		if (__rear == __BUFSIZE) {
			__rear = 0;
		}
		return ch;
	}
}