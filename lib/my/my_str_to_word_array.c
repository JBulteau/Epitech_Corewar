/*
** EPITECH PROJECT, 2017
** strtowordarray
** File description:
** Task 04
*/

#include "my.h"
#include <stdlib.h>

static int my_count_words(char const *str);

int my_count_words(char const *str)
{
	int count = 1;

	for (int i = 1; str[i] != '\0'; i++) {
		if (str[i] == ' ')
			count++;
	}
	return (count);
}

char **my_str_to_word_array(char const *str)
{
	char **tab;
	int len = my_strlen(str);
	int j = 0;
	int k = 0;
	int nb_words = my_count_words(str);

	tab = malloc(sizeof(*tab) * nb_words);
	for (int i = 0; i < nb_words; i++) {
		tab[i] = malloc(sizeof(tab) * len);
		my_memset(tab[i], '\0', len);
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			tab[j][k] = str[i];
			k++;
		} else {
			j++;
			k = 0;
		}
	}
	return (tab);
}
