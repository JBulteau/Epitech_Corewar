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

int parsing(node_t *first, char **buffer, int fd)
{
	int inc = 0;
	int check = 0;
	node_t *new = NULL;

	for (; *buffer != NULL && (*buffer[0] == '\0' || *buffer[0] == '#'); \
(*buffer = get_next_line(fd))); // main for ??
	new = malloc(sizeof(*new));
	for (; *buffer[inc] != '\0'; inc++) {
		if (*buffer[inc] == '#' || *buffer[inc] == '%' || \
*buffer[inc] == ',')
			return(-6);
		if (*buffer[inc] == ' ' || *buffer[inc] == ':')
			break;
		if ((check = check_label_chars(buffer, inc)) < 0)
			return (check);
	}
	if (*buffer[inc] != ':')
		check = find_instru(*buffer);
	if (check == -1 || *buffer[inc] == '\0' || (*buffer[inc] == ':' \
&& *buffer[inc + 1] != ' '))
		return (-6);
	first->next = new;
	new->info.op_code = check;
	if ((check = check_args(check, *buffer + inc + 1, &(new->info))) < 0)
		return(check);
	first = new;
	return (0);
}