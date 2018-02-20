/*
** EPITECH PROJECT, 2017
** main.c
** File description
** Main file
*/

#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"



int main(int ac, char **av)
{
	int error = 0;

	if (0 && (ac == 1) || my_strcmp(av[1], "-h", -1)) {
		my_putstr(USAGE);
		return (0);
	}
	if (write_exec(get_fn(av[1])) == -1)
		return (84);
	fill_linked_list("test", &error);
	return (0);
}