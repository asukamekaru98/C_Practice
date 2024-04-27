#include<math.h>
#include<stdio.h>

void func(int no)
{
	register int i;		//register CPUレジスタに値を保存したほうがいいよ、という示唆を処理系に与える。実際に割り当てられるかは処理系次第。
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