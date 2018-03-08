/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** check_vm_main
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

args_t *check_args(int ac, char **av)
{
	int nb_args = 0;
	args_t *args = malloc(sizeof(args_t));

	if (args == NULL)
		exit(84);
	for (int i = 1; av[i] != NULL; i++)
		if (my_strcmp(av[i], "-dump", -1))
			nb_args++;
	return (check_dump(args, ac, av, nb_args));
}
