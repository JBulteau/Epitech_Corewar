/*
** EPITECH PROJECT, 2017
** vm_struct.c
** File description:
** Functions that handle the vm_t structure
*/

#include "my.h"
#include "corewar.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

vm_t *load_program_in_arena(vm_t *vm, prog_name_t *prog, int fd)
{
	for (int i = prog->adress; i < prog->adress + prog->size; i++) {
		if (vm->arena[i % MEM_SIZE] != '\0') {
			write(2, "Overlap\n", 8);
			return (NULL);
		}
		if (read(fd, &vm->arena[i % MEM_SIZE], 1) == -1)
			return (NULL);
	}
	return (vm);
}

vm_t *get_program_info(vm_t *vm, prog_name_t *prog_name, int free_memory)
{
	int fd = open(prog_name->name, O_RDONLY);
	unsigned char *str = malloc(sizeof(unsigned char) * 132);

	if (fd == -1)
		return (NULL);
	if (read(fd, str, 132) == -1)
		return (NULL);
	my_realloc(str, 5);
	if (read(fd, str, 4) == -1)
		return (NULL);
	prog_name->size = hexa_to_deca(str);
	if (prog_name->size > free_memory)
		return (NULL);
	my_realloc(str, 2052);
	if (read(fd, str, 2052) == -1)
		return (NULL);
	vm = load_program_in_arena(vm, prog_name, fd);
	free(str);
	close(fd);
	return (vm);
}

vm_t *init_arena(vm_t *vm, args_t *args)
{
	int free_memory = MEM_SIZE;
	prog_name_t *current = args->progs;
	
	while (args->progs != NULL) {
		if (args->progs->prev != NULL)
			free_memory -= args->progs->prev->size;
		if (get_program_info(vm, args->progs, free_memory) == NULL)
			return (NULL);
		args->progs = args->progs->next;
	}
	args->progs = current;
	return (vm);
}

vm_t *init_vm(int prog_num, args_t *args)
{
	vm_t *vm = malloc(sizeof(vm_t) * 1);

	if (vm == NULL)
		return (NULL);
	for (int i = 0; i < MEM_SIZE; i++)
		vm->arena[i] = 0;
	vm->current_cycle = 0;
	vm->cycle_to_die = 0;
	vm->live = malloc(sizeof(char) * prog_num);
	vm->prog = malloc(sizeof(prog_t *) * prog_num);
	if ((vm->live == NULL) || (vm->prog == NULL))
		return (NULL);
	for (int i = 0; i < prog_num; i++)
		vm->live = 0;
	vm = init_arena(vm, args);
	return (vm);
}