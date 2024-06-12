#include<stdio.h>
#include"chap03/getchr.h"
#include"chap03/_getchr.h"

char __buffer[__BUFSIZE];
int __buf_no = 0;
int __front = 0;
int __rear = 0;

int getchr()
{
	if (__buf_no <= 0) {
		return getchr();
	}
	else {
		__buf_no--;
		int temp = __buffer[__front++];
		if (__front == __BUFSIZE) {
			__front = 0;
		}
		return temp;
	}
}