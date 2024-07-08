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

	for (i = 0;i < nrow;i++) {
		a[i] = malloc(sizeof(SCALAR) * ncol);

		//�L���e�ʕs���̂Ƃ��A�J������NULL��ԋp
		if (a[i] == NULL) {
			while (--i >= 0)
			{
				free(a[i]);
			}

			free(a);
			return NULL;
		}
	}

	a[nrow] = NULL;
	return a;
}

// �x�N�g���쐬 �G���[���̓G���[��\������B
vector new_vector(int n)
{
	vector v = newvec(n);

	if (v == NULL) error("�L���e�ʕs��");

	return v;
}

int main()
{
	printf("void* %d", (int)sizeof(void*));
	printf("int* %d", (int)sizeof(int*));
}

#endif // !MATUTIL
