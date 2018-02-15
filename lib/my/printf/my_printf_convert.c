/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** functions handling with convert base for my_printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int my_ptr_x(va_list ap, char *flags)
{
	unsigned int nb = va_arg(ap, unsigned int);
	int n = 0;
	char *base = "0123456789abcdef";

	return (test_unsigned_flags(nb, base, flags, n));
}

int my_ptr_x_maj(va_list ap, char *flags)
{
	unsigned int nb = va_arg(ap, unsigned int);
	int n = 0;
	char *base = "0123456789ABCDEF";

	return (test_unsigned_flags(nb, base, flags, n));
}

int my_ptr_o(va_list ap, char *flags)
{
	unsigned int nb = va_arg(ap, unsigned int);
	int n = 0;
	char *base = "01234567";

	return (test_unsigned_flags(nb, base, flags, n));
}

int my_ptr_b(va_list ap, char *flags)
{
	unsigned int nb = va_arg(ap, unsigned int);
	int n = 0;
	char *base = "01";

	return (test_unsigned_flags(nb, base, flags, n));
}
