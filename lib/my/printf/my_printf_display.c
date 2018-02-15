/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "struct_type.h"

int str_padding(int len, char *flags, char c)
{
	int i;
	int n = 0;

	for (i = 0; (flags[i] <= '0' || flags[i] > '9')\
&& flags[i] != '\0'; i++);
	while (flags[i] > '0' && flags[i] <= '9') {
		n = n * 10 + (flags[i] - '0');
		i++;
	}
	for (i = n; i > len; i--)
		my_putchar(c);
	if (len > n)
		return (0);
	return (n - len);
}

int is_in_str(char c, char *flags)
{
	while (*flags != '\0') {
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

int browse_args(va_list ap, char *flags)
{
	for (int i = 0; i < 11; i++)
		if (type_funcs[i].type == flags[my_strlen(flags) - 1])
			return (type_funcs[i].ptrfunc(ap, flags));
	return (0);
}
