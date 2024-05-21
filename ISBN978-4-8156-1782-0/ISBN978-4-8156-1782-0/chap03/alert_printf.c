#include <stdio.h>
#include <stdarg.h>

int alert_printf(const char* format, ...)
{
	va_list ap;

	putchar('\a');
	va_start(ap, format);
	int count = vprintf(format, ap);
	va_end(ap);

	return count;
}

int main()
{
	alert_printf("Hello\n");
	alert_printf("%d %ld %.2f\n",2, 3L, 3.14);

	return 0;
}