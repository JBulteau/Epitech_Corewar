/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** same as previous task with n first char
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
		if (s1[i] != s2[i]) {
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
