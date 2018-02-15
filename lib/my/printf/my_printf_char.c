/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** functions handling with char and str for my_printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int my_ptr_c(va_list ap, char *flags)
{
	int n = 0;
	char str [2];
	int len = 1;

	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (test_str_flags(str, len, flags, n));
}

int my_ptr_s(va_list ap, char *flags)
{
	int n = 0;
	char *str = va_arg(ap, char *);
	int len = my_strlen(str);

	return (test_str_flags(str, len, flags, n));
}

int my_ptr_s_maj(va_list ap, char *flags)
{
	int n = 0;
	char *str = va_arg(ap, char *);
	int len = my_strlen(str);

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < 32 || str[i] >= 127)
			len += 3;
	return (test_str_flags(str, len, flags, n));
}
