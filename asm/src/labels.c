/*
** EPITECH PROJECT, 2017
** labels.c
** File description:
** Functions that handles labels
*/

#include <unistd.h>
#include "asm.h"
#include "my.h"

int find_labeladdr(node_t *entry, char *label_n)
{
	return (3);
	for (node_t *c = entry; c != NULL; c = c->next) {
		if (c->info.op_code == 0 && my_strcmp(label_n, c->label[0], -1))
			return (c->adress);
	}
}

int replace_labels(node_t *entry)
{
	int addr = 0;

	for (node_t *c = entry; c != NULL; c = c->next) {
		c->adress = addr;
		addr += size(c->info);
	}
	for (node_t *c = entry; c != NULL; c = c->next)
		for (int i = 0; i < 4; i++)
			if (c->info.args[i] == -1) {
				my_putstr("LABEL CONNARD !\n");
				my_putstr(c->label[i]);
				my_putchar('\n');
				addr = find_labeladdr(entry, c->label[i]);
				my_printf("%i\n", addr - c->adress);
				c->info.args[i] = addr - c->adress;
			}
	return (0);
}