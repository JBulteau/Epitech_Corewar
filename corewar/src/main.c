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
#include <stdlib.h>

void display_winner(args_t *args, vm_t *vm)
{
	for (int i = 0; vm->live[i] != -2; i++) {
		if (vm->live[i] == 1 && (vm->cycle_to_die > 0))
			my_printf("The player %i(%s) has won.\n", i + 1, \
&args->progs->prog_name[4]);
		args->progs = args->progs->next;
	}
}

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

int main(int ac, char **av)
{
	args_t *args = NULL;
	vm_t *vm;
	int nb_prog = 0;

	help(ac, av);
	args = init_args(ac, av, &nb_prog);
	args = fill_empty_args(args, nb_prog);
	vm = init_vm(nb_prog, args);
	if (vm == NULL)
		return (84);
	fill_struct_vm_prog(nb_prog, vm, args);
	if (vm == NULL)
		return (84);
	check_cycle(vm, args);
	display_winner(args, vm);
	free_vm(vm, args);
	return (0);
}