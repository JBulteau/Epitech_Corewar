/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** My strncmp (strcmp -> n = -1)
*/

#include <unistd.h>

int my_strcmp(char *str1, char *str2, int n)
{
	int i;

	if ((str1 == NULL) || (str2 == NULL))
		return (0);
	if (n == -1) {
		for (i = 0; str1[i] && str2[i]; i++)
			if (str1[i] != str2[i])
				return (0);
		if (str1[i] != str2[i])
			return (0);
		return (1);
	} else {
		for (i = 0; i < n && str1[i] && str2[i]; i++)
			if (str1[i] != str2[i])
				return (0);
		return (1);
	}
}