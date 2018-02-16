/*
** EPITECH PROJECT, 2017
** writing.c
** File description:
** Functions that write champion.cor
*/

#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int write_header(int fd, char *name, char *comment)
{
	int magic = rev_endiannes(COREWAR_EXEC_MAGIC);
	int zero = 0;
	int to_write = PROG_NAME_LENGTH - my_strlen(name) + 6;

	if (write(fd, &magic, sizeof(int)) == -1)
		return (-1);
	if (write(fd, name, my_strlen(name)) == -1)
		return (-1);
	for (int i = 0; i < to_write; i++) {
		if (write(fd, &zero, 1) == -1)
			return (-1);
	}
	if (write(fd, comment, my_strlen(comment)) == -1)
		return (-1);
	to_write = COMMENT_LENGTH - my_strlen(comment) + 6;
	for (int i = 0; i < to_write; i++) {
		if (write(fd, &zero, 1) == -1)
			return (-1);
	}
	return (0);
}