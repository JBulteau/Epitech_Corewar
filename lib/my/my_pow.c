/*
** EPITECH PROJECT, 2017
** my_pow
** File description:
** my_pow
*/

int my_pow(int nb, int power)
{
	int result = 1;

	for (int i = 0 ; i < power; i++)
		result *= nb;
	return (result);
}