/*
** EPITECH PROJECT, 2017
** my_realloc
** File description:
** my_realloc
*/

#include "my.h"
#include <stdlib.h>

char *my_realloc(char *str, int size)
{
	char *new_str = NULL;

	new_str = malloc(sizeof(char) * size);
	if (new_str == NULL)
		return (NULL);
	if (str != NULL) {
		my_strcpy(new_str, str, -1);
		free(str);
	}
	return (new_str);
}