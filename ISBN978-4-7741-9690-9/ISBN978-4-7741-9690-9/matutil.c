#ifndef MATUTIL
#define MATUTIL

#include<stdio.h>
#include<stdlib.h>

#ifndef SCALAR
	// �x�N�g����s��̐����̌^
	#define SCALAR double
#endif // !SCALAR

// 
typedef SCALAR* vector, ** matrix;

// ���b�Z�[�W��\�����ďI������֐�
void error(char* message)
{
	fprintf(stderr, "\n%s\n", message);
	exit(1);
}

// �x�N�g���쐬
// v = newvec(10); �Ƃ����ӂ��ɂ���ƁAv[0] ~ v[9]�܂Ŏg����
vector newvec(int n)
{
	return malloc(sizeof(SCALAR) * n);
}

// �s������B
// a = newmat(30,40)�Ƃ����ӂ��ɂ���ƁAa[0][0]����a[29][39]�܂Ŏg����B
matrix newmat(int nrow, int ncol)
{
	int i;
	matrix a;

	if ((a = malloc((nrow + 1) * sizeof(void*))) == NULL)
		return NULL;



	return malloc(sizeof(SCALAR))
}

#endif // !MATUTIL
