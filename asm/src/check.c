/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** Functions that check inputs
*/

#include "my.h"
#include "asm.h"
#include "op.h"
#include <stdlib.h>

int write_args(node_t *op, int type, char **args, int op_code)
{
	for (int i = 0; i < op_tab[op_code - 1].nbr_args; i++) {
		type = is_valid_arg(args[i], op, i);
		if (type < 0) {
			return (type);
		}
		write_args_type(&(op->info), type);
		write_args_stru(&(op->info), args[i], type, i);
		if (!(type & op_tab[op_code - 1].type[i])) {
			return (-10);
		}
	}
	return (0);
}

int check_args(int op_code, char *args_str, node_t *op)
{
	char **args = strtowordarr(args_str, SEPARATOR_CHAR);
	int type = 0;

	if (op_code == 0)
		return (0);
	for (int i = 0; args[i]; i++)
		args[i] = clear_str(args[i]);
	for (type = 0; args[type]; type++);
	if (type > op_tab[op_code - 1].nbr_args)
		return (-11);
	if ((type = write_args(op, type, args, op_code)) < 0) {
		my_printf("%iTYPE --> %x\n", type, op->info.args_types);	
		return (type);
	}
	if (op->info.args_types == 4)
		op->info.args_types = op->info.args_types << 4;
	if (op_tab[op_code - 1].nbr_args == 2)
		op->info.args_types = op->info.args_types << 2;
	return (0);
}

int find_instru(char *str)
{
	int i = 0;

	while (str[i++] != '\0' && str[i] != ' ');
	str[i] = '\0';
	for (int j = 0; op_tab[j].mnemonique != 0; j++)
		if (my_strcmp(str, op_tab[j].mnemonique, -1) == 1) {
			free(str);
			return (j + 1);
		}
	free(str);
	return (-1);

}

int check_label_chars(char **buffer, int inc)
{
	for (int j = 0; LABEL_CHARS[j] != '\0'; j++) {
		if (LABEL_CHARS[j] == (*buffer)[inc])
			return (0);
		if (LABEL_CHARS[j + 1] == '\0')
			return (-6);
	}
}