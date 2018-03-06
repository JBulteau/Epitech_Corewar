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
	int prog_c = 0;
	int return_v = exec_fnc[prog->instr.op_code - 1](vm->arena, prog);

	my_printf("%i EXEC --> %s\n", prog->pc, op_tab[prog->instr.op_code - 1].mnemonique);
	if (return_v > 0) {
		printf("Live %i\n", return_v);
		for (; vm->live[prog_c] != -2; prog_c++);
		if (return_v <= prog_c && vm->live[return_v - 1] == 0) {
			vm->live[return_v - 1] = 1;
			my_printf("programm %i is alive !\n", return_v);
		}
	}
}

int scheduler(vm_t *vm)
{
	char changes_carry[] = {2, 3, 4, 5, 6, 7, 8, 10, 13, 14, 0};

	//for (int i = 0; i < 30; i++) //FORCED CYCLES
	for (prog_t *current = vm->prog[0]; current != NULL; current = current->next) {
		if (current->cycle_wait == 0) {
			//my_putchar('\n');
			if (indexof(current->instr.op_code, changes_carry) != -1) {
				//my_put_nbr(current->instr.op_code);
				//my_putstr("RESET CARRY\n");
				current->carry = 0;
			}
			if (current->instr.op_code > 0) {
				execute(vm, current);
				//my_putstr("\nEXECUTE\n");
				//my_putstr("MV PC to next instru\n");
				current->pc = (current->pc + size(current->instr)) % MEM_SIZE;
			}
			current->instr = read_instru(vm->arena, current->pc);
			//my_putstr("LOAD INSTRU\n");
			//disp_instruction(current->instr);
			if ((current->instr.arg_type == -1) || (current->instr.op_code == -1)) {
				current->pc++;
				//my_putstr("Mv PC to +1\n");
				continue;
			}
			current->cycle_wait = op_tab[current->instr.op_code - 1].nbr_cycles;
		} else {
			//my_putstr("Wait-");
			current->cycle_wait--;
		}
	}
	return (0);
} /* scheduler */