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
	// TODO : free arggs fnc
	// TODO : vérifier args != NULL
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

void check_cycle(vm_t *vm, int i)
{
	int alive = 0;

	do {
		for (int i = 0; vm->live[i] != -2; i++)
			if (vm->live[i] == 1)
				vm->live[i] = 0;
		for (; vm->current_cycle < 100; vm->current_cycle++)
			scheduler(vm);
		vm->current_cycle = 0;
		vm->cycle_to_die -= CYCLE_DELTA;
		alive = count_alive(vm);
		for (int i = 0; vm->live[i] != -2; i++)
			if (vm->live[i] == 0) {
				free_dead_prog(vm->live[i]);
				my_printf("Champion n°%i died.\n", i + 1);
			}
	} while (alive > 1);
}

int main(int ac, char **av)
{
	args_t *args = NULL;
	vm_t *vm;
	int i = 0;
	int nb_prog = 0;

	help(ac, av);
	args = init_args(ac, av, &nb_prog);
	args = fill_empty_args(args, nb_prog);
	vm = init_vm(nb_prog, args);
	fill_struct_vm_prog(nb_prog, vm);
	for (prog_name_t *curr = args->progs; curr->next != NULL; (curr = curr->next) && i++) {
		vm->prog[i]->pc = curr->address;
		vm->prog[i]->start_adr = curr->address;
		vm->prog[i]->size = curr->size;
		vm->prog[i]->nb_prog = i;
		vm->prog[i]->reg[0] = i + 1;
	}
	if (vm == NULL)
		return (84);
	check_cycle(vm, i);
	for (int i = 0; vm->live[i] != -2; i++)
		if (vm->live[i] && (vm->cycle_to_die > 0))
			my_printf("Champion n°%i won.\n", i + 1);
	free_vm(vm, args);
	return (0);
} /* main */
