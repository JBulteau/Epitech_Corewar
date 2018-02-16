/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** corewar
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

args_t *check_prog(args_t *args, char *str)
{
	int fd = open(str, O_RDONLY);
	int magic_number = 0;

	if (fd == -1)
		error(NULL, args);
	my_revstr(str);
	if (!my_strcmp(str, "roc.", 4)) {
		my_revstr(str);
		write(2, str, my_strlen(str));
		error(NOT_EXEC, args);
	}
	read(fd, &magic_number, 4);
	magic_number = rev_endiannes(magic_number);
	if (magic_number != COREWAR_EXEC_MAGIC)
		error(WRONG_MAGIC_NB, args);
	close(fd);
	args->progs->name = malloc(sizeof(char) * (my_strlen(str) + 1));
	if (args->progs->name == NULL)
		error(NULL, args);
	my_strcpy(args->progs->name, str, -1);
	return (args);
} /* check_prog */

args_t *check_adress(args_t *args, char *str)
{
	int adress = hexa_to_deca(str);

	if (adress == -1)
		error(INVALID_OFFSET, args);
	args->progs->adress = adress % MEM_SIZE;
	return (args);
}

args_t *check_prog_number(args_t *args, char *str)
{
	int prog_number = my_getnbr(str);

	if ((prog_number > 4) || (prog_number < 1))
		error(INVALID_N_NB, args);
	args->progs->prog_nb = prog_number;
	return (args);
}

args_t *check_flags(args_t *args, int ac, char **av)
{
	args->progs = malloc(sizeof(prog_t));
	if (args->progs == NULL)
		error(NULL, args);
	args->progs->prev = NULL;
	for (int i = 3; i < ac; i++) {
		if ((av[i][0] == '-') && (av[i][1] == 'n')) {
			args = check_prog_number(args, av[i++]);
			continue;
		} else if ((av[i][0] == '-') && (av[i][1] == 'a')) {
			args = check_adress(args, av[i++]);
			continue;
		}
		args = check_prog(args, av[i]);
		args->progs->next = malloc(sizeof(prog_t));
		if (args->progs->next == NULL)
			error(NULL, args);
		args->progs->next->prev = args->progs;
		args->progs = args->progs->next;
	}
	return (args);
}

args_t *check_dump(args_t *args, int ac, char **av, int nb_args)
{
	if (nb_args > 1)
		error(DOUBLE_DUMP, args);
	else if (nb_args == 0)
		error(NO_DUMP, args);
	if (my_strcmp(av[1], "-dump", -1)) {
		if (av[2] == NULL)
			error(NO_DUMP, args);
		if (args->dump = hexa_to_deca(av[2]) == -1)
			error(NEG_DUMP, args);
	} else
		error(MISPLACED_DUMP, args);
	return (check_flags(args, ac, av));
}