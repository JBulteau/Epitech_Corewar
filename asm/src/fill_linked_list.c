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

int fill_next(node_t *first, char **line, int fd)
{
	for (; line != NULL && (*line[0] == '\0' || *line[0] == '#'); \
(*line = get_next_line(fd))); // main for ??
	for (int i = 0; buffer[i] != '\0'; i++) {
		for (int j = 0; LABEL_CHAR[j] != '\0'; j++) {
			if (LABEL_CHAR[j] == buffer[i])
				break;
			if (LABEL_CHAR[j + 1] == '\0')
				return (-6);
		}
		
	}
	return(0);
	
}