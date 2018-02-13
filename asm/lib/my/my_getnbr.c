/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_get_number
*/

int my_getnbr(char *str)
{
	int nb = 0;
	int sign = 1;

	if (str[0] == '-')
		sign = -1;
	for (int i = (sign == 1) ? 0 : 1; str[i] >= '0' && str[i] <= '9'; i++) {
		nb = nb * 10;
		nb = nb + str[i] - '0';
	}
	return (sign * nb);
}