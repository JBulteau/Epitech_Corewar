/*
** EPITECH PROJECT, 2017
** revstr
** File description:
** Task 03
*/

static int str_length(char *str);

int str_length(char *str)
{
	int length = 0;

	while (*str != '\0') {
		length = length + 1;
		str = str + 1;
	}
	return (length);
}

char *my_revstr(char *str)
{
	int length;
	int loop_count = 0;
	char temp_storage;

	length = str_length(str);
	while (loop_count < length / 2) {
		temp_storage = str[loop_count];
		str[loop_count] = str[length - loop_count - 1];
		str[length - loop_count - 1] = temp_storage;
		loop_count = loop_count + 1;
	}
	return (str);
}
