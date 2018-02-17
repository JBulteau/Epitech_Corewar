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
		*error = -5;
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

int check_buff(char **buffer, int *error)
{
	if (buffer[0] == NULL) {
		*error = -1;
		return (-1);
	}
	for (;buffer[0] != NULL && buffer[0][0] == '#'; buffer[0] = get_next_line(fd));
	if (buffer[0] == NULL)
		return (-1);
	buffer[0] = clear_str(buffer[0]);
	if ((my_strncmp(buffer[0], ".name", 5) != 0)) {
		*error = -6;
		return (-1);
	}
	return (0);
}

node_t *fill_linked_list(char *filename, int *error)
{
	char *pathname = concat(filename, ".s", 0, 0);
	int fd = open(pathname, O_RDWR, 0700);
	char *buffer = get_next_line(fd);
	node_t *first = malloc(sizeof(*first));
	node_t *save = first;
	int nb = 0;


	//ERROR ROMAIN if (*error != 0) return (NULL);
	for (int i = 7; buffer[i] != '"'; i++)
		nb++;
	first->label = malloc(sizeof(char) * (nb + 1));
	first->label = my_strcpy2(first->label, (buffer + 7));
	first->label[nb] = '\0';
}
