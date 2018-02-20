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
	if (*buffer == NULL)
		return (*error = -1);
	for (;*buffer != NULL && *buffer[0] == '#'; *buffer = get_next_line(fd));
	if (*buffer == NULL)
		return (-1);
	*buffer = clear_str(*buffer);
	if ((my_strncmp(*buffer, to_check, 5) != 0)) {
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
	(*first)->label[0] = malloc(sizeof(char) * (nb + 2));
	(*first)->label[0] = my_strcpy2((*first)->label[0], (*buffer + 7));
	(*first)->label[0][nb] = '\0';
	for (int i = 1; i <= 4; i++) {
		(*first)->label[i] = malloc(1);
		(*first)->label[i][0] = '\a';
	}
	(*first)->next = *second;
	*save = *first;
	*first = *second;
}

void fill_second_case(node_t **first, node_t **second, node_t **save, char **buffer)
{
	int nb = 0;

	for (int i = 10; (*buffer)[i] != '"'; i++)
		nb++;
	(*first)->label[0] = malloc(sizeof(char) * (nb + 2));
	(*first)->label[0] = my_strcpy2((*first)->label[0], (*buffer + 10));
	(*first)->label[0][nb] = '\0';
	for (int i = 1; i <= 4; i++) {
		(*first)->label[i] = malloc(1);
		(*first)->label[i][0] = '\a';
	}
	(*first)->next = NULL;
}

node_t *fill_linked_list(char *filename, int *error)
{
	char *pathname = concat(filename, ".s", 0, 0);
	int fd = open(pathname, O_RDWR, 0700);
	char *buffer = get_next_line(fd);
	node_t *first = NULL;
	node_t *second = NULL;
	node_t *save = NULL;

	//les 5 prochaines lignes à mettre dans une fonction
	if (buffer == NULL)
		*error = -1;
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
	parsing(first, &buffer, fd);
	//save = save->next->next;
	//for (; save != NULL; save = save->next)
	//	my_printf("op : %i\nargs_type : %i\narg :%s\n\n", save->info.op_code, save->info.args_types, save->info.args[1]);
	return (save);
}