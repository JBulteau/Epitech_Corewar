/*
** EPITECH PROJECT, 2017
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
#include <stdlib.h>

void free_vm(vm_t *vm, args_t *args)
{
	free(vm->live);
	free(vm->prog);
	free(vm);
	free(args);
}

void help(int ac, char **av)
{
	if ((ac == 2) && (my_strcmp(av[1], "-h", -1)		\
			  || my_strcmp(av[1], "--help", -1))) {
		my_printf(HELP, MEM_SIZE);
		exit(0);
	}
}

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

void free_progs(prog_t *prog)
{
	if (prog == NULL)
		return;
	if (prog->next)
		free_progs(prog->next);
	free(prog);
}
