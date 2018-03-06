/*
** EPITECH PROJECT, 2017
** main.c
** File description
** Main file
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int main(int ac, char **av)
{
	node_t *to_write;
	int error = 0;
	char *name;
	int fd = 0;

	if ((ac == 1) || my_strcmp(av[1], "-h", -1))
		return (my_putstr(USAGE), 0);
	name = get_fn(av[1]);
	if (name == NULL)
		return (84);
	to_write = fill_linked_list(name, &error);
	if (error != 0 && error != 42)
		return (84);
	if (error == 42) {
		//WRITE HEADER
		//fd = _open(name);
		return (0);
		//write_header(fd, to_write->label[0], to_write->next->label[0], 0);
	} else {
		error = replace_labels(to_write->next->next);
		if (error)
			return (84);
		error = write_exec(name, to_write);
	}
	if (error)
		return (84);
	free_ll(to_write);
	free(name);
	return (0);
}