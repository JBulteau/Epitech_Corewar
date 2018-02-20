/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** Str to word array
*/

#include <unistd.h>
#include "my.h"

int get_wordlen(char *str, char separator)
{
	int i = 0;

	for (; str[i] != '\0' && str[i] != separator; i++);
	return (i);
}

int count_words(char *str, char sep)
{
	int words = 0;
	int i;
	int is_w = 0;

	if (str == NULL)
		return (0);
	words = (str[0] != 0 && str[0] != sep) ? 1 : 0;
	is_w = (words) ? 1 : 0;
	for (i = 0; str[i]; i++) {
		if ((str[i] == sep) && is_w) {
			words++;
			is_w = 0;
		}
		if (!is_w && (str[i] != sep))
			is_w = 1;
	}
	return (words);
}

void copy_word(char *dest, char *src, int size)
{
	for (int i = 0; i < size; i++)
		dest[i] = src[i];
	dest[size] = '\0';
}

char **strtowordarr(char *str, char separator)
{
	int w_count = count_words(str, separator);
	char **word_arr = malloc((w_count + 1) * sizeof(char *));
	int word = 0;
	int is_w = 0;
	int n = 0;

	if (word_arr == NULL)
		return (NULL);
	for (int i = 0; i < w_count + 1; (int)(word_arr[i] = NULL) & (i++));
	for (int i = 0; str[i]; i++) {
		if ((str[i] == separator) && ((n = 0) == 0))
			continue;
		if (n == 0) {
			n = get_wordlen(str + i, separator);
			word_arr[word] = malloc(n + 1);
			if (word_arr[word] == NULL)
				return (NULL);
			copy_word(word_arr[word++], str + i, n);
		}
	}
	return (word_arr);
}