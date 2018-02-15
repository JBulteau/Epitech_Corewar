/*
** EPITECH PROJECT, 2017
** putnbr base
** File description:
** convert int from base 10 to given base
*/

#include "my.h"

int my_putnbr_base(int nb, char const *base, int i)
{
	int b_len = my_strlen(base);

	if (nb == 0 && i == 0) {
		my_putchar('0');
		return (1);
	}
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb != 0) {
		i = my_putnbr_base(nb / b_len, base, i + 1);
		my_putchar(base[nb % b_len]);
		return (i);
	}
	return (0);
}
