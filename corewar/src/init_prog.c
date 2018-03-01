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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

prog_name_t *fill_address(prog_name_t *prog, int nb_progs, int i, int total_size)
{
	int gap = (MEM_SIZE - total_size) / nb_progs;

	if (i == 0)
		prog->address = 0;
	if (i == 1)
		prog->address = prog->prev->size + gap;
	if (i == 2)
		prog->address = \
prog->prev->size + prog->prev->prev->size + gap * 2;
	if (i == 3)
		prog->address = prog->prev->size + \
prog->prev->prev->size + prog->prev->prev->prev->size + gap * 3;
	return (prog);
}

prog_name_t *fill_nb_prog(prog_name_t *prog)
{
	prog_name_t *current = prog;

	prog->prog_nb = 1;
	while (prog->prev != NULL) {
		prog = prog->prev;
		if (prog->prog_nb == current->prog_nb) {
			current->prog_nb++;
		}
	}
	prog = current;
	while (prog->next != NULL) {
		prog = prog->next;
		if (prog->prog_nb == current->prog_nb){
			current->prog_nb++;
		}
	}
	prog = current;
	return (prog);
}

int get_program_size(prog_name_t *prog)
{
	int fd = open(prog->name, O_RDONLY);
	char *str = malloc(sizeof(char) * (PROG_NAME_LENGTH + 8));
	int size;

	if (fd == -1 || str == NULL)
		return (-1);
	if (read(fd, str, PROG_NAME_LENGTH + 8) == -1)
		return (-1);
	if (read(fd, &size, sizeof(int)) == -1)
		return (-1);
	prog->size = rev_endiannes(size);
	free(str);
	close(fd);
	return (0);
}

args_t *fill_empty_args(args_t *args, int nb_prog)
{
	prog_name_t *first = args->progs;
	int total_size = 0;

	for (int i = 0; i < nb_prog; i++) {
		if (get_program_size(args->progs) == -1)
			return (NULL);
		total_size += args->progs->size;
		args->progs = args->progs->next;
	}
	args->progs = first;
	for (int i = 0; i < nb_prog; i++) {
		if (args->progs->address == -1) {
			args->progs = fill_address(args->progs, nb_prog, i, \
total_size);
		}
		if (args->progs->prog_nb == -1) {
			args->progs = fill_nb_prog(args->progs);
		}
		args->progs = args->progs->next;
	}
	args->progs = first;
	return (args);
}

prog_name_t *init_args_value(void)
{
	prog_name_t *prog = malloc(sizeof(prog_t));

	if (prog == NULL)
		return (NULL);
	prog->address = -1;
	prog->prog_nb = -1;
	prog->size = 0;
	return (prog);
}