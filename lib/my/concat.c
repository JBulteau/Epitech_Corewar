/*
** EPITECH PROJECT, 2017
** concat.c
** File description:
** concat 2 str
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *concat(char *src1, char *src2, int free1, int free2)
{
	int len1 = my_strlen(src1);
	int len2 = my_strlen(src2);
	char *res = malloc(len1 + len2 + 1);

	if (res == NULL)
		return (NULL);
	for (int i = 0; i < len1; i++)
		res[i] = src1[i];
	for (int i = len1; i < len1 + len2; i++)
		res[i] = src2[i - len1];
	res[len1 + len2] = 0;
	if (free1)
		free(src1);
	if (free2)
		free(src2);
	return (res);
}