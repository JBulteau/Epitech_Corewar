/*
** EPITECH PROJECT, 2017
** main.c
** File description
** Main file
*/

#include "op.h"
#include "my.h"
#include "asm.h"

int main(int ac, char **av)
{
	if (0 && (ac == 1) || my_strcmp(av[1], "-h", -1)) {
		my_putstr(USAGE);
		return (0);
	}
	my_printf("%i\n", str_find("champion.s", ".s"));
	if (write_exec("tmp") == -1)
		return (84);
	//fill_linked_list("test");
	return (0);
}