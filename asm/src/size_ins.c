/*
** EPITECH PROJECT, 2017
** size_ins.c
** File description:
** functions that calculates the size of instructions
*/

#include "op.h"
#include "my.h"
#include "asm.h"
#include <signal.h>

int size(in_struct_t op)
{
	int size = 1;

	if (op.op_code == 0)
		return (0);
	if (op.args_types != 0)
		size++;
	if ((op.op_code == 10) || (op.op_code == 11) || (op.op_code == 14))
		size += size_indexes(op.args_types);
	else if (op.args_types == 0)
		size += size_notype(op.op_code);
	else
		size += size_arg(op.args_types);
	my_putchar('\n');
	return (size);
}

/* Get size for std opcodes */
int size_arg(int args)
{
	int size = 0;
	int arg_code;

	for (int i = 0; i < 4; i++) {
		arg_code = (args >> 6 - (2 * i)) & 0b11;
		if (arg_code == 0b01)
			size += T_REG;
		if (arg_code == 0b10)
			size += DIR_SIZE;
		if (arg_code == 0b11)
			size += IND_SIZE;
	}
	return (size);
}

/* get size for ldi sti lldi*/
int size_indexes(int args)
{
	int arg_code;
	int size = 0;

	for (int i = 0; i < 4; i++) {
		arg_code = (args >> 6 - (2 * i)) & 0b11;
		if (arg_code == 0b01)
			size += T_REG;
		else if (arg_code == 0b10 || arg_code == 0b11)
			size += IND_SIZE;
	}
	return (size);
}

/* get size live / zjump / fork / lfork */
int size_notype(int opcode)
{
	if (opcode == 1)
		return (4);
	else
		return (2);
}