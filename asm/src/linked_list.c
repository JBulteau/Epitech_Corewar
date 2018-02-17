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

char *my_strcpy2(char *dest, char const *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest [i] = '\0';
	return (dest);
}

void test_synt_name(char *name, int *error)
{
	int i = 1;

	if (name[0] != ' ') {
		*error = -6;
		return;
	} else if (name[1] != '"') {
		*error = -5
		return;
	}
	while (name[++i] != '\0' && name[i] != '"');
	if (i == 2) {
		*error = -3;
		return;
	} else if (name[i] == '\0' || name[i + 1] != '\0') {
		*error = -5;
		return;
	}
}

node_t *fill_linked_list(char *filename, int *error)
{
	char *pathname = concat(filename, ".s", 0, 0);
	int fd = open(pathname, O_RDWR, 0700);
	char *buffer = get_next_line(fd);
	node_t *first = malloc(sizeof(*first));
	node_t *save = first;
	int nb = 0;

	if (buffer == NULL) {
		*error = -1;
		return (NULL);
	}
	for (;buffer != NULL && buffer[0] == '#'; buffer = get_next_line(fd));
	if (buffer == NULL)
		return (NULL);
	buffer = clear_str(buffer);
	if ((my_strncmp(buffer, ".name", 5) != 0)) {
		*error = -6;
		return (NULL);
	}
	//ERROR ROMAIN if (*error != 0) return (NULL);
	for (int i = 7; buffer[i] != '"'; i++)
		nb++;
	first->label = malloc(sizeof(char) * (nb + 1));
	first->label = my_strcpy2(first->label, (buffer + 7));
	first->label[nb] = '\0';
}