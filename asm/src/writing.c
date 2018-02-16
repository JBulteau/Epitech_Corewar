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
int write_exec(char *filename)
{
	char *pathname = concat("champion", ".cor", 0, 0);
	int fd = open("champion.cor", O_CREAT | O_RDWR, 0700);

	if ((pathname == NULL) || (fd == -1)) {
		if (filename)
			free(pathname);
		return (-1);
	}
	write_header(fd, "NAME", "COMMENT");
	write_op(fd, (in_struct_t) {0, 0, {0}});
}

/* Function that writes the header */
int write_header(int fd, char *name, char *comment)
{
	int magic = rev_endiannes_int(COREWAR_EXEC_MAGIC);
	int zero = 0;
	int to_write = PROG_NAME_LENGTH - my_strlen(name) + 6;

	if (write(fd, &magic, sizeof(int)) == -1)
		return (-1);
	if (write(fd, name, my_strlen(name)) == -1)
		return (-1);
	for (int i = 0; i < to_write; i++)
		if (write(fd, &zero, 1) == -1)
			return (-1);
	if (write(fd, comment, my_strlen(comment)) == -1)
		return (-1);
	to_write = COMMENT_LENGTH - my_strlen(comment) + 6;
	for (int i = 0; i < to_write; i++)
		if (write(fd, &zero, 1) == -1)
			return (-1);
	return (0);
}

/* Functions that writes the args for std functions */
int write_arg(int fd, in_struct_t op, int arg)
{
}

/* Functions that writes the args for ldi sti lldi*/
int write_special(int fd, in_struct_t op)
{
}

/* Function that writes the opcode + args_byte */
int write_op(int fd, in_struct_t op)
{
	int return_v = 0;

	return_v = write(fd, &op.op_code, 1);
	if (return_v == -1)
		return (-1);
	return_v = write(fd, &op.args_types, 1);
	if (return_v == -1)
		return (-1);
	if ((op.op_code == 10) || (op.op_code == 11) || (op.op_code == 14))
		return_v = write_special(fd, op);
	else
		for (int i = 0; (i < 4) && (return_v != -1); i++)
			return_v = write_arg(fd, op, i);
	if (return_v != -1)
		return (-1);
	return (0);
}