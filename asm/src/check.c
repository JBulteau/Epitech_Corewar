/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** Functions that check inputs
*/

int check_args(int op_code, char *args)
{
	return (0);
}

int find_instru(char *str)
{
	int i = -1;

	while(str[++i] != '\0' && str[i] != ' ');
	str[i] = '\0';
	i = -1;
	while(op_tab[++i] != NULL && strcmp(op_tab[i].mnemonique, str) != 0);
	if (op_tab[i] == NULL)
		return (-1);
	else
		return (i - 1);
}
