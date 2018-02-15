/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** functions handling with numbers in my_printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int my_ptr_d(va_list ap, char *flags)
{
	int nb = va_arg(ap, int);
	int n = 0;
	int len = int_len(nb);

	return (test_int_flags(nb, len, flags, n));
}

int my_ptr_i(va_list ap, char *flags)
{
	int nb = va_arg(ap, int);
	int n = 0;
	int len = int_len(nb);

	return (test_int_flags(nb, len, flags, n));
}

int my_ptr_p(va_list ap, char *flags)
{
	long long nb = va_arg(ap, long long);
	int n = 0;
	int len = long_long_len(nb);

	return (test_long_long_flags(nb, len, flags, n));
}

int my_ptr_u(va_list ap, char *flags)
{
	unsigned int nb = va_arg(ap, int);
	int n = 0;
	char *base = "0123456789";

	return (test_unsigned_flags(nb, base, flags, n));
}
