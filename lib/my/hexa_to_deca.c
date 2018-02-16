/*
** EPITECH PROJECT, 2017
** convert hexa to decimal
** File description:
** convert hexa to decimal
*/

#include "my.h"

int hexa_to_deca(char *str)
{
	int nb = 0;
	int index;

	my_revstr(str);
	for (int i = 0; str[i] != '\0'; i++) {
		index = indexof(str[i], "0123456789ABCDEF") * my_pow(16, i);
		if (index == -1)
			return (-1);
		nb += index;
	}
	return (nb);
}