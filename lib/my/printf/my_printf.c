/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *browse_flags(const char *format, int i, char *flags);
int handle_flags(va_list ap, char *flags);

int is_flag(char *flags)
{
	char *ref = "cdisxXobupS +-0#.123456789";
	int i = 0;
	int j = 0;
	int similitude = 0;

	while (ref[i] != '\0' && flags[j] != '\0') {
		if (ref[i] == flags[j])
			similitude++;
		i++;
		if (ref[i] == '\0') {
			i = 0;
			j++;
		}
	}
	if (similitude == my_strlen(flags))
		return (1);
	else
		return (0);
}

int my_printf(const char *format, ...)
{
	va_list ap;
	int nb = 0;
	char *flags;

	va_start(ap, format);
	for (int i = 0; format[i] != '\0'; i++) {
		if (format[i] == '%') {
			flags = browse_flags(format, i + 1, flags);
			i += (my_strlen(flags) != 0) ? my_strlen(flags) : 1;
			nb += handle_flags(ap, flags);
			free(flags);
		} else
			nb += my_putchar(format[i]);
	}
	va_end(ap);
	return (nb);
}
