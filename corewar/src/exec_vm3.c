/*
** EPITECH PROJECT, 2017
** exec_vm3.c
** File description:
** function for the instru
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int live(unsigned char *arena, prog_t *prog)
{
	(void)arena;
	return (prog->instr.args[0]);
}

int ld(unsigned char *arena, prog_t *prog)
{
	int reg = prog->instr.args[1];
	int arg = prog->instr.arg_type >> 6 & 0b11;

	if (arg == 1)
		prog->reg[reg - 1] = prog->reg[prog->instr.args[0] - 1];
	else
		prog->reg[reg - 1] = \
arena[(prog->pc + prog->instr.args[0]) % IDX_MOD];
	prog->carry = 1;
	return (0);
}