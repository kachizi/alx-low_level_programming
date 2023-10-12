#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - sum of parameters.
 * @n: number of parameters passed
 * Return: sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list holds;
	unsigned int i, sum = 0;

	va_start(holds, n);

	for (i = 0; i < n; i++)
		sum += va_arg(holds, int);

	va_end(holds);

	return (sum);
}
