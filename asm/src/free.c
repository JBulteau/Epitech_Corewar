/*
** EPITECH PROJECT, 2017
** free.c
** File description:
** Functions used to free
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

void free_ll(node_t *ll)
{
	if (ll == NULL)
		return;
	if (ll->next != NULL)
		free_ll(ll->next);
	free(ll);
}