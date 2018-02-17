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

node_t *fill_linked_list(char *filename)
{
	char *pathname = concat(filename, ".s", 0, 0);
	int fd = open(pathname, O_RDWR, 0700);
	char *buffer = NULL;
	node_t *first = malloc(sizeof(*first));
	node_t *save = first;

	buffer = get_next_line(fd);
}