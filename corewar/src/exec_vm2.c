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

	if ((int*)arena && type_arg_1 == 1) {
		if (type_arg_2 == 1)
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] ^ prog->reg[(prog->instr.args[1]) - 1];
		else
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] ^ prog->instr.args[1];
	} else {
		if (type_arg_2 == 1)
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->instr.args[0] ^ prog->reg[(prog->instr.args[1]) - 1];
		else
			prog->reg[(prog->instr.args[0]) - 1] = \
prog->instr.args[0] ^ prog->instr.args[1];
	}
	prog->carry = 1;
	return (0);
}

int zjmp(unsigned char *arena, prog_t *prog)
{
	if (prog->carry != 1)
		return (0);
	prog->pc = (prog->pc + prog->instr.args[0]) % IDX_MOD;
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

	if (type_arg_1 == 1)
		if (type_arg_2 == 1)
			arena[(prog->pc + prog->reg[prog->instr.args[1] - 1] + \
prog->reg[prog->instr.args[2]] - 1) % IDX_MOD] = prog->reg[reg - 1];
		else
			arena[(prog->pc + prog->reg[prog->instr.args[1] - 1] + \
prog->instr.args[2]) % IDX_MOD] = prog->reg[reg - 1];
	else
		if (type_arg_2 == 1)
			arena[(prog->pc + prog->instr.args[1] + \
prog->reg[prog->instr.args[2] - 1]) % IDX_MOD] = prog->reg[reg - 1];
		else
			arena[(prog->pc + prog->instr.args[1] + \
prog->instr.args[2]) % IDX_MOD] = prog->reg[reg - 1];
	return (0);
}