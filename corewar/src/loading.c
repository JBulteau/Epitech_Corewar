/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** virtual machine for corewar
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_comment(int fd, char *comment, int *prog_size)
{
	int error = 0;

	do {
		error = read(fd, comment, 1);		
	} while (error != -1 && comment[0] < ' ');
	for (int i = 1; i <= COMMENT_LENGTH && comment[i - 1] != '\0' \
&& error != -1; i++) {
		error = read(fd, &comment[i], 1);
		*prog_size++;
	}
	if (comment[COMMENT_LENGTH] != '\0' || error == -1)
		return (NULL);
	return (comment);
}

char *get_name(int fd, char *prog_name, int *prog_size)
{
	int error = 0;

	if (read(fd, prog_name, 1) == -1)
		return (NULL);
	for (int i = 1; i <= PROG_NAME_LENGTH \
&& prog_name[i - 1] != '\0' && error != -1; i++) {
		error = read(fd, &prog_name[i], 1);
		*prog_size++;
	}
	if (prog_name[PROG_NAME_LENGTH] != '\0' || error == -1)
		return (NULL);
	return (prog_name);
}

header_t *set_header(int fd, header_t *header)
{
	header->prog_size = 2;
	if (read(fd, &header->magic, 4) == -1)
		return (NULL);
	my_memset(header->prog_name, '\0', PROG_NAME_LENGTH + 1);
	if (my_strcpy(header->prog_name, \
get_name(fd, header->prog_name, &header->prog_size), -1) == NULL)
		return (NULL);
	my_memset(header->comment, '\0', COMMENT_LENGTH + 1);
	if (my_strcpy(header->comment, \
get_comment(fd, header->comment, &header->prog_size), -1) == NULL)
		return (NULL);
	return (header);
}

prog_info_t *load_program(prog_name_t *prog_name)
{
	prog_info_t *prog_info = malloc(sizeof(prog_info_t));
	int fd = open(prog_name->name, O_RDONLY);

	if (prog_info == NULL || fd == -1)
		return (NULL);
	prog_info->header = malloc(sizeof(header_t));
	if (prog_info->header == NULL) {
		free(prog_info);
		return (NULL);
	}
	prog_info->header = set_header(fd, prog_info->header);
	if (prog_info->header == NULL) {
		free(prog_info);
		return (NULL);
	}
	return (prog_info);
}

void load_vm(args_t *args, int nb_progs)
{
	prog_info_t **prog_info = NULL;

	prog_info = malloc(sizeof(prog_info_t*) * (nb_progs + 1));
	if (prog_info == NULL)
		error(NULL, args);
	prog_info[nb_progs] = NULL;
	for (int i = 0; i < nb_progs; i++) {
		prog_info[i] = load_program(args->progs);
		if (prog_info[i] == NULL) {
			free(prog_info);
			error(NULL, args);
		}
	}
	my_printf("%s\n%s\n", prog_info[0]->header->prog_name, prog_info[0]->header->comment);
}