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

	if (reg < 1 || reg > REG_NUMBER)
		return (-1);
	if (type_arg == 1)
		prog->reg[(prog->instr.args[1]) - 1] = prog->reg[reg - 1];
	else
		arena[((((prog->pc) + (prog->instr.args[1])) % \
IDX_MOD) % MEM_SIZE)] = prog->reg[reg - 1];
	return (0);
}

int add(unsigned char *arena, prog_t *prog)
{
	int reg0 = prog->instr.args[2];
	int reg1 = prog->instr.args[1];
	int reg2 = prog->instr.args[0];

	if (reg0 < 1 || reg0 > REG_NUMBER || reg1 < 1 || reg1 > REG_NUMBER || \
reg2 < 1 || reg2 > REG_NUMBER)
		return (-1);
	(void)arena;
	prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[1]) - 1] + prog->reg[(prog->instr.args[0]) - 1];
	prog->carry = 1;
	return (0);
}

int sub(unsigned char *arena, prog_t *prog)
{
	int reg0 = prog->instr.args[2];
	int reg1 = prog->instr.args[1];
	int reg2 = prog->instr.args[0];

	if (reg0 < 1 || reg0 > REG_NUMBER || reg1 < 1 || reg1 > REG_NUMBER || \
reg2 < 1 || reg2 > REG_NUMBER)
		return (-1);
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
	int reg0 = prog->instr.args[2];
	int reg1 = prog->instr.args[1];
	int reg2 = prog->instr.args[0];

	(void)arena;
	if (reg0 < 1 || reg0 > REG_NUMBER)
		return (-1);
	if (type_arg_1 == 1) {
		if (and_bis(prog, reg2, type_arg_2, reg1) == -1)
			return (-1);
	} else
		if (type_arg_2 == 1 && and_bis2(reg1, prog) == -1) {
			return (-1);
		} else
			prog->reg[(prog->instr.args[2]) - 1] =		\
				prog->instr.args[0] & prog->instr.args[1];
	prog->carry = 1;
	return (0);
}

int or(unsigned char *arena, prog_t *prog)
{
	int type_arg_1 = prog->instr.arg_type >> 6 & 0b11;
	int type_arg_2 = prog->instr.arg_type >> 4 & 0b11;
	int reg0 = prog->instr.args[2];
	int reg1 = prog->instr.args[1];
	int reg2 = prog->instr.args[0];

	(void)arena;
	if (reg0 < 1 || reg0 > REG_NUMBER)
		return (-1);
	if (type_arg_1 == 1)
		if (or_bis(prog, reg2, type_arg_2, reg1) == -1)
			return (-1);
	else
		if (type_arg_2 == 1 && or_bis2(reg1, prog) == -1) {
			return (-1);
		} else
			prog->reg[(prog->instr.args[2]) - 1] =		\
				prog->instr.args[0] | prog->instr.args[1];
	prog->carry = 1;
	return (0);
}