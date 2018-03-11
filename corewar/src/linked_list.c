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

prog_t *new_fork_case(prog_t *prog)
{
	prog_t *new = malloc(sizeof(prog_t));
	prog_t *curr = prog;

	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->next_f = NULL;
	init_prog_struct(new);
	prog->next_f = new;
	while (prog->next != NULL)
		prog = prog->next;
	prog->next = new;
	new->prev = prog;
	prog = curr;
	return (new);
}

void init_prog_struct(prog_t *new)
{
	new->carry = 0;
	new->cycle_wait = 0;
	new->pc = 0;
	new->nb_prog = 0;
	for (int i = 0; i < REG_NUMBER; i++)
		new->reg[i] = 0;
}

prog_t *new_prog_case(int i, vm_t *vm)
{
	prog_t *new = malloc(sizeof(prog_t));

	if (new == NULL)
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

int fill_struct_vm_prog(int nb_prog, vm_t *vm, args_t *args)
{
	int i = 0;

	vm->prog = malloc(sizeof(prog_t *) * (nb_prog + 1));
	if (vm->prog == NULL)
		return (-1);
	for (int i = 0; i < nb_prog; i++) {
		vm->prog[i] = new_prog_case(i, vm);
		vm->prog[i]->instr = (in_struct_t) {0, 0, {0, 0, 0, 0}};
		if (vm->prog[i] == NULL)
			return (-1);
	}
	vm->prog[nb_prog] = vm->prog[nb_prog - 1];
	for (prog_name_t *curr = args->progs; curr->next != NULL; \
(curr = curr->next) && i++) {
		vm->prog[i]->pc = curr->address;
		vm->prog[i]->start_adr = curr->address;
		vm->prog[i]->size = curr->size;
		vm->prog[i]->nb_prog = i;
		vm->prog[i]->reg[0] = i + 1;
	}
	return (0);
}