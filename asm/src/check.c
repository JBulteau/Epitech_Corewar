/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** Functions that check inputs
*/

#include "my.h"
#include "asm.h"
#include "op.h"

int check_args(int op_code, char *args_str)
{
	char **args = my_str_to_word_array(args_str, SEPARATOR_CHAR);
	int error = 0;

	my_printf("%s\n", op_tab[op_code - 1].mnemonique);
	for (int i = 0; args[i]; i++) {
		args[i] = clear_str(args[i]);
		my_printf("%s\n", args[i]);
	}
	for (int i = 0; i < op_tab[op_code - 1].nbr_args; i++) {
		my_printf("Valid args -> %i\n", op_tab[op_code + 1].type[i]);
		error = is_valid_arg(args[i]);
		if (error < 0)
			return (error);
	}
	return (0);
}

int find_instru(char *str)
{
	int i = -1;

	while (str[++i] != '\0' && str[i] != ' ') ;
	//str[i] = '\0';
	i = -1;
	while (op_tab[++i].mnemonique != 0 &&
	       my_strcmp(op_tab[i].mnemonique, str, -1) != 0) ;
	if (op_tab[i].mnemonique == 0)
		return (-1);
	else
		return (i + 1);
}