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

int live(unsigned char *arena, prog_t *prog)
{
	arena = arena;
	return (prog->instr.args[0]);
}

int ld(unsigned char *arena, prog_t *prog)
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

int st(unsigned char *arena, prog_t *prog)
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

int add(unsigned char *arena, prog_t *prog)
{
	prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[1]) - 1] + prog->reg[(prog->instr.args[0]) - 1];
	prog->carry = 1;
	arena = arena;
	return (0);
}

int sub(unsigned char *arena, prog_t *prog)
{
	prog->reg[(prog->instr.args[2]) - 1] = \
prog->reg[(prog->instr.args[1]) - 1] - prog->reg[(prog->instr.args[0]) - 1];
	prog->carry = 1;
	arena = arena;
	return (0);
}

int and(unsigned char *arena, prog_t *prog)
{
	return (0);
}

int or(unsigned char *arena, prog_t *prog)
{
	return (0);
}

int xor(unsigned char *arena, prog_t *prog)
{
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
	return (0);
}

int sti(unsigned char *arena, prog_t *prog)
{
	return (0);
}

int fork_exec(unsigned char *arena, prog_t *prog)
{
	return (0);
}

int lld(unsigned char *arena, prog_t *prog)
{
	return (0);
}

int lldi(unsigned char *arena, prog_t *prog)
{
	return (0);
}

int lfork(unsigned char *arena, prog_t *prog)
{
	return (0);
}

int aff(unsigned char *arena, prog_t *prog)
{
	return (!my_putchar((prog->reg[(prog->instr.args[0]) - 1]) % 256));
}