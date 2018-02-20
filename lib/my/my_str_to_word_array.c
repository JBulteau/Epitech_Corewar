/*
** EPITECH PROJECT, 2017
** strtowordarray
** File description:
** Task 04
*/

#include "my.h"
#include <stdlib.h>

int my_count_words(char const *str, char sep)
{
	int count = 1;

	for (int i = 1; str[i] != '\0'; i++)
		if (str[i] == sep)
			count++;
	return (count);
}

char **my_str_to_word_array(char const *str, char sep)
{
	char **tab;
	int len = my_strlen(str);
	int j = 0;
	int k = 0;
	int nb_words = my_count_words(str, sep);

	tab = malloc(sizeof(*tab) * (nb_words + 1));
	tab[nb_words] = NULL;
	for (int i = 0; i < nb_words; i++)
		tab[i] = malloc(sizeof(tab) * len);
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] != sep) {
			tab[j][k] = str[i];
			k++;
		} else {
			j++;
			k = 0;
		}
	return (tab);
}