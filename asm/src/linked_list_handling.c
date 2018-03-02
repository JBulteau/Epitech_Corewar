/*
** EPITECH PROJECT, 2017
** linked_list_handling.c
** File description:
** function for linked list
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "asm.h"

void fill_first_case_two(node_t **first, node_t **second)
{
	(*first)->info.op_code = 0;
	(*first)->info.args_types = 0;
	(*first)->next = *second;
	(*first)->adress = -1;
}

int fill_first_case(node_t **first, node_t **second, node_t **save, \
char **buffer)
{
	int nb = 0;

	for (int i = 7; (*buffer)[i] != '"'; i++)
		nb++;
	*first = malloc(sizeof(**first));
	*second = malloc(sizeof(**second));
	(*first)->label[0] = malloc(sizeof(char) * (nb + 2));
	if (*first == NULL || *second == NULL || (*first)->label[0] == NULL)
		return (-1);
	(*first)->label[0] = my_strcpy2((*first)->label[0], (*buffer + 7));
	(*first)->label[0][nb] = '\0';
	for (int i = 1; i <= 4; i++) {
		(*first)->label[i] = malloc(1);
		if ((*first)->label[i] == NULL)
			return (-1);
		(*first)->label[i][0] = '\a';
	}
	fill_first_case_two(first, second);
	*save = *first;
	*first = *second;
	return (0);
}

int fill_second_case(node_t **first, node_t **second, node_t **save, \
char **buffer)
{
	int nb = 0;

	for (int i = 10; (*buffer)[i] != '"'; i++)
		nb++;
	(*first)->label[0] = malloc(sizeof(char) * (nb + 2));
	if ((*first)->label[0] == NULL)
		return (-1);
	(*first)->label[0] = my_strcpy2((*first)->label[0], (*buffer + 10));
	(*first)->label[0][nb] = '\0';
	for (int i = 1; i <= 4; i++) {
		(*first)->label[i] = malloc(1);
		if ((*first)->label[i] == NULL)
			return (-1);
		(*first)->label[i][0] = '\a';
	}
	(*first)->info.op_code = 0;
	(*first)->info.args_types = 0;
	(*first)->adress = -1;
	(*first)->next = NULL;
	return (0);
}

void write_args_type(in_struct_t *op, int type)
{
	if (op->op_code == 1 || op->op_code == 9 || op->op_code == 12 \
|| op->op_code == 15)
		return;
	if (type == T_DIR)
		op->args_types += 2;
	else if (type == T_REG)
		op->args_types += 1;
	else
		op->args_types += 3;
	op->args_types = op->args_types << 2;
}

void write_args_stru(in_struct_t *op, char *strarg, int type, int nb_arg)
{
	if ((type == T_DIR && strarg[1] != LABEL_CHAR) || type == T_REG)
		op->args[nb_arg] = my_getnbr(strarg + 1);
	else if (type == T_DIR && strarg[1] == LABEL_CHAR)
		op->args[nb_arg] = -1;
	else
		op->args[nb_arg] = my_getnbr(strarg);
}