/*
** EPITECH PROJECT, 2017
** vm_struct.c
** File description:
** Functions that handle the vm_t structure
*/

#include "corewar.h"
#include <stdlib.h>
#include <unistd.h>

vm_t *init_vm(int prog_num)
{
	vm_t *vm = malloc(sizeof(vm_t) * 1);

	if (vm == NULL)
		return (NULL);
	for (int i = 0; i < MEM_SIZE; i++)
		vm->arena[i] = 0;
	vm->current_cycle = 0;
	vm->cycle_to_die = 0;
	vm->live = malloc(sizeof(char) * prog_num);
	vm->prog = malloc(sizeof(prog_t) * (prog_num + 1));
	if ((vm->live == NULL) || (vm->prog == NULL))
		return (NULL);
	for (int i = 0; i < prog_num; i++)
		vm->live = 0;
	return (vm);
}

