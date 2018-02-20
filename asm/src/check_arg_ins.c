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

static int check_label(char *arg)
{
	int len = my_strlen(arg);

	if (len == 2)
		return (-18);
	for (int i = 2; arg[i]; i++)
		if (indexof(arg[i], LABEL_CHARS) == -1)
			return (-7);
	return (T_DIR);
}

static int check_dir(char *arg)
{
	for (int i = 1; arg[i]; i++)
		if ((arg[i] < '0') || (arg[i] > '9'))
			return (-10);
	return (T_DIR);
}

static int check_ind(char *arg)
{
	for (int i = 0; arg[i]; i++)
		if ((arg[i] < '0') || (arg[i] > '9'))
			return (-10);
	return (T_IND);
}

int is_valid_arg(char *arg)
{
	int reg;
	int len = my_strlen(arg);

	if (arg[0] == 'r')
		return (check_reg(arg));
	else if (arg[0] == DIRECT_CHAR) {
		if (arg[1] == LABEL_CHAR)
			return (check_label(arg));
		else
			return (check_dir(arg));
	} else
		return (check_ind(arg));
}