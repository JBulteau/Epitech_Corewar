/*
** EPITECH PROJECT, 2017
** lib_my
** File description:
** lib my
*/

#ifndef __MY__H_
#define	__MY__H_

#define ERR_CODE 84
#define READ_SIZE 3

char *concat(char *src1, char *src2, int free1, int free2);
int get_digits(int nb);
char *get_next_line(int fd);
int indexof(char c, char *str);
int my_getnbr(char *str);
int my_putchar(char c);
int my_putstr(char *str);
int my_strcmp(char *str1, char *str2, int n);
int my_put_nbrbase(int nb, char *base);
int my_put_nbr(int nb);
char *my_strdup(char const *str);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
int my_unsigned_base(unsigned int nb, char const *base, int i);
int my_put_long_long(long long nb, int i);
int my_putstr_octal(char *str);
int my_putnbr_base(int nb, char const *base, int i);
char **my_str_to_word_array(char const *str);
char *my_memset(char *s, int c, int n);

#endif
