/*
** EPITECH PROJECT, 2017
** writing.c
** File description:
** Functions that write champion.cor
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

/* Main function that writes */
int write_exec(char *filename, node_t *entry)
{
	int error = 0;
	char *pathname = concat(filename, ".cor", 0, 0);
	int fd = open(pathname, O_CREAT | O_RDWR, 0700);
	int total_size = 0;

	if ((pathname == NULL) || (fd == -1)) {
		if (filename)
			free(pathname);
		return (-1);
	}
	for (node_t *curr = entry->next->next; curr != NULL; curr = curr->next) {
		total_size += size(curr->info);
	}
	write_header(fd, entry->label[0], entry->next->label[0], total_size);
	for (node_t *curr = entry->next->next; curr != NULL; curr = curr->next)
		write_op(fd, curr->info);
	free(pathname);
	return (0);
}

/* Function that writes the header */
int write_header(int fd, char *name, char *comment, int size)
{
	int magic = rev_endiannes_int(COREWAR_EXEC_MAGIC);
	int values[3] = {0};

	values[1] = rev_endiannes_int(size);
	values[2] = PROG_NAME_LENGTH - my_strlen(name) + 4;
	if (write(fd, &magic, sizeof(int)) == -1)
		return (-1);
	if (write(fd, name, my_strlen(name)) == -1)
		return (-1);
	for (int i = 0; i < values[2]; i++)
		if (write(fd, &values[0], 1) == -1)
			return (-1);
	if (write(fd, &values[1], sizeof(int)) == -1)
		return (-1);
	if (write(fd, comment, my_strlen(comment)) == -1)
		return (-1);
	values[2] = COMMENT_LENGTH - my_strlen(comment) + 4;
	for (int i = 0; i < values[2]; i++)
		if (write(fd, &values[0], 1) == -1)
			return (-1);
	return (0);
} /* write_header */

/* Functions that writes the args for std functions */
int write_arg(int fd, in_struct_t op, int arg)
{
	int arg_type = (op.args_types >> 6 - (2 * arg)) & 0b11;
	int to_write = rev_endiannes_int(op.args[arg]);

	if (arg_type == 0b01)
		if (write(fd, &op.args[arg], T_REG) == -1)
			return (-1);
	if (arg_type == 0b10)
		if (write(fd, &to_write, DIR_SIZE) == -1)
			return (-1);
	if (arg_type == 0b11) {
		to_write = rev_endiannes_short(op.args[arg]);
		if (write(fd, &to_write, IND_SIZE) == -1)
			return (-1);
	}
	return (0);
}

/* Functions that writes the args for ldi sti lldi*/
int write_indexes(int fd, in_struct_t op, int arg)
{
	int arg_type = (op.args_types >> 6 - (2 * arg)) & 0b11;
	int to_write = rev_endiannes_short(op.args[arg]);

	if (arg_type == 0b01)
		if (write(fd, &op.args[arg], T_REG) == -1)
			return (-1);
	if ((arg_type == 0b11) || (arg_type == 0b10))
		if (write(fd, &to_write, IND_SIZE) == -1)
			return (-1);
	return (0);
}

/* Function that writes bytecode for live / zjump / fork / lfork */
int write_notype(int fd, in_struct_t op)
{
	if (op.op_code == 1) {
		op.args[0] = rev_endiannes_int(op.args[0]);
		if (write(fd, &op.args[0], 4) == -1)
			return (-1);
	} else {
		op.args[0] = rev_endiannes_short(op.args[0]);
		if (write(fd, &op.args[0], 2) == -1)
			return (-1);
	}
	return (0);
}

/* Function that writes the opcode + args_byte */
int write_op(int fd, in_struct_t op)
{
	int return_v = 0;

	if (op.op_code == 0)
		return (0);
	return_v = write(fd, &op.op_code, 1);
	if (return_v == -1)
		return (-1);
	if (return_v == -1)
		return (-1);
	if (op.args_types == 0)
		return_v = write_notype(fd, op);
	else
		return_v = write(fd, &op.args_types, 1);
	if ((op.op_code == 10) || (op.op_code == 11) || (op.op_code == 14))
		for (int i = 0; (i < 4) && (return_v != -1); i++)
			return_v = write_indexes(fd, op, i);
	else
		for (int i = 0; (i < 4) && (return_v != -1); i++)
			return_v = write_arg(fd, op, i);
	if (return_v == -1)
		return (-1);
	return (0);
}