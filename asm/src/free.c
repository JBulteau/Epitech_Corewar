/*
** EPITECH PROJECT, 2017
** free.c
** File description:
** Functions used to free
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

void free_linked_list(node_t *linked_list)
{
	if (linked_list == NULL)
		return;
	if (linked_list->next != NULL)
		free_linked_list(linked_list->next);
	free(linked_list);
}

int open_new_file(char *filename)
{
	char *pathname = NULL;
	int i;
	int fd;

	for (i = my_strlen(filename); i >= 0 && filename[i] != '/'; i--);
	filename = (filename[i] == '/') ? filename + i + 1 : filename;
	pathname = concat(filename, ".cor", 0, 0);
	fd = open(pathname, O_CREAT | O_RDWR, 0644);
	if ((pathname == NULL) || (fd == -1)) {
		if (pathname)
			free(pathname);
		return (-1);
	}
	free(pathname);
	return (fd);
}

int write_exec(char *filename, node_t *entry)
{
	int error = 0;
	int fd = open_new_file(filename);
	int total_size = 0;

	for (node_t *curr = entry->next->next; curr != NULL; curr = curr->next)
		total_size += size(curr->info);
	write_header(fd, entry->label[0], entry->next->label[0], total_size);
	for (node_t *curr = entry->next->next; curr != NULL; curr = curr->next)
		write_op(fd, curr->info);
	return (0);
}