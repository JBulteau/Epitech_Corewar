/*
** EPITECH PROJECT, 2017
** exec_vm2.c
** File description:
** function for the instru
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int xor(unsigned char *arena, prog_t *prog)
{
	int type_arg_1 = prog->instr.arg_type >> 6 & 0b11;
	int type_arg_2 = prog->instr.arg_type >> 4 & 0b11;
	int reg0 = prog->instr.args[2];
	int reg1 = prog->instr.args[1];
	int reg2 = prog->instr.args[0];

	if (reg0 < 1 || reg0 > REG_NUMBER)
		return (-1);
	(void)arena;
	if (type_arg_1 == 1) {
		if (reg2 < 1 || reg2 > REG_NUMBER)
			return (-1);
		if (type_arg_2 == 1) {
			if (reg1 < 1 || reg1 > REG_NUMBER)
				return (-1);
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] ^ prog->reg[(prog->instr.args[1]) - 1];
		} else
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] ^ prog->instr.args[1];
	} else
		if (type_arg_2 == 1) {
			if (reg1 < 1 || reg1 > REG_NUMBER)
				return (-1);
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->instr.args[0] ^ prog->reg[(prog->instr.args[1]) - 1];
		} else
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->instr.args[0] ^ prog->instr.args[1];
	prog->carry = 1;
	return (0);
}

int zjmp(unsigned char *arena, prog_t *prog)
{
	if (prog->carry != 1)
		return (0);
	my_printf("[%i] zjump from %i to %i\n", prog->nb_prog, prog->pc, (prog->pc + (short)(prog->instr.args[0]) % IDX_MOD) % MEM_SIZE);
	prog->pc = (prog->pc + (short)(prog->instr.args[0]) % IDX_MOD) % MEM_SIZE;
	arena = arena;
	return (0);
}

int ldi(unsigned char *arena, prog_t *prog)
{
	int reg = prog->instr.args[2];
	int type_arg_1 = prog->instr.arg_type >> 6 & 0b11;
	int type_arg_2 = prog->instr.arg_type >> 4 & 0b11;

	if (type_arg_1 == 1)
		if (type_arg_2 == 1)
			prog->reg[reg - 1] = arena[(prog->pc + prog->reg[prog->\
instr.args[0] - 1] + prog->reg[prog->instr.args[1] - 1]) % IDX_MOD];
		else
			prog->reg[reg - 1] = arena[(prog->pc + prog->reg[prog->\
instr.args[0] - 1] + prog->instr.args[1]) % IDX_MOD];
	else
		if (type_arg_2 == 1)
			prog->reg[reg - 1] = \
arena[(prog->instr.args[0] + prog->reg[prog->instr.args[1]]) % IDX_MOD];
		else
			prog->reg[reg - 1] = \
arena[(prog->instr.args[0] + prog->instr.args[1]) % IDX_MOD];
	prog->carry = 1;
	return (0);
}

int sti(unsigned char *arena, prog_t *prog)
{
	int reg = prog->instr.args[0];
	int type_arg_1 = prog->instr.arg_type >> 4 & 0b11;
	int type_arg_2 = prog->instr.arg_type >> 2 & 0b11;
	 
	if (reg < 0 || reg > REG_NUMBER)
		return (-1);
	if (type_arg_1 == 1)
		if (type_arg_2 == 1)
			cp_reg_to_arena(arena, prog->pc + (prog->reg[prog->ins\
tr.args[1] - 1] + prog->reg[prog->instr.args[2]] - 1) % IDX_MOD, prog->reg\
[reg - 1]);
		else
			cp_reg_to_arena(arena, prog->pc + (prog->reg[prog->ins\
tr.args[1] - 1] + prog->instr.args[2]) % IDX_MOD, prog->reg[reg - 1]);
	else
		if (type_arg_2 == 1)
			cp_reg_to_arena(arena, prog->pc + (prog->instr.args[1\
] + prog->reg[prog->instr.args[2] - 1]) % IDX_MOD, prog->reg[reg - 1]);
		else
			cp_reg_to_arena(arena, prog->pc + (prog->instr.args[1\
] + prog->instr.args[2]) % IDX_MOD, prog->reg[reg - 1]);
	return (0);
}
