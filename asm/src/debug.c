/*
** EPITECH PROJECT, 2017
** debug.c
** File description:
** Debug fncs
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

node_t *init_node(void)
{
	node_t *node = malloc(sizeof(node_t));

	if (node == NULL)
		return (NULL);
	node->info.args[0] = 0;
	node->info.args[1] = 0;
	node->info.args[2] = 0;
	node->info.args[3] = 0;
	node->info.args_types = 0;
	node->info.op_code = 0;
	node->label[0] = "";
	node->label[1] = "";
	node->label[2] = "";
	node->label[3] = "";
	node->label[4] = "";
	node->next = NULL;
	return (node);
}

void disp_node(node_t *node)
{
	my_printf("OP CODE: %x\n", node->info.op_code);
	my_printf("ARG TYPE: %x\n", node->info.args_types);
	my_printf("ADRESS: %x\n", node->adress);
	my_printf("ARGS:\t%i   %i   %i   %i\n", node->info.args[0], node->info.args[1], node->info.args[2], node->info.args[3]);
}

static node_t *create_node(int args[5], int types, int code, char **labels) {
	node_t *node = malloc(sizeof(node_t));

	node->info.args[0] = args[0];
	node->info.args[1] = args[1];
	node->info.args[2] = args[2];
	node->info.args[3] = args[3];
	node->info.args_types = types;
	node->info.op_code = code;
	node->label[0] = labels[0];
	node->label[1] = labels[1];
	node->label[2] = labels[2];
	node->label[3] = labels[3];
	node->label[4] = labels[4];
	node->next = NULL;
	return (node);
}

node_t *manual_ll(void)
{
	int args[5] = {0};
	char *labels[5] = {"name", "\a", "\a", "\a", "\a"};
	node_t *first;
	node_t *node = create_node(args, 0x0, 0, labels);
	first = node;

	labels[0] = "comment";
	node = create_node(args, 0x0, 0, labels);
	first->next = node;

	return (first);
}