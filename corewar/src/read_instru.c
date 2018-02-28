/*
** EPITECH PROJECT, 2017
** read_instru.c
** File description:
** Functions that read instructions in the arena
*/

#include <stdio.h>
#include "corewar.h"

int load_n_arena(unsigned char *arena, int pos, int size)
{
	int res = 0;

	for (int i = 0; i < size; i++) {
		res = res << 8;
		printf("-> %x\n", res);
		res += arena[(pos + i) % MEM_SIZE];
	}
	printf("%x\n", res);
	return (res);
}

void read_one_arg(unsigned char *arena, int pos, in_struct_t *op)
{
	if (op->op_code == 0x10) { // AFF
		op->arg_type = arena[(pos + 1) % MEM_SIZE];
		op->args[0] = arena[(pos + 2) % MEM_SIZE];
		return;
	}
	if (op->op_code == 0x01) { // LIVE
		op->args[0] = load_n_arena(arena, pos + 1, 4);
		return;
	}
	// JZMP / FORK / LFROK TODO
	op->args[0] = load_n_arena(arena, pos + 1, 2);
}

void load_args(unsigned char *arena, in_struct_t *op)
{
	int arg = 0;
	int cursor = 2;

	for (int i = 0; i < 4; i++) {
		arg = op->arg_type >> 6 - (i * 2) & 0b11;
		if (arg == 0b01) {
			op->args[i] = load_n_arena(arena, cursor, 1);
			cursor += 1;
		}
		if (arg == 0b10) {
			op->args[i] = load_n_arena(arena, cursor, 4);
			cursor += 4;
		}
		if (arg == 0b11) {
			op->args[i] = load_n_arena(arena, cursor, 2);
			cursor += 2;
		}
	}
}

void load_index(unsigned char *arena, in_struct_t *op)
{
	int arg = 0;
	int cursor = 2;

	for (int i = 0; i < 4; i++) {
		arg = op->arg_type >> 6 - (i * 2) & 0b11;
		if (arg == 0b01) {
			op->args[i] = load_n_arena(arena, cursor, 1);
			cursor += 1;
		}
		if (arg == 0b11 || arg == 0b10) {
			op->args[i] = load_n_arena(arena, cursor, 2);
			cursor += 2;
		}
	}
}

in_struct_t read_instru(unsigned char *arena, int pos)
{
	in_struct_t op;

	op.op_code = load_n_arena(arena, pos, 1);
	for (int i = 0; i < 4; i++)
		op.args[i] = 0;
	op.arg_type = 0;
	if ((op.op_code < 1) || (op.op_code > 16)) {
		op.op_code = -1;
		return (op);
	}
	if ((op.op_code == 1) || (op.op_code == 9) || (op.op_code == 12) || (op.op_code == 15) || (op.op_code == 16)) {
		read_one_arg(arena, pos, &op);
		return (op);
	}
	op.arg_type = load_n_arena(arena, pos + 1, 1);
	if ((op.op_code == 0x0e) || (op.op_code == 0x0b) || (op.op_code == 0x0a))
		load_index(arena, &op);
	else
		load_args(arena, &op);
	return (op);
}