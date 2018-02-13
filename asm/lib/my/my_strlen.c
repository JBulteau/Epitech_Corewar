/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++);
	return (len);
}