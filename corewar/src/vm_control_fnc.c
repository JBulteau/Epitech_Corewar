/*
** EPITECH PROJECT, 2017
** scheduler.c
** File description:
** Scheduler
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

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

int count_alive(vm_t *vm)
{
	int alive = 0;

	for (int i = 0; vm->live[i] != -2; i++)
		if (vm->live[i] == 1)
			alive++;
	return (alive);
}

void check_cycle(vm_t *vm)
{
	int alive = 0;

	do {
		my_printf("RESET LIVE\n");
		for (int i = 0; vm->live[i] != -2; i++)
			if (vm->live[i] == 1)
				vm->live[i] = 0;
		for (; vm->current_cycle < vm->cycle_to_die \
&& vm->current_cycle != vm->dump; vm->current_cycle++)
			scheduler(vm);
		if (vm->current_cycle == vm->dump) {
			disp_arena(vm);
			break;
		}
		vm->cycle_to_die += vm->cycle_to_die - CYCLE_DELTA;
		alive = count_alive(vm);
		for (int i = 0; vm->live[i] != -2; i++)
			if (vm->live[i] == 0) {
				vm->live[i] = -1;
				my_printf("Champion n°%i died.\n", i + 1);
			}
	} while (alive > 1);
}