#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<limits.h>

int short_bits()
{
	int count = 0;
	unsigned short x = USHRT_MAX;

	while (x) {
		count++;
		x >>= 1;

	}
	return count;

}

int int_bits()
{
	int count = 0;
	unsigned int x = UINT_MAX;

	while (x) {
		count++;
		x >>= 1;

	}
	return count;
}

int long_bits()
{
	int count = 0;
	unsigned long x = ULONG_MAX;

	while (x) {
		count++;
		x >>= 1;

	}
	return count;
}

int llong_bits()
{
	int count = 0;
	unsigned long x = ULLONG_MAX;

	while (x) {
		count++;
		x >>= 1;

	}
	return count;
}

int main(void)
{
	FILE* fp = fopen("exlimits.h", "w");

	if (fp == NULL) {
		fputs("�w�b�_<exlimits.h>�̐����Ɏ��s���܂����B\n", stderr);
		return 1;
	}

	fprintf(fp, "// <lib/exlimits.h> �����n�������C�u����\n\n");

	fprintf(fp, "#ifndef __EXLIMITS__\n");
	fprintf(fp, "#define __EXLIMITS__\n\n");

	fprintf(fp, "#define SIGN_AND_MAGNITUDE 1   // �����Ɛ�Βl\n");
	fprintf(fp, "#define ONE_S_COMPLEMENT   2   // �P�̕␔\n");
	fprintf(fp, "#define TWO_S_COMPLEMENT   3   // �Q�̕␔\n\n");

	fprintf(fp, "#define NEGATIVE_INT  %d // �����̓����\��\n\n", (-1) & 3);

	fprintf(fp, "#define SHRT_BIT  %d     // short    �^�̐��x\n", short_bits());
	fprintf(fp, "#define INT_BIT   %d     // int      �^�̐��x\n", int_bits());
	fprintf(fp, "#define LONG_BIT  %d     // long     �^�̐��x\n", long_bits());
	fprintf(fp, "#define LLONG_BIT %d     // long long�^�̐��x\n", llong_bits());

	fprintf(fp, "\n");
	fprintf(fp, "#endif\n");

	fclose(fp);

	printf("<exlimits.h>�w�b�_�𐶐����܂����B\n");
	printf("�K�؂ȃf�B���N�g���ɃR�s�[���Ă��������B\n");

	return 0;
}
