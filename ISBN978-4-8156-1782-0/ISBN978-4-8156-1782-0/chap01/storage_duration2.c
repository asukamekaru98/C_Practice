#include<stdio.h>

int ft;
void func()
{
	int at = 0;
	static int st;	//�����������͈̂�x����

	ft++;
	at++;
	st++;

	printf("ft = %d at = %d st = %d\n", ft, at, st);
}

int main()
{
	for (int i = 0; i < 8; i++) {
		func();
	}
}