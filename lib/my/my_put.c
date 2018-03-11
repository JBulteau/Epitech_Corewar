/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** my_put functions
*/

#include "my.h"
#include <unistd.h>

int my_putchar(char c)
{
	return (write(1, &c, 1));
}

int my_putstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (i);
}

int my_put_nbrbase(int nb, char *base)
{
	int base_len = my_strlen(base);
	int displayed = 0;

	if (nb < 0)
		my_putchar('-');
	nb = (nb < 0) ? -nb : nb;
	if (nb == 0) {
		my_putchar(base[0]);
		return (0);
	}
	if (nb / base_len != 0)
		displayed = my_put_nbrbase(nb / base_len, base) + 1;
	my_putchar(base[nb % base_len]);
	return (displayed);
}

int my_put_nbr(int nb)
{
	return (my_put_nbrbase(nb, "0123456789"));
}