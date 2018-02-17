/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** gnl
*/

#include "get_next_line.h"

char *my_malloc(char *str, int size)
{
	int	i = 0;
	char *ret_str;
	int size_st = my_strlen(str);

	if ((ret_str = malloc(sizeof(*ret_str) * (size_st + size))) == NULL)
		return (NULL);
	while (str[i] != '\0') {
		ret_str[i] = str[i];
		i++;
	}
	free(str);
	return (ret_str);
}

char get_result(const int fd)
{
	static char buffer[READ_SIZE];
	static char *buff;
	static int size;
	char result;

	if (size == 0) {
		if (fd < 0)
			return (0);
		size = read(fd, buffer, READ_SIZE);
		if (size == 0 || size == -1)
			return (0);
		buff = &buffer[0];
	}
	result = (*buff);
	buff++;
	size--;
	return (result);
}

char *get_next_line(const int fd)
{
	char	*str;
	char	save;
	int	size = 0;

	if ((str = malloc(READ_SIZE + 1)) == NULL)
		return (NULL);
	if ((save = get_result(fd)) == 0)
		return (NULL);
	while (save != '\n' && save != '\0') {
		str[size++] = save;
		if ((save = get_result(fd)) == 0 && str == NULL)
			return (NULL);
		if (size % (READ_SIZE + 1) == 0)
			str = my_malloc(str, size + READ_SIZE + 1);
	}
	str[size] = '\0';
	if (save == '\0' && str[0] == '\0')
		return (NULL);
	return (str);
}
