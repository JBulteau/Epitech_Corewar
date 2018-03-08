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
	for (node_t *c = entry; c != NULL; c = c->next) {
		if (c->info.op_code == 0 \
&& my_strcmp(label_n, c->label[0], -1)) {
			return (c->address);
		}
	}
}

int replace_labels(node_t *entry)
{
	int addr = 0;

	if (entry == NULL)
		return (-1);
	for (node_t *c = entry; c != NULL; c = c->next) {
		c->address = addr;
		addr += size(c->info);
	}
	for (node_t *c = entry; c != NULL; c = c->next) {
		for (int i = 0; i < 4; i++) {
			if (c->info.args[i] == -1 && c->label[i][0] != '\0') {
				addr = find_labeladdr(entry, c->label[i]);
				c->info.args[i] = addr - c->address;
			}
		}
	}
	return (0);
}