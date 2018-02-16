/*
** EPITECH PROJECT, 2017
** strcpy
** File description:
** Task 01
*/

char *my_strcpy(char *dest, char const *src, int n)
{
	int i = 0;

	if (n == -1) {
		while (src[i] != '\0') {
			dest[i] = src[i];
			i = i + 1;
		}
		dest[i] = '\0';
	} else {
		while (src[i] != '\0' && i < n) {
			dest[i] = src[i];
			i = i + 1;
		}
		dest[i] = '\0';
	}
	return (dest);
}
