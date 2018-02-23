/*
** EPITECH PROJECT, 2017
** parsing_and_fill.c
** File description:
** function to parse and fill the linked_list
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int label_parsing(char **buffer, int *inc, node_t *new)
{
	if ((*buffer)[*inc + 1] == ' ') {
		*buffer += 7;

	}
}

int parsing_first_word(char **buffer, node_t **new, int *inc)
{
	int check = 0;

	if ((*buffer)[0] == '\0' || (*buffer)[0] == '#') {
		return (2);
	}
	*new = init_node();
	if (*new == NULL)
		return (84);
	for (; (*buffer)[*inc] != '\0'; (*inc)++) {
		if ((*buffer)[*inc] == '#' || (*buffer)[*inc] == '%' || \
(*buffer)[*inc] == ',')
			return(-6);
		if ((*buffer)[*inc] == ' ' || (*buffer)[*inc] == ':')
			break;
		if ((check = check_label_chars(buffer, *inc)) < 0)
			return (check);
	}
	return (0);
}

int parsing_instru(char **buffer, int *inc, node_t *first, node_t *new)
{
	int check = 0;

	if ((*buffer)[*inc] != ':')
		check = find_instru(my_strdup(*buffer));
	if (check == -1 || (*buffer)[*inc] == '\0')
		return (-6);
	if (((*buffer)[*inc] == ':') && ((*buffer)[*inc + 1] != ' ' && (*buffer)[*inc + 1] != '\0'))
		return (-6);
	first->next = new;
	new->info.op_code = check;
	if ((*buffer)[*inc] == ':')
		label_parsing(buffer, inc, new);
	return (check);
}

int parsing(node_t *first, char **buffer, int fd)
{
	int inc = 0;
	int check = 0;
	node_t *new = NULL;

	*buffer = get_next_line(fd);
	if (*buffer == NULL)
		return (84);
	*buffer = clear_str(*buffer);
	for (; *buffer != NULL ; (*buffer = get_next_line(fd)) && (inc = 0)) {
		*buffer = clear_str(*buffer);
		if ((check = parsing_first_word(buffer, &new, &inc)) == 2)
			continue;
		else if (check != 0)
			return (check);
		if ((check = parsing_instru(buffer, &inc, first, new)) < 0)
			return (check);
		if ((check = check_args(check, *buffer + inc + 1, &(new->info))) < 0)
			return (check);
		new->next = NULL;
		first = new;
	}
	return (0);
}

void write_args_type(in_struct_t *op, int type)
{
	if (op->op_code == 1 || op->op_code == 9 || op->op_code == 12 || op->op_code == 15)
		return;
	if (type == T_DIR)
		op->args_types += 2;	
	else if (type == T_REG)
		op->args_types += 1;	
	else
		op->args_types += 3;	
	op->args_types = op->args_types << 2;
}

void write_args_stru(in_struct_t *op, char *strarg, int type, int nb_arg)
{
	if ((type == T_DIR && strarg[1] != LABEL_CHAR) || type == T_REG)
		op->args[nb_arg] = my_getnbr(strarg + 1);
	else if (type == T_DIR && strarg[1] == LABEL_CHAR)
		op->args[nb_arg] = -1;
	else
		op->args[nb_arg] = my_getnbr(strarg);
}