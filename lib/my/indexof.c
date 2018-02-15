/*
** EPITECH PROJECT, 2017
** indexof.c
** File description:
** Search char in str
*/

int indexof(char c, char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return (i);
	return (-1);
}