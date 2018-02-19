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

int check_buff(char **buffer, int *error, int fd, char *to_check)
{
	if (buffer[0] == NULL) {
		*error = -1;
		return (-1);
	}
	for (;buffer[0] != NULL && buffer[0][0] == '#'; buffer[0] = get_next_line(fd));
	if (buffer[0] == NULL)
		return (-1);
	buffer[0] = clear_str(buffer[0]);
	if ((my_strncmp(buffer[0], to_check, 5) != 0)) {
		*error = -6;
		return (-1);
	}
	return (0);
}

void fill_first_case(node_t **first, node_t **second, node_t **save, char **buffer)
{
	int nb = 0;

	for (int i = 7; (*buffer)[i] != '"'; i++)
		nb++;
	*first = malloc(sizeof(**first));
	*second = malloc(sizeof(**second));
	(*first)->label = malloc(sizeof(char) * (nb + 1));
	(*first)->label = my_strcpy2((*first)->label, (*buffer + 7));
	(*first)->label[nb] = '\0';
	(*first)->next = *second;
	*save = *first;
	*first = *second;
}

void fill_second_case(node_t **first, node_t **second, node_t **save, char **buffer)
{
	int nb = 0;

	for (int i = 10; (*buffer)[i] != '"'; i++)
		nb++;
	(*first)->label = malloc(sizeof(char) * (nb + 1));
	(*first)->label = my_strcpy2((*first)->label, (*buffer + 10));
	(*first)->label[nb] = '\0';
}

node_t *fill_linked_list(char *filename, int *error)
{
	char *pathname = concat(filename, ".s", 0, 0);
	int fd = open(pathname, O_RDWR, 0700);
	char *buffer = get_next_line(fd);
	node_t *first = NULL;
	node_t *second = NULL;
	node_t *save = first;

	//les 5 prochaines lignes à mettre dans une fonction
	if (check_buff(&buffer, error, fd, ".name") == -1)
		return (NULL);
	test_synt_name(buffer + 5, error);
	if (*error != 0)
		return (NULL);
	fill_first_case(&first, &second, &save, &buffer);
	buffer = get_next_line(fd);
	if (check_buff(&buffer, error, fd, ".comment") == -1)
		return (NULL);
	test_synt_name(buffer + 8, error);
	if (*error != 0)
		return (NULL);
	fill_second_case(&first, &second, &save, &buffer);
	fill_next(first, &buffer);
	return (save);
}