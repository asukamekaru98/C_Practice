#include<math.h>
#include<stdio.h>

void func(int no)
{
	register int i;		//register CPU���W�X�^�ɒl��ۑ������ق���������A�Ƃ��������������n�ɗ^����B���ۂɊ��蓖�Ă��邩�͏����n����B
	auto int x = 100;

	printf("x = %d\n", x);

	for (i = 0; i < no;i++) {
		double x = sin((double)i / no);
		printf("x = %f\n", x);
	}
	printf("x = %d\n", x);
}

int main()
{
	func(10);

}