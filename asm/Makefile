##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile our projects
##

NAME		=	asm

SRC_DIR		=	$(realpath ./src)

SRC_FILES	=	main.c	\
			op.c	\
			writing.c	\
			endianness.c	\
			linked_list.c	\
			clean_str.c	\
			size_ins.c	\
			fill_linked_list.c	\

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

CFLAGS		=	-W -Wextra  -I ../include

OBJ		=	$(SRC:%.c=%.o)

LIB_DIR		=	$(realpath ../lib)

LDFLAGS		=	-L $(LIB_DIR) -Llib -lmy

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C $(LIB_DIR)/my
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
		$(RM) $(OBJ)
		$(MAKE) clean -C $(LIB_DIR)/my

fclean:		clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIB_DIR)/my

re:		fclean all

debug:		CFLAGS += -g
debug:		re
