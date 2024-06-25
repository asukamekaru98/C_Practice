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



	return malloc(sizeof(SCALAR))
}

#endif // !MATUTIL
