##
## EPITECH PROJECT, 2017
## EvalExpr
## File description:
## Lib Makefile
##

NAME = my

SRCS =	concat.c \
	get_digits.c	\
	gnl.c	\
	indexof.c	\
	my_getnbr.c	\
	my_put.c	\
	my_strdup.c	\
	my_strlen.c

OBJS = $(SRCS:.c=.o)

INC = -I .

CC = gcc

CFLAGS = $(INC) -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc lib$(NAME).a $(OBJS)
	cp my.h ../../include
	cp lib$(NAME).a ..

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f lib$(NAME).a
	rm -f ../../lib$(NAME).a
	rm -f ../lib$(NAME).a

re: fclean all

debug: CFLAGS += -g
debug: re