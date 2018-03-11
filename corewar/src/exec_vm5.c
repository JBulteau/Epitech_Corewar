/*
** EPITECH PROJECT, 2018
** exec_vm5
** File description:
** instru
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int lldi_bis(int reg2, int type_arg_2, prog_t *prog, unsigned char *arena)
{
	int reg1 = prog->instr.args[1];
	int reg = prog->instr.args[2];

	if (reg2 < 1 || reg2 > REG_NUMBER)
		return (-1);
	if (type_arg_2 == 1) {
		if (reg1 < 1 || reg1 > REG_NUMBER)
			return (-1);
		prog->reg[reg - 1] =
			arena[(prog->pc + prog->reg[prog->instr.args[0] - 1] +
			       prog->reg[prog->instr.args[1] - 1]) % MEM_SIZE];
	} else
                prog->reg[reg - 1] =
			arena[prog->pc + prog->reg[prog->instr.args[0] - 1]
			     + prog->instr.args[1]];
	return (0);
}

int lldi_bis2(int reg1, prog_t *prog, unsigned char *arena, int reg)
{
	if (reg1 < 1 || reg1 > REG_NUMBER)
		return (-1);
	prog->reg[reg - 1] = \
		arena[prog->instr.args[0] + prog->reg[prog->instr.args[1]]];
	return (0);
}
