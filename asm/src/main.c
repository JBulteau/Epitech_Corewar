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

	if ((ac == 1) || my_strcmp(av[1], "-h", -1)) {
		my_putstr(USAGE);
		return (0);
	}
	name = get_fn(av[1]);
	if (name == NULL)
		return (84);
	to_write = fill_linked_list(name, &error);
	if (error != 0)
		return (error);
	if (error)
		return (84);
//	to_write->next->next->label[0] = "label";
	error = replace_labels(to_write->next->next);
	if (error)
		return (84);
	error = write_exec(name, to_write);
	if (error)
		return (84);
	free_ll(to_write);
	free(name);
	return (0);
}