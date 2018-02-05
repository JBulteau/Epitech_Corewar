/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** duplicates a str
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
	char *out;
	int i;

	out = malloc(my_strlen(str) + 1);
	for (i = 0; str[i] != '\0'; i++)
		out[i] = str[i];
	out[i] = '\0';
	return (out);
}