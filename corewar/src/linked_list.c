/*
** EPITECH PROJECT, 2017
** Linked_list.c
** File description:
** functions to fill the linked list
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void free_dead_prog(prog_t *to_kill)
{
	if (to_kill == NULL)
		return;
	if (to_kill->next_f != NULL)
		free_dead_prog(to_kill->next_f);
	free(to_kill);
}

prog_t *new_fork_case(vm_t *vm, int prog_f, int nb_prog)
{
	prog_t *new = malloc(sizeof(prog_t));

	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->next_f = NULL;
	init_prog_struct(new);
	vm->prog[nb_prog]->next = new;
	new->prev = vm->prog[nb_prog];
	vm->prog[prog_f - 1]->next_f = new;
	vm->prog[nb_prog] = new;
	return (new);
}

void init_prog_struct(prog_t *new)
{
	new->carry = 0;
	new->cycle_wait = 0;
	new->pc = 0;
	for (int i = 0; i < REG_NUMBER; i++)
		new->reg[i] = 0;
}

prog_t *new_prog_case(int i, vm_t *vm)
{
	prog_t *new = malloc(sizeof(prog_t));

	if (new = NULL)
		return (NULL);
	new->next = NULL;
	new->next_f = NULL;
	if (i > 0) {
		new->prev = vm->prog[i - 1];
		vm->prog[i - 1]->next = new;
		init_prog_struct(new);
		return (new);
	} else {
		new->prev = NULL;
		init_prog_struct(new);
		return (new);
	}
}

int fill_struct_vm_prog(int nb_prog, vm_t *vm)
{
	vm->prog = malloc(sizeof(prog_t*) * (nb_prog + 1));
	if (vm->prog == NULL)
		return (-1);
	for (int i = 0; i < nb_prog; i++) {
		vm->prog[i] = malloc(sizeof(prog_t));
		vm->prog[i] = new_prog_case(i, vm);
		if (vm->prog[i] == NULL)
			return (-1);
	}
	vm->prog[nb_prog] = vm->prog[nb_prog - 1];	
	return (0);
}

