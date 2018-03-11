/*
** EPITECH PROJECT, 2017
** exec_vm4
** File description:
** f for the instru
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int and_bis(prog_t *prog, int reg2, int type_arg_2, int reg1)
{
	if (reg2 < 1 || reg2 > REG_NUMBER)
		return (-1);
	if (type_arg_2 == 1) {
		if (reg1 < 1 || reg1 > REG_NUMBER)
			return (-1);
		prog->reg[(prog->instr.args[2]) - 1] = \
			prog->reg[(prog->instr.args[0]) - 1]
			& prog->reg[(prog->instr.args[1]) - 1];
	} else
		prog->reg[(prog->instr.args[2]) - 1] = \
			prog->reg[(prog->instr.args[0]) - 1]
			& prog->instr.args[1];
	return (0);
}

int and_bis2(int reg1, prog_t *prog)
{
	if (reg1 < 1 || reg1 > REG_NUMBER)
		return (-1);
	prog->reg[(prog->instr.args[2]) - 1] = \
		prog->instr.args[0] & \
		prog->reg[(prog->instr.args[1]) - 1];
}

int or_bis(prog_t *prog, int reg2, int type_arg_2, int reg1)
{
	if (reg2 < 1 || reg2 > REG_NUMBER)
		return (-1);
	if (type_arg_2 == 1) {
		if (reg1 < 1 || reg1 > REG_NUMBER)
			return (-1);
		prog->reg[(prog->instr.args[2]) - 1] =			\
			prog->reg[(prog->instr.args[0]) - 1]
			| prog->reg[(prog->instr.args[1]) - 1];
	} else
		prog->reg[(prog->instr.args[2]) - 1] = \
			prog->reg[(prog->instr.args[0]) - 1]
			| prog->instr.args[1];
	return (0);
}

int or_bis2(int reg1, prog_t *prog)
{
	if (reg1 < 1 || reg1 > REG_NUMBER)
		return (-1);
	prog->reg[(prog->instr.args[2]) - 1] = \
		prog->instr.args[0] \
		| prog->reg[(prog->instr.args[1]) - 1];
}
