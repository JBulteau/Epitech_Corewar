/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
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

int main(int ac, char **av)
{
	args_t *args = NULL;

	if ((ac == 2) && (av[1][0] == '-') && (av[1][1] == 'h')) {
		my_printf(HELP, MEM_SIZE);
		return (0);
	} else {
		args = check_args(ac, av);
		while (args->progs->prev != NULL)
			args->progs = args->progs->prev;
		if (args->progs->name == NULL)
			error(NO_CHAMPION, args);
	}
	return (0);
}