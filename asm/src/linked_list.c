/*
** EPITECH PROJECT, 2017
** linked_list.c
** File description:
** functions to fill the linked list of all instructions
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

//op_tab[i];

node_t *fill_linked_list(char *filename, int *error)
{
	char *pathname = concat(filename, ".s", 0, 0);
	int fd = open(pathname, O_RDWR, 0700);
	char *buffer = get_next_line(fd);
	node_t *first = malloc(sizeof(*first));
	node_t *save = first;

	if (buffer == NULL) {
		*error = -1;
		return (NULL);
	}
	for (;buffer != NULL && buffer[0] == '#'; buffer = get_next_line(fd));
	if (buffer == NULL)
		return (NULL);
	if (my_strncmp(buffer, ".name", 5) != 0) {
		*error = -6;
		return (NULL);
	}
}

void init_clear_str(char *buffer, char **result, int *quo)
{
	int nb = 0;
	int i = 0;

	for (; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			(*quo) += 1;
		if ((buffer[i] == ' ' || buffer[i] == '\t') && *quo % 2 == 0)
			for (; buffer[i + 1] == ' ' || \
buffer[i + 1] == '\t'; i++);
		nb++;
	}
	if (buffer[i - 1] == ' ' || buffer[i - 1] == '\t')
		nb--;
	if (buffer[0] == ' ' || buffer[0] == '\t')
		nb--;
	*result = malloc(sizeof(char) * (nb + 1));
	(*result)[nb] = '\0';
	*quo = 0;
}

void spaces_handle(int *a, char *result, int *i, char *buffer)
{
	if (*a > 0) {
		result[*a] = ' ';
		(*a)++;
	}
	for (; (buffer[*i + 1] == ' ' || buffer[*i + 1] == '\t'); (*i)++);
}

char *clear_str(char *buffer)
{
	char *result = NULL;
	int a = 0;
	int quo = 0;

	init_clear_str(buffer, &result, &quo);
	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			quo += 1;
		if ((buffer[i] == ' ' || buffer[i] == '\t') && quo % 2 == 0) {
			spaces_handle(&a, result, &i, buffer);
			continue;
		}
		result[a] = buffer[i];
		a++;
	}
	free(buffer);
	return (result);
}