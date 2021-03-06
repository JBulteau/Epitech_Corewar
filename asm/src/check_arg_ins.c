/*
** EPITECH PROJECT, 2017
** check_arg_ins.c
** File description:
** Functions that checks arguments given to instructions
*/

#include "op.h"
#include "my.h"
#include "asm.h"

static int check_reg(char *arg)
{
	int len = my_strlen(arg);
	int reg = 0;

	if (len == 1)
		return (-9);
	reg = my_getnbr(arg + 1);
	if ((reg <= 0) || (reg > REG_NUMBER))
		return (-9);
	for (int i = 1; arg[i]; i++)
		if ((arg[i] < '0') || (arg[i] > '9'))
			return (-9);
	return (T_REG);
}

static int check_label(char *arg, int type)
{
	for (int i = 0; arg[i]; i++)
		if (indexof(arg[i], LABEL_CHARS) == -1)
			return (-7);
	return ((type) ? T_DIR : T_IND);
}

static int check_dir(char *arg)
{
	for (int i = 1; arg[i]; i++) {
		if ((i == 1) && (arg[i] == '-'))
			continue;
		if ((arg[i] < '0') || (arg[i] > '9'))
			return (-10);
	}
	return (T_DIR);
}

static int check_ind(char *arg)
{
	for (int i = 0; arg[i]; i++) {
		if ((i == 0) && ((arg[i] == '-') || (arg[i] == LABEL_CHAR)))
			continue;
		if ((arg[i] < '0') || (arg[i] > '9'))
			return (-10);
	}
	return (T_IND);
}

int is_valid_arg(char *arg, node_t *op, int i)
{
	int reg;
	int len = my_strlen(arg);

	if (arg[0] == 'r')
		return (check_reg(arg));
	else if (arg[0] == DIRECT_CHAR) {
		if (arg[1] == LABEL_CHAR) {
			op->label[i] = my_strdup(arg + 2);
			op->info.args[i] = -1;
			return (check_label(arg + 2, 1));
		} else
			return (check_dir(arg));
	} else {
		if (arg[0] == LABEL_CHAR) {
			op->label[i] = my_strdup(arg + 1);
			op->info.args[i] = -1;
			return (check_label(arg + 1, 0));
		} else
			return (check_ind(arg));
	}
}