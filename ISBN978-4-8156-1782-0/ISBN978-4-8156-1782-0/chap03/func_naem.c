#include<stdio.h>

void func()
{
	printf("__func__ = %s\n", __func__);
	printf("__FILE__ = %s\n", __FILE__);
	printf("__LINE__ = %d\n", __LINE__);
	//printf("__LINE__ = %s\n", __LINE__); //エラーなる
}

int main()
{
	func();

	printf("__func__ = %s\n", __func__);
	printf("__FILE__ = %s\n", __FILE__);
	printf("__LINE__ = %d\n", __LINE__);
	//printf("__LINE__ = %s\n", __LINE__); //エラーなる
}