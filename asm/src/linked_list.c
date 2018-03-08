/*
** EPITECH PROJECT, 2017
** linked_list.c
** File description:
** functions to fill the linked list of all instructions
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int test_synt_name(char *name, int *error)
{
	int i = 1;

	if (name[0] != ' ')
		return (*error = -6);
	else if (name[1] != '"')
		return (*error = -5);
	while (name[++i] != '\0' && name[i] != '"');
	if (name[i] == '\0' || name[i + 1] != '\0')
		return (*error = -5);
	return (0);
}

int check_buff(char **buffer, int *error, int fd, char *to_check)
{
	if (*buffer == NULL)
		return (*error = -1);
	for (; *buffer != NULL && *buffer[0] == COMMENT_CHAR; \
*buffer = get_next_line(fd));
	if (*buffer == NULL)
		return (*error = -1);
	//TODO: NE PAS CLEAR SI ENTRE QUOTES
	*buffer = clear_str(*buffer);
	if ((my_strncmp(*buffer, to_check, 5) != 0)) {
		*error = -6;
		return (-1);
	}
	return (0);
}

int name_handling(node_t **all, int fd, char **buffer, int *error)
{
	*buffer = get_next_line(fd);
	for (; *buffer != NULL && ((*buffer)[0] == '\0' || (*buffer)[0] == \
COMMENT_CHAR); *buffer = get_next_line(fd));
	if (check_buff(buffer, error, fd, NAME_CMD_STRING) == -1)
		return (-1);
	if (test_synt_name(*buffer + my_strlen(NAME_CMD_STRING), error) < 0)
		return (-1);
	if (fill_first_case(&(all[0]), &(all[1]), &(all[2]), buffer) == -1)
		return (-1);
	return (0);
}

node_t *fill_linked_list(char *filename, int *error)
{
	char *pathname = concat(filename, ".s", 0, 0);
	int fd = open(pathname, O_RDONLY);
	char *buffer = NULL;
	node_t *all[3] = {NULL, NULL, NULL};

	if (fd == -1 && (*error = -1) == -1)
		return (NULL);
	if (name_handling(all, fd, &buffer, error) == -1)
		return (NULL);
	buffer = get_next_line(fd);
	for (; buffer != NULL && (buffer[0] == '\0' || buffer[0] == \
COMMENT_CHAR); buffer = get_next_line(fd));
	if (check_buff(&buffer, error, fd, COMMENT_CMD_STRING) < 0 || \
test_synt_name(buffer + my_strlen(COMMENT_CMD_STRING), error) < 0 || \
fill_second_case(&(all[0]), &(all[1]), &(all[2]), &buffer) < 0 || \
(*error = parsing(all[0], &buffer, fd)) < 0)
		return (NULL);
	if (*error == 42)
		return (all[2]);
	return (all[2]);
}