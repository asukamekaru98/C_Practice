#ifndef MATUTIL
#define MATUTIL

#include<stdio.h>
#include<stdlib.h>

#ifndef SCALAR
	// ベクトルや行列の成分の型
	#define SCALAR double
#endif // !SCALAR

// 
typedef SCALAR* vertor, ** matrix;

// メッセージを表示して終了する関数
void error(char* message)
{
	fprintf(stderr, "\n%s\n", message);
	exit(1);
}




#endif // !MATUTIL
