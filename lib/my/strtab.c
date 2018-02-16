/*
** EPITECH PROJECT, 2017
** strtab.c
** File description:
** strtab
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void loop_to_malloc(char **buffer, int *a, char **result)
{
	int quo = 0;

	for (int i = 0; (*buffer)[i] != '\0';) {
		if ((*buffer)[i] == '"')
			quo += 1;
		if ((*buffer)[i] == ' ' && quo % 2 == 0) {
			(*buffer)[i] = '\0';
			result[*a] = malloc(sizeof(char) * i + 1);
			my_strcpy(result[*a], *buffer, -1);
			(*a)++;
			*buffer = *buffer + i + 1;
			i = 0;
		} else
			i++;
	}
}

char **my_str_to_word(char *buffer)
{
	int nb_word = 0;
	char **result = NULL;
	int a = 0;
	int last = 0;
	int quo = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			quo += 1;
		if (buffer[i] == ' ' && quo % 2 == 0)
			nb_word++;
	}
	nb_word += 1;
	result = malloc(sizeof(result) * (nb_word + 1));
	result[nb_word] = NULL;
	loop_to_malloc(&buffer, &a, result);
	for (int i = 0; buffer[i] != '\0'; i++)
		last++;
	result[a] = malloc(sizeof(char) * last + 1);
	my_strcpy(result[a], buffer, -1);
	return (result);
}