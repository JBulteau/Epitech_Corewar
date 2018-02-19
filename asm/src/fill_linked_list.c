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

int fill_next(node_t *first, char **buffer, int fd)
{
	int inc = 0;
	int check = 0;

	for (; *buffer != NULL && (*buffer[0] == '\0' || *buffer[0] == '#'); \
(*buffer = get_next_line(fd))); // main for ??
	for (; *buffer[inc] != '\0'; inc++) {
		for (int j = 0; LABEL_CHARS[j] != '\0'; j++) {
			if (LABEL_CHARS[j] == *buffer[inc])
				break;
			if (LABEL_CHARS[j + 1] == '\0')
				return (-6);
		}
	}	
	if (*buffer[inc] != ':')
		check = find_instru(*buffer);
	if (check == -1)
		my_putchar('a');
	if (*buffer[inc] == '\0')
		return (-6);
	return (0);	
}