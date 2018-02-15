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

int override_useless_flags(char *flags_str, char flag, int count)
{
	int i;

	if (flag == '-' || flag == '.')
		for (i = 0; flags_str[i] != '0' && flags_str[i] != '\0'; i++);
	if (flag == '+')
		for (i = 0; flags_str[i] != ' ' && flags_str[i] != '\0'; i++);
	if (flags_str[i] == '\0')
		return (count);
	while (flags_str[i] != '\0') {
		flags_str[i] = flags_str[i + 1];
		i++;
	}
	return (-1);
}

void find_overrider_flags(char *flags)
{
	for (int i = 0; flags[i] != '\0'; i++) {
		if (flags[i] == '-' || flags[i] == '.' || flags[i] == '+') {
			i = override_useless_flags(flags, flags[i], i);
		}
	}
}

int handle_flags(va_list ap, char *flags)
{
	int size = my_strlen(flags);

	if (size == 0)
		return (1);
	find_overrider_flags(flags);
	return (browse_args(ap, flags));
}

int is_type(char c)
{
	char *str = "cdisxXobupS%";

	while (*str != '\0') {
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char *browse_flags(const char *format, int i, char *flags)
{
	int size = 0;

	while (is_type(format[i]) == 0 && format[i] != '\0') {
		size++;
		i++;
	}
	flags = malloc(sizeof(char) * (size + 2));
	for (int j = 0; j <= size; j++)
		flags[j] = format[i - size + j];
	flags[size + 1] = '\0';
	if (is_flag(flags) == 0) {
		flags[0] = '\0';
		my_putchar('%');
	}
	return (flags);
}
