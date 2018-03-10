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

int parse_words(char **buffer, int *inc, node_t *middle, node_t **first)
{
	node_t *new = malloc(sizeof(node_t));
	int check = 0;

	(*buffer)[*inc] = '\0';
	middle->info.op_code = 0;
	middle->label[0] = malloc(sizeof(char) * (my_strlen(*buffer) + 1));
	if (middle->label[0] == NULL || new == NULL)
		return (84);
	middle->label[0][my_strlen(*buffer)] = '\0';
	for (int i = 0; (*buffer)[i] != '\0'; i++)
		middle->label[0][i] = (*buffer)[i];
	middle->next = new;
	*buffer += (*inc + 2);
	check = find_instru(my_strdup(*buffer));
	new->info.op_code = check;
	if (check == -1)
		return (84);
	*inc = 0;
	parsing_first_word(buffer, first, inc);
	return (check);
}

int label_parsing(char **buffer, int *inc, node_t *middle, node_t **first)
{
	if ((*buffer)[*inc + 1] == ' ') {
		return (parse_words(buffer, inc, middle, first));
	} else {
		(*buffer)[*inc] = '\0';
		middle->info.op_code = 0;
		middle->label[0] = my_strdup(*buffer);
		if (middle->label[0] == NULL)
			return (84);
		*first = middle;
	}
	return (0);

}

int parsing_first_word(char **buffer, node_t **new, int *inc)
{
	int check = 0;

	if ((*buffer)[0] == '\0' || (*buffer)[0] == COMMENT_CHAR)
		return (2);
	if (*new == NULL)
		*new = init_node();
	if (*new == NULL)
		return (-1);
	for (; (*buffer)[*inc] != '\0'; (*inc)++) {
		if ((*buffer)[*inc] == COMMENT_CHAR || (*buffer)[*inc] == \
DIRECT_CHAR || (*buffer)[*inc] == SEPARATOR_CHAR)
			return (-6);
		if ((*buffer)[*inc] == ' ' || (*buffer)[*inc] == LABEL_CHAR)
			break;
		if ((check = check_label_chars(buffer, *inc)) < 0)
			return (check);
	}
	return (0);
}

int parsing_instru(char **buffer, int *inc, node_t *first, node_t *new)
{
	int check = 0;

	if ((*buffer)[*inc] != LABEL_CHAR)
		check = find_instru(my_strdup(*buffer));
	if (check == -1 || (*buffer)[*inc] == '\0')
		return (-6);
	if (((*buffer)[*inc] == LABEL_CHAR) && ((*buffer)[*inc + 1] != ' ' \
&& (*buffer)[*inc + 1] != '\0'))
		return (-6);
	first->next = new;
	new->info.op_code = check;
	if ((*buffer)[*inc] == LABEL_CHAR)
		check = label_parsing(buffer, inc, new, &first);
	return (check);
}

int parsing(node_t *first, char **buffer, int fd)
{
	int inc = 0;
	int check = 0;
	node_t *new = NULL;

	for ((*buffer = get_next_line(fd)) && (*buffer = clear_str(*buffer)); \
*buffer != NULL && *buffer[0] == '\n' && (*buffer = get_next_line(fd)) != \
NULL && (*buffer = clear_str(*buffer)) != NULL; );
	if (*buffer == NULL)
		return (42);
	*buffer = clear_str(*buffer);
	for (int i = 0; *buffer != NULL; (*buffer = get_next_line(fd)) && \
((inc = 0) == 0) && i++) {
		if ((*buffer)[0] == '\0')
			continue;
		*buffer = (i > 0) ? clear_str(*buffer) : *buffer;
		if ((check = parsing_first_word(buffer, &new, &inc)) == 2)
			continue;
		else if (check < 0 || (check = \
parsing_instru(buffer, &inc, first, new)) < 0)
			return (check);
		first = new;
		if (first->next != NULL)
			first = first->next;
		(*buffer)[(indexof(COMMENT_CHAR, (*buffer)) == -1) ? 0 : \
indexof(COMMENT_CHAR, (*buffer))] = (indexof(COMMENT_CHAR, (*buffer)) == -1) \
? (*buffer)[0] : '\0';
		if ((check = check_args(check, *buffer + inc + 1, first)) < 0)
			return (check);
		first->next = NULL;
		new = NULL;
	}
	return (0);
}