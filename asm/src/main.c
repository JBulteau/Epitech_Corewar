/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int write_file(int *error, char *name, node_t *to_write)
{
	int fd = 0;

	if (*error == 42) {
		fd = open_new_file(name);
		if (fd == -1) {
			return (-1);
		}
		write_header(fd, to_write->label[0], \
to_write->next->label[0], 0);
		close(fd);
	} else {
		*error = replace_labels(to_write->next);
		if (*error)
			return (-1);
		*error = write_exec(name, to_write);
	}
	return (0);
}

int disp_err_msg(int error)
{
	char *errors[] = {ERR_EMPTY, USAGE, NO_NAME, NO_COMMENT, ERR_SYNTAX, \
ERR_INV_INS, ERR_INV_LAB, ERR_MUL_LAB, ERR_INV_REG, ERR_INV_ARG, \
ERR_TOOMANY_ARGS, ERR_MANY_NAMES, ERR_MANY_COMMENT, ERR_NAME_FIRSTLN, \
ERR_TOOLONG_NAME, ERR_COMM_AFTER_NAME, ERR_TOOLONG_COMM, ERR_UNDEF_LAB, \
ERR_UNDEF_COMM, ERR_UNDEF_NAME, FILE_NOTFOUND};

	my_putstr(errors[-error - 1]);
	my_putchar('\n');
	return (84);
}

int main(int ac, char **av)
{
	node_t *to_write;
	int error = 0;
	char *name;

	if ((ac == 1) || my_strcmp(av[1], "-h", -1))
		return (my_putstr(USAGE), 0);
	name = get_fn(av[1]);
	if (name == NULL)
		return (84);
	to_write = fill_linked_list(name, &error);
	if (error != 0 && error != 42 || (to_write == NULL))
		return (disp_err_msg(error));
	if (write_file(&error, name, to_write))
		return (disp_err_msg(error));
	if (error && error != 42)
		return (disp_err_msg(error));
	free_linked_list(to_write);
	free(name);
	if (ac > 2)
		main(ac - 1, av + 1);
	return (0);
}