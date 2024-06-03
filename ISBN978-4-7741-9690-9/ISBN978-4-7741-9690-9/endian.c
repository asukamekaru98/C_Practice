#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 1;

	// int型変数iのアドレスをchar型ポインタにキャストし、その値を確認することでエンディアンを判定
	if (*((char*)&i)) {
		// 最初のバイトが非ゼロであればリトルエンディアン
		printf("リトルエンディアン");
	}
	else if (*((char*)&i + (sizeof(int) - 1))) {
		// 最後のバイトが非ゼロであればビッグエンディアン
		printf("クソデカエンディアン");
	}
	else {
		printf("不明\n");
	}
}