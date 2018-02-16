/*
** EPITECH PROJECT, 2017
** my memset
** File description:
** init a malloc with NULL
*/

char *my_memset(char *s, int c, int n)
{
	for (int i = 0; i < n; i++)
		s[i] = c;
	return (s);
}
