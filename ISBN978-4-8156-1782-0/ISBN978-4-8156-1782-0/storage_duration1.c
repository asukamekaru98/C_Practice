#include<stdio.h>

int ft = 0;
void func()
{
	int at = 0;
	static int st = 0;	//‰Šú‰»‚³‚ê‚é‚Ì‚Íˆê“x‚¾‚¯

	ft++;
	at++;
	st++;

	printf("ft = %d at = %d st = %d\n",ft, at, st);
}

int main()
{
	for (int i = 0;i < 8;i++) {
		func();
	}
}