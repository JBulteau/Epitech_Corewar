/*
** EPITECH PROJECT, 2017
** My_put_long
** File description:
** put long for printf
*/

#include "my.h"

int my_put_long_long(long long nb, int i)
{
	char *base = "0123456789abcdef";

	if (nb == 0 && i == 0) {
		my_putchar('0');
		return (1);
	}
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
		i++;
	}
	if (nb != 0) {
		i = my_put_long_long(nb / 16, i + 1);
		my_putchar(base[nb % 16]);
		return (i);
	}
	return (i);
}
