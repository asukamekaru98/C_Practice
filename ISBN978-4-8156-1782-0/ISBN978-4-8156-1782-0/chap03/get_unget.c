#include<stdio.h>

#define BUFSIZE 256 //�o�b�t�@�̑傫��

char buffer[BUFSIZE];
int buf_no = 0;
int front = 0;
int rear = 0;

int getchr()
{
	if (buf_no <= 0) {
		// �o�b�t�@����Ȃ�
		return getchar(); //�L�[�{�[�h����Ă�ŕԂ�
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
		//�o�b�t�@�����t�Ȃ�
		return EOF; //����ȏ㉟���߂��Ȃ�
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