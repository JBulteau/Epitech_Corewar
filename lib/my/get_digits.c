/*
** EPITECH PROJECT, 2017
** get_digits.c
** File description:
** Return the number of digits of an int
*/

int get_digits(int nb)
{
	int i = (nb <= 0) ? 1 : 0;

	for (i = 0; nb != 0; i++)
		nb = nb / 10;
	return (i);
}