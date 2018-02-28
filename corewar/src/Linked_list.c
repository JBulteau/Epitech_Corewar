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
	prog_t *new = malloc(sizeof(prog_t) * 1);

	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->next_f = NULL;
	if (i > 0) {
		new->prev = vm->prog[i - 1];
		vm->(prog[i - 1])->next = new;
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
	vm->prog = malloc(sizeof(vm->prog) * (nb_prog + 1));
	if (vm->prog == NULL)
		return (-1);
	for (int i = 0; i < nb_prog; i++) {
		vm->prog[i] = new_prog_case(i, vm);
		if (vm->prog[i] == NULL)
			return (-1);
	}
	vm->prog[nb_prog] = vm->prog[nb_prog - 1];	
	return (0);
}