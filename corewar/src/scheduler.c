/*
** EPITECH PROJECT, 2017
** scheduler.c
** File description:
** Scheduler
*/

#include <unistd.h>
#include "my.h"
#include "corewar.h"

int (*exec_fnc[16])(unsigned char *arena, prog_t *prog) = {
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

int execute(vm_t *vm, prog_t *prog)
{
	my_printf("[%i] %i EXEC --> %s\n", prog->nb_prog, prog->pc, \
op_tab[prog->instr.op_code - 1].mnemonique);
	int prog_c = 0;
	int return_v = exec_fnc[prog->instr.op_code - 1](vm->arena, prog);

	if (return_v > 0) {
		my_printf("Live %i\n", return_v);
		for (; vm->live[prog_c] != -2; prog_c++);
		if (return_v <= prog_c && vm->live[return_v - 1] == 0) {
			vm->live[return_v - 1] = 1;
			my_printf("[%i] programm %i is alive !\n", prog->nb_prog, return_v);
		}
	}
}

int scheduler_cycle(prog_t *current, vm_t *vm)
{
	char changes_carry[] = {2, 3, 4, 5, 6, 7, 8, 10, 13, 14, 0};

	if (current->cycle_wait == 0) {
		if (indexof(current->instr.op_code, changes_carry) != -1)
			current->carry = 0;
		if (current->instr.op_code > 0) {
			execute(vm, current);
			current->pc = (current->instr.op_code == 9) ? current->pc : (current->pc + size(current->instr)) % MEM_SIZE;
		}
		current->instr = read_instru(vm->arena, current->pc);
		if ((current->instr.arg_type == -1) || \
(current->instr.op_code == -1)) {
			current->pc++;
			return (-42);
		}
		my_printf("[%i] LOADED INSTRU AT PC = %i\n", current->nb_prog, current->pc);
		current->cycle_wait = \
op_tab[current->instr.op_code - 1].nbr_cycles;
	} else {
		//my_printf("[%i] Waiting %i cycles\n", current->nb_prog, current->cycle_wait);
		current->cycle_wait--;
	}
}

int scheduler(vm_t *vm)
{

	for (prog_t *current = vm->prog[0]; current != NULL; current = \
current->next) {
		scheduler_cycle(current, vm);
	}
	my_printf("Cycle n° %i\n", vm->current_cycle);
	return (0);
}
