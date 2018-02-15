/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** printf
*/

#ifndef __MY_PRINTF_H_
#define __MY_PRINTF_H_

#include <stdarg.h>

int str_padding(int len, char *flags, char c);
int test_str_flags(char *str, int len, char *flags, int count);
int test_long_long_flags(long long nb, int len, char *flags, int count);
int test_unsigned_flags(unsigned int nb, char *base, char *flags, int count);
int test_int_flags(int nb, int len, char *flags, int count);
int long_long_len(long long nb);
int unsigned_len(unsigned int nb, char *base);
int int_len(int nb);
int is_in_str(char c, char *flags);
int browse_args(va_list ap, char *flags);
int override_useless_flags(char *flags_str, char flag, int count);
void find_overrider_flags(char *flags);
int handle_flags(va_list ap, char *flags);
int is_flag(char *flags);
int is_type(char c);
char *browse_flags(const char *format, int i, char *flags);

#endif
