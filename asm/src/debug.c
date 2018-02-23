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