/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** strlen
*/

#include <unistd.h>
#include "my.h"

int my_strlen(char const *str)
{
	int len;

	if (str == NULL)
		return (-1);
	for (len = 0; str[len] != '\0'; len++);
	return (len);
}