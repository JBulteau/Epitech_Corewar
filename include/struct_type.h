/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** declaration of type structure
*/

#ifndef __STRUCT_TYPE_H_
#define __STRUCT_TYPE_H_

#include <stdarg.h>

int my_ptr_c(va_list ap, char *flags);
int my_ptr_d(va_list ap, char *flags);
int my_ptr_i(va_list ap, char *flags);
int my_ptr_s(va_list ap, char *flags);
int my_ptr_x(va_list ap, char *flags);
int my_ptr_x_maj(va_list ap, char *flags);
int my_ptr_o(va_list ap, char *flags);
int my_ptr_b(va_list ap, char *flags);
int my_ptr_u(va_list ap, char *flags);
int my_ptr_p(va_list ap, char *flags);
int my_ptr_s_maj(va_list ap, char *flags);

struct types
{
	char type;
	int (*ptrfunc)(va_list, char*);
};

struct types type_funcs [] = {
	{'c', &my_ptr_c},
	{'d', &my_ptr_d},
	{'i', &my_ptr_i},
	{'s', &my_ptr_s},
	{'x', &my_ptr_x},
	{'X', &my_ptr_x_maj},
	{'o', &my_ptr_o},
	{'b', &my_ptr_b},
	{'u', &my_ptr_u},
	{'p', &my_ptr_p},
	{'S', &my_ptr_s_maj}
};

#endif
