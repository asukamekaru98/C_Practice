#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdio.h>

char* str_dt(const struct tm* timeptr)
{
	static char result[20];

	sprintf(result, "%04d-%02d-%02d %02d:%02d:%02d",
		timeptr->tm_year + 1900, timeptr->tm_mon + 1, timeptr->tm_wday,
		timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec);

	return result;
}

int main(void)
{
	time_t now = time(NULL);

	printf("åªç›éûçè%s\n", str_dt(localtime(&now)));

	return 0;
}