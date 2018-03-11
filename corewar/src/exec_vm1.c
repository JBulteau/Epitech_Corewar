/*
** EPITECH PROJECT, 2017
** exec_vm1.c
** File description:
** function for the instru
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int fork_exec(unsigned char *arena, prog_t *prog)
{
	int i;

	if (prog->pc >= prog->start_adr)
		for (i = prog->pc + 3; i < prog->start_adr + prog->size; i++)
			arena[((i + prog->instr.args[0]) % IDX_MOD) % MEM_SIZE]\
= arena[i % MEM_SIZE];
	else
		for (i = prog->pc + 3; i < prog->start_adr + prog->size - \
MEM_SIZE; i++)
			arena[((i + prog->instr.args[0]) % IDX_MOD) % MEM_SIZE]\
= arena[i % MEM_SIZE];
	if ((prog->next_f = new_fork_case(prog)) == NULL)
			return (-1);
	prog->next_f->start_adr = ((prog->pc + prog->instr.args[0]) % IDX_MOD) \
% MEM_SIZE;
	prog->next_f->pc = prog->next_f->start_adr;
	prog->next_f->size = i - prog->pc;
	return (0);
}

int lld(unsigned char *arena, prog_t *prog)
{
	int reg = prog->instr.args[1];
	int arg = prog->instr.arg_type >> 6 & 0b11;

	if (arg == 1)
		prog->reg[reg - 1] = prog->reg[prog->instr.args[0] - 1];
	else
		prog->reg[reg - 1] = \
arena[prog->pc + prog->instr.args[0]];
	prog->carry = 1;
	return (0);
}

int lldi(unsigned char *arena, prog_t *prog)
{
	int reg = prog->instr.args[2];
	int type_arg_1 = prog->instr.arg_type >> 6 & 0b11;
	int type_arg_2 = prog->instr.arg_type >> 4 & 0b11;

	if (type_arg_1 == 1)
		if (type_arg_2 == 1)
			prog->reg[reg - 1] = arena[prog->pc + prog->reg[prog->\
instr.args[0] - 1] + prog->reg[prog->instr.args[1] - 1]];
		else
			prog->reg[reg - 1] = arena[prog->pc + prog->reg[prog->\
instr.args[0] - 1] + prog->instr.args[1]];
	else
		if (type_arg_2 == 1)
			prog->reg[reg - 1] = \
arena[prog->instr.args[0] + prog->reg[prog->instr.args[1]]];
		else
			prog->reg[reg - 1] = \
arena[prog->instr.args[0] + prog->instr.args[1]];
	prog->carry = 1;
	return (0);
}

int lfork(unsigned char *arena, prog_t *prog)
{
	int i;

	if (prog->pc >= prog->start_adr)
		for (i = prog->pc + 3; i < prog->start_adr + prog->size; i++)
			arena[(i + prog->instr.args[0]) % MEM_SIZE] = \
arena[i % MEM_SIZE];
	else
		for (i = prog->pc + 3; i < prog->start_adr + prog->size - \
MEM_SIZE; i++)
			arena[(i + prog->instr.args[0]) % MEM_SIZE] = \
arena[i % MEM_SIZE];
	if ((prog->next_f = new_fork_case(prog)) == NULL)
			return (-1);
	prog->next_f->start_adr = (prog->pc + prog->instr.args[0]) % \
MEM_SIZE;
	prog->next_f->pc = prog->next_f->start_adr;
	prog->next_f->size = i - prog->pc;
	return (0);
}

int aff(unsigned char *arena, prog_t *prog)
{
	return (!my_putchar((prog->reg[(prog->instr.args[0]) - 1]) % 256));
}