/*
** EPITECH PROJECT, 2017
** instruct_func.c
** File description:
** function for the instru
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int live(char *arena, prog_t *prog)
{
	arena = arena;
	return (prog->instr.args[0]);
}

int ld(char *arena, prog_t *prog)
{
	int reg = prog->instr.args[1];
	int arg = prog->instr.arg_type >> (6 - (nb_arg * 2)) & 0b11;

	if (arg == 3)
		prog->reg[reg - 1] = (prog->pc + prog->instr.args[0]) % IDX_MOD;
	else
		prog->reg[reg - 1] = arena[prog->instr.args[0]];
	prog->carry = 1;
}