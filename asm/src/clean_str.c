/*
** EPITECH PROJECT, 2017
** clean_str.c
** File description:
** function to clean the str from all useless spaces and tab
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

void init_clear_str(char *buffer, char **result)
{
	int nb = 0;
	int i = 0;

	for (; buffer[i] != '\0'; i++) {
		if ((buffer[i] == ' ' || buffer[i] == '\t'))
			for (; buffer[i + 1] == ' ' || \
buffer[i + 1] == '\t'; i++);
		nb++;
	}
	if (buffer[i - 1] == ' ' || buffer[i - 1] == '\t')
		nb--;
	if (buffer[0] == ' ' || buffer[0] == '\t')
		nb--;
	*result = malloc(sizeof(char) * (nb + 2));
	(*result)[nb] = '\0';

}

void spaces_handle(int *a, char *result, int *i, char *buffer)
{
	int j = *i;

	for (; buffer[j] != '\0' && (buffer[j] == ' ' || \
buffer[j] == '\t'); j++);
	if (buffer[j] == '\0')
		j = 0;
	if (*a > 0 && j != 0) {
		result[*a] = ' ';
		(*a)++;
	}
	for (; (buffer[*i + 1] == ' ' || buffer[*i + 1] == '\t'); (*i)++);
}

char *clear_str(char *buffer)
{
	char *result = NULL;
	int a = 0;

	init_clear_str(buffer, &result);
	for (int i = 0; buffer[i] != '\0'; i++) {
		if ((buffer[i] == ' ' || buffer[i] == '\t')) {
			spaces_handle(&a, result, &i, buffer);
			continue;
		}
		result[a++] = buffer[i];
	}
	result[a] = '\0';
	free(buffer);
	return (result);
}

char *get_fn(char *pathname)
{
	int index = 0;
	char *fn = my_strdup(pathname);

	if (fn == NULL)
		return (NULL);
	index = str_find(fn, ".s");
	if (index == -1)
		return (fn);
	if (fn[index + 2] != '\0')
		return (fn);
	fn[index] = 0;
	return (fn);
}