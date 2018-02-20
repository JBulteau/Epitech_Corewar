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
	int check_ins = 0;
	int check = 0;

	for (; *buffer != NULL && (*buffer[0] == '\0' || *buffer[0] == '#'); \
(*buffer = get_next_line(fd))); // main for ??
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
		check_ins = find_instru(*buffer);
	if (check_ins == -1 || *buffer[inc] == '\0' || (*buffer[inc] == ':' \
&& *buffer[inc + 1] != ' '))
		return (-6);
	
	
	
	return (0);	
}