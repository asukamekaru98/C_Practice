#include<stdio.h>

int ft;
void func()
{
	int at = sin(0.9);
	static int st = sin(0.9);	//‰Šú‰»‚³‚ê‚é‚Ì‚Íˆê“x‚¾‚¯

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