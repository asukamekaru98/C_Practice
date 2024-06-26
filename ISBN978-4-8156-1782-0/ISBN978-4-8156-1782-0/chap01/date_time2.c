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
	time_t current = time(NULL);
	struct tm* timer = localtime(&current);
	char* wday_name[] = { "日","月","火","水","木","金","土" };

	printf("現在時刻は%d年%d月%d日 (%s) %d時%d分%d秒です\n",
		timer->tm_year + 1900,
		timer->tm_mon + 1,
		timer->tm_wday,
		wday_name[timer->tm_wday],
		timer->tm_hour,
		timer->tm_min,
		timer->tm_sec);

	return 0;
}