#ifndef MATUTIL
#define MATUTIL

#include<stdio.h>
#include<stdlib.h>

#ifndef SCALAR
	// ベクトルや行列の成分の型
	#define SCALAR double
#endif // !SCALAR

// 
typedef SCALAR* vector, ** matrix;

// メッセージを表示して終了する関数
void error(char* message)
{
	fprintf(stderr, "\n%s\n", message);
	exit(1);
}

// ベクトル作成
// v = newvec(10); というふうにすると、v[0] ~ v[9]まで使える
vector newvec(int n)
{
	return malloc(sizeof(SCALAR) * n);
}

// 行列を作る。
// a = newmat(30,40)というふうにすると、a[0][0]からa[29][39]まで使える。
matrix newmat(int nrow, int ncol)
{
	int i;
	matrix a;


	if ((a = malloc((nrow + 1) * sizeof(void*))) == NULL)
		return NULL;

	for (i = 0;i < nrow;i++) {
		a[i] = malloc(sizeof(SCALAR) * ncol);

		//記憶容量不足のとき、開放してNULLを返却
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

// ベクトル作成 エラー時はエラーを表示する。
vector new_vector(int n)
{
	vector v = newvec(n);

	if (v == NULL) error("記憶容量不足");

	return v;
}

int main()
{
	printf("void* %d", (int)sizeof(void*));
	printf("int* %d", (int)sizeof(int*));
}

#endif // !MATUTIL
