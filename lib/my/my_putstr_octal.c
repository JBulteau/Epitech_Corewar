/*
** EPITECH PROJECT, 2017
** putstr, print ascii octal when non printable
** File description:
** putstr octal
*/

#include "my.h"

void convert_octal(char c)
{
	if (c < 8)
		my_putstr("00");
	else if (c < 32)
		my_putchar('0');
	my_putnbr_base(c, "01234567", 0);
}

int my_putstr_octal(char *str)
{
	int i = 0;

	while (*str != '\0') {
		if (*str < 32 || *str >= 127) {
			my_putchar('\\');
			convert_octal(*str);
			i += 4;
		} else {
			my_putchar(*str);
			i++;
		}
		str++;
	}
	return (i);
}
