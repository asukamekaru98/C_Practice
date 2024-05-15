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
		fputs("ヘッダ<exlimits.h>の生成に失敗しました。\n", stderr);
		return 1;
	}

	fprintf(fp, "// <lib/exlimits.h> 処理系特性ライブラリ\n\n");

	fprintf(fp, "#ifndef __EXLIMITS__\n");
	fprintf(fp, "#define __EXLIMITS__\n\n");

	fprintf(fp, "#define SIGN_AND_MAGNITUDE 1   // 符号と絶対値\n");
	fprintf(fp, "#define ONE_S_COMPLEMENT   2   // １の補数\n");
	fprintf(fp, "#define TWO_S_COMPLEMENT   3   // ２の補数\n\n");

	fprintf(fp, "#define NEGATIVE_INT  %d // 負数の内部表現\n\n", (-1) & 3);

	fprintf(fp, "#define SHRT_BIT  %d     // short    型の精度\n", short_bits());
	fprintf(fp, "#define INT_BIT   %d     // int      型の精度\n", int_bits());
	fprintf(fp, "#define LONG_BIT  %d     // long     型の精度\n", long_bits());
	fprintf(fp, "#define LLONG_BIT %d     // long long型の精度\n", llong_bits());

	fprintf(fp, "\n");
	fprintf(fp, "#endif\n");

	fclose(fp);

	printf("<exlimits.h>ヘッダを生成しました。\n");
	printf("適切なディレクトリにコピーしてください。\n");

	return 0;
}
