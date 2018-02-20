/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** gnl
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

// char *my_malloc(char *str, int size)
// {
// 	int	i = 0;
// 	char *ret_str;
// 	int size_st = my_strlen(str);

// 	if ((ret_str = malloc(sizeof(*ret_str) * (size_st + size))) == NULL)
// 		return (NULL);
// 	while (str[i] != '\0') {
// 		ret_str[i] = str[i];
// 		i++;
// 	}
// 	free(str);
// 	return (ret_str);
// }

// char get_result(const int fd)
// {
// 	static char buffer[READ_SIZE];
// 	static char *buff;
// 	static int size;
// 	char result;

// 	if (size == 0) {
// 		if (fd < 0)
// 			return (0);
// 		size = read(fd, buffer, READ_SIZE);
// 		if (size == 0 || size == -1)
// 			return (0);
// 		buff = &buffer[0];
// 	}
// 	result = (*buff);
// 	buff++;
// 	size--;
// 	return (result);
// }

// char *get_next_line(const int fd)
// {
// 	char	*str;
// 	char	save;
// 	int	size = 0;

// 	if ((str = malloc(READ_SIZE + 1)) == NULL)
// 		return (NULL);
// 	if ((save = get_result(fd)) == 0)
// 		return (NULL);
// 	while (save != '\n' && save != '\0') {
// 		str[size++] = save;
// 		if ((save = get_result(fd)) == 0 && str == NULL)
// 			return (NULL);
// 		if (size % (READ_SIZE + 1) == 0)
// 			str = my_malloc(str, size + READ_SIZE + 1);
// 	}
// 	str[size] = '\0';
// 	if (save == '\0' && str[0] == '\0')
// 		return (NULL);
// 	return (str);
// }

int add_more(char **buffer, int c, int i, char *save)
{
	int old_place = 0;
	char *new = NULL;

	if (c == 1) {
		for (;(*buffer)[old_place] != '\0'; old_place++);
		new = malloc(sizeof(char) * (old_place + READ_SIZE + 1));
		for (int i = 0; i < old_place; i++)
			new[i] = (*buffer)[i];
		free(*buffer);
		*buffer = new;
		return (old_place);
	}
	else {
		for (; (*buffer)[i] != '\n'; i++);
		(*buffer)[i] = '\0';
		for (; (*buffer)[i + 1] != '\0'; old_place = (i++ && c++))
			save[c] = (*buffer)[i + 1];
		save[c] = '\0';
	}
	return (0);
}

int is_line_finished(char **buffer, int fd, char *save)
{
	int nb_place_buffer = 0;
	int nb_read = 0;

	for (int i = 0; save != NULL && save[i] != '\0'; i++)
		nb_place_buffer++;
	for (int line_ok = 0; line_ok == 0;) {
		nb_read = read(fd, *buffer + nb_place_buffer, READ_SIZE);
		if (nb_read == 0) {
			(*buffer)[nb_place_buffer + nb_read] = '\0';
			return (1);
		}
		(*buffer)[nb_place_buffer + nb_read] = '\0';
		for (int i = 0; (*buffer)[i] != '\0'; i++)
			line_ok = ((*buffer)[i] == '\n') ? 1 : line_ok;
		if (line_ok == 0)
			nb_place_buffer = add_more(buffer, 1, 0, save);
	}
	add_more(buffer, 0, 0, save);
	return (0);
}

int case_read_null(char **buffer, int i, int a, char *save)
{
	for (int c = 0; (*buffer)[c] != '\0'; c++) {
		if ((*buffer)[c + 1] == '\n')
			break;
		else if ((*buffer)[c + 1] == '\0') {
			save[0] = '\0';
			return (1);
		}
	}
	for (; (*buffer)[i] != '\n'; i++);
	(*buffer)[i] = '\0';
	for (; (*buffer)[i + 1] != '\0'; i++) {
		save[a] = (*buffer)[i + 1];
		a++;
	}
	save[a] = '\0';
	return (1);
}

int handle_all(int nb_inside_buffer, char **buffer, int fd, char *save)
{
	int i = 0;
	int a = 0;
	int check = 0;

	(*buffer)[nb_inside_buffer] = '\0';
	check = is_line_finished(buffer, fd, save);
	if (check == 1 && (*buffer)[0] != '\0')
		return (case_read_null(buffer, i, a, save));
	else if (check == 1) {
		if (*buffer)
			free(*buffer);
		return (0);
	}
	return (2);
}

char *get_next_line(int fd)
{
	static char save[READ_SIZE];
	char *buffer;
	int nb_inside_buffer = 0;
	int fn = 0;

	for (int i = 0; save[i] != '\0'; nb_inside_buffer++)
		i++;
	buffer = malloc(sizeof(char) * (READ_SIZE + nb_inside_buffer + 1));
	buffer[0] = '\0';
	for (int i = 0; save != NULL && save[i] != '\0'; i++)
		buffer[i] = save[i];
	fn = handle_all(nb_inside_buffer, &buffer, fd, save);
	if (fn == 0)
		return (0);
	if (fn == 1)
		return (buffer);
	return (buffer);
}
