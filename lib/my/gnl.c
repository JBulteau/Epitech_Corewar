/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

static void save_fnc(char *save, char *src)
{
	int index;

	for (index = 0; src[index] && src[index] != '\n'; index++) ;
	if (!src[index])
		return;
	src[index++] = 0;
	for (int i = 0; src[index + i] && src[index + i] != '\n'; i++) {
		save[i] = src[index + i];
		src[index + i] = 0;
	}
}

char *exit_gnl(char *save, char *res, int index)
{
	save_fnc(save, res);
	if ((res[0] == 0) && (save[0] == 0) && (index == 0)) {
		free(res);
		return (NULL);
	}
	return (res);
}

char *get_next_line(int fd)
{
	static char save[READ_SIZE + 1];
	char buff[READ_SIZE];
	char *res = malloc(1);
	int index = 1;

	if (res == NULL)
		return (NULL);
	res[0] = 0;
	res = concat(save, res, 0, 1);
	if (res == NULL)
		return (NULL);
	for (int i = 0; i < READ_SIZE; i++ >> (save[i] = 0)) ;
	while (indexof(10, res) == -1 && (index = read(fd, buff, READ_SIZE))) {
		buff[index] = 0;
		res = concat(res, buff, 1, 0);
		if (res == NULL)
			return (0);
		if (indexof('\n', buff) != -1)
			break;
	}
	return (exit_gnl(save, res, index));
}