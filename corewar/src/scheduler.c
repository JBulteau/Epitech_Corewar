/*
** EPITECH PROJECT, 2017
** scheduler.c
** File description:
** Scheduler
*/

#include <unistd.h>
#include "my.h"
#include "corewar.h"

int (*exec_fnc[16])(unsigned char *arena, prog_t *prog) =
{
	&live,
	&ld,
	&st,
	&add,
	&sub,
	&and,
	&or,
	&xor,
	&zjmp,
	&ldi,
	&sti,
	&fork_exec,
	&lld,
	&lldi,
	&lfork,
	&aff
};

int execute(vm_t *vm, prog_t *prog, prog_name_t *prog_name)
{
	int prog_c = 0;
	int return_v = exec_fnc[prog->instr.op_code - 1](vm->arena, prog);

	if (return_v > 0) {
		for (; vm->live[prog_c] != -2; prog_c++);
		if (return_v <= prog_c && vm->live[return_v - 1] == 0) {
			vm->live[return_v - 1] = 1;
			my_printf("The player %i(%s) is alive.\n", return_v, \
&prog_name->prog_name[4]);
		}
		return (0);
	}
	return (return_v);
}

int scheduler_cycle(prog_t *current, vm_t *vm, prog_name_t *prog_name)
{
	char changes_carry[] = {2, 3, 4, 5, 6, 7, 8, 10, 13, 14, 0};

	if (indexof(current->instr.op_code, changes_carry) != -1)
		current->carry = 0;
	if (current->instr.op_code > 0)
		if (execute(vm, current, prog_name) != -1) {
			current->pc = (current->instr.op_code == 9) ? \
current->pc : (current->pc + size(current->instr)) % MEM_SIZE;
		} else
			current->pc++;
	current->instr = read_instru(vm->arena, current->pc);
	if ((current->instr.arg_type == -1) || \
(current->instr.op_code == -1)) {
		current->pc++;
		return (-42);
	}
	current->cycle_wait = op_tab[current->instr.op_code - 1].nbr_cycles;
}

int scheduler(vm_t *vm, args_t *args)
{
	prog_name_t *first = args->progs;

	for (prog_t *current = vm->prog[0]; current != NULL; current = \
current->next) {
		if (current->cycle_wait == 0)
			scheduler_cycle(current, vm, args->progs);
		else
			current->cycle_wait--;
		args->progs = args->progs->next;
	}
	args->progs = first;
	return (0);
}