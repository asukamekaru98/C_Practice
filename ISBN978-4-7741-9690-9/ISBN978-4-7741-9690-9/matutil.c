#ifndef MATUTIL
#define MATUTIL

#include<stdio.h>
#include<stdlib.h>

#ifndef SCALAR
	// �x�N�g����s��̐����̌^
	#define SCALAR double
#endif // !SCALAR

// 
typedef SCALAR* vertor, ** matrix;

// ���b�Z�[�W��\�����ďI������֐�
void error(char* message)
{
	fprintf(stderr, "\n%s\n", message);
	exit(1);
}




#endif // !MATUTIL
