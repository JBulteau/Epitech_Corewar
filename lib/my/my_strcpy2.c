/*
** EPITECH PROJECT, 2017
** my_strcpy2.c
** File description:
** strcpy2
*/

char *my_strcpy2(char *dest, char const *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}