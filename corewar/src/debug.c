/*
** EPITECH PROJECT, 2017
** debug.c
** File description:
** Function that debug
*/

#include "my.h"
#include "corewar.h"
#include <stdio.h>

void disp_arena(vm_t *vm)
{
	for (int i = 0; i < MEM_SIZE; i++) {
		my_printf("%02x ", vm->arena[i]);
		if ((i + 1) % 32 == 0)
			my_putchar('\n');
	}
}

void disp_instruction(in_struct_t op)
{
	printf("OP_CODE: %02x\nARGS_TYPE: %02x\nARGS: %02x,%02x,%02x,%02x\n", op.op_code, op.arg_type, op.args[0], op.args[1], op.args[2], op.args[3]);
}