/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** virtual machine for corewar
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

int rev_endiannes(int nb)
{
	int res = 0;

	for (int i = 0; i < 4; i++) {
		if (res)
			res = res << 8;
		res += nb >> (8 * i) & (0xff);
	}
	return (res);
}

void error(char *str, args_t *args)
{
	if (str != NULL)
		write(2, str, my_strlen(str));
	if (args->progs != NULL) {
		while (args->progs->next != NULL)
			args->progs = args->progs->next;
		while (args->progs->prev != NULL) {
			args->progs = args->progs->prev;
			free(args->progs->next);
		}
		free(args->progs);
	}
	free(args);
	exit(84);
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

args_t *init_args(int ac, char **av, int *nb_progs)
{
	args_t *args = check_args(ac, av);

	while (args->progs->prev != NULL)
		args->progs = args->progs->prev;
	if (args->progs->name == NULL)
		error(NO_CHAMPION, args);
	for (*nb_progs = 0; args->progs->name != NULL; *nb_progs += 1)
		if (args->progs->next != NULL)
			args->progs = args->progs->next;
	while (args->progs->prev != NULL)
		args->progs = args->progs->prev;
	if (*nb_progs > 4)
		error(TOO_MANY_CHAMP, args);
	return (args);
}


int main(int ac, char **av)
{
	args_t *args = NULL;
	vm_t *vm;
	int nb_prog = 0;

	if ((ac == 2) && (my_strcmp(av[1], "-h", -1) \
|| my_strcmp(av[1], "--help", -1))) {
		my_printf(HELP, MEM_SIZE);
		return (0);
	}
	args = init_args(ac, av, &nb_prog);
	args = fill_empty_args(args, nb_prog);
	vm = init_vm(nb_prog, args);
	if (vm == NULL)
		return (84);
	return (0);
}