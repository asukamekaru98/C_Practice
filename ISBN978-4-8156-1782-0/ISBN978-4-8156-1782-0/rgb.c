#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum rgb_id {
	red,
	green,
	blue,
	rgb_no,
};

char* rgb[rgb_no] = {
	[red] = "red",
	[green] = "green",
	[blue] = "blue",
};

int main(void)
{
	int color;

	do {
		for (int i = 0; i < rgb_no; i++) {
			printf("(%d)%s ", i, rgb[i]);

		}
		printf(": ");
		scanf("%d", &color);
	} while (color < red || color >= rgb_no);

	switch (color) {
	case red:
		printf("ê‘");
		break;
	case green:
		printf("óŒ");
		break;
	case blue:
		printf("ê¬");
		break;
	}

	printf("ÇëIÇ—Ç‹ÇµÇΩÇÀ\n");
}