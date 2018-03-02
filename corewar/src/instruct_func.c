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
	int arg = prog->instr.arg_type >> (6 - (0 * 2)) & 0b11;

	if (arg == 3)
		prog->reg[reg - 1] = (prog->pc + prog->instr.args[0]) % IDX_MOD;
	else
		prog->reg[reg - 1] = arena[prog->instr.args[0]];
	prog->carry = 1;
	return (0);
}

int st(char *arena, prog_t *prog)
{
	int reg = prog->instr.args[0];
	int type_arg = prog->instr.arg_type >> (6 - (1 * 2)) & 0b11;

	if (type_arg != 3)
		prog->reg[(prog->instr.args[1]) - 1] = prog->reg[reg - 1];
	else
		arena[((prog->pc) + (prog->instr.args[1]) % IDX_MOD)] = \
prog->reg[reg - 1];
	return (0);
}

int add(char *arena, prog_t *prog)
{
	prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[1]) - 1] + prog->reg[(prog->instr.args[0]) - 1];
	prog->carry = 1;
	arena = arena;
	return (0);
}

int sub(char *arena, prog_t *prog)
{
	prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[1]) - 1] - prog->reg[(prog->instr.args[0]) - 1];
	prog->carry = 1;
	arena = arena;
	return (0);
}

int and(char *arena, prog_t *prog)
{
	return (0);
}

int or(char *arena, prog_t *prog)
{
	return (0);
}

int xor(char *arena, prog_t *prog)
{
	return (0);
}

int zjmp(char *arena, prog_t *prog)
{
	if (prog->carry != 1)
		return (0);
	prog->pc = (prog->pc + prog->instr.args[0]) % IDX_MOD;
	arena = arena;
	return (0);
}

int ldi(char *arena, prog_t *prog)
{
	return (0);
}

int sti(char *arena, prog_t *prog)
{
	return (0);
}

int fork_exec(char *arena, prog_t *prog)
{
	return (0);
}

int lld(char *arena, prog_t *prog)
{
	return (0);
}

int lldi(char *arena, prog_t *prog)
{
	return (0);
}

int lfork(char *arena, prog_t *prog)
{
	return (0);
}

int aff(char *arena, prog_t *prog)
{
	return (!my_putchar((prog->reg[(prog->instr.args[0]) - 1]) % 256));
}