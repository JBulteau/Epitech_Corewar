/*
** EPITECH PROJECT, 2017
** exec_vm0.c
** File description:
** function for the instru
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int st(unsigned char *arena, prog_t *prog)
{
	int reg = prog->instr.args[0];
	int type_arg = prog->instr.arg_type >> 4 & 0b11;

	if (type_arg == 1)
		prog->reg[(prog->instr.args[1]) - 1] = prog->reg[reg - 1];
	else
		arena[((prog->pc) + (prog->instr.args[1]) % IDX_MOD)] = \
prog->reg[reg - 1];
	return (0);
}

int add(unsigned char *arena, prog_t *prog)
{
	(void)arena;
	prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[1]) - 1] + prog->reg[(prog->instr.args[0]) - 1];
	prog->carry = 1;
	return (0);
}

int sub(unsigned char *arena, prog_t *prog)
{
	(void)arena;
	prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[1]) - 1] - prog->reg[(prog->instr.args[0]) - 1];
	prog->carry = 1;
	return (0);
}

int and(unsigned char *arena, prog_t *prog)
{
	int type_arg_1 = prog->instr.arg_type >> 6 & 0b11;
	int type_arg_2 = prog->instr.arg_type >> 4 & 0b11;

	(void)arena;
	if (type_arg_1 == 1)
		if (type_arg_2 == 1)
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] & prog->reg[(prog->instr.args[1]) - 1];
		else
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] & prog->instr.args[1];
	else
		if (type_arg_2 == 1)
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->instr.args[0] & prog->reg[(prog->instr.args[1]) - 1];
		else
			prog->reg[(prog->instr.args[0]) - 1] = \
prog->instr.args[0] & prog->instr.args[1];
	prog->carry = 1;
	return (0);
}

int or(unsigned char *arena, prog_t *prog)
{
	int type_arg_1 = prog->instr.arg_type >> 6 & 0b11;
	int type_arg_2 = prog->instr.arg_type >> 4 & 0b11;

	(void)arena;
	if (type_arg_1 == 1)
		if (type_arg_2 == 1)
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] | prog->reg[(prog->instr.args[1]) - 1];
		else
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[0]) - 1] | prog->instr.args[1];
	else
		if (type_arg_2 == 1)
			prog->reg[(prog->instr.args[2]) - 1] = \
prog->instr.args[0] | prog->reg[(prog->instr.args[1]) - 1];
		else
			prog->reg[(prog->instr.args[0]) - 1] = \
prog->instr.args[0] | prog->instr.args[1];
	prog->carry = 1;
	return (0);
}