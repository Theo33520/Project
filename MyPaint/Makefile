##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = 	./src/main.c \
		./src/clique_here.c \
		./src/menu_help.c \
		./src/menu.c \
		./src/my_paint.c \
		./src/pencil.c	\
		./src/paramters_object.c \
		my_printf/my_printf.c 			\
        my_printf/my_put_nbr.c 			\
        my_printf/my_putchar.c			\
        my_printf/my_putstr.c				\
        my_printf/my_putfloat.c			\
        my_printf/octet.c					\
        my_printf/hexadecimal_maj.c         \
        my_printf/hexadecimal.c

SRC_TEST = tests/test.c

SRC_MAIN = src/main.c

DEBUG = -g3

CSFML = 	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME	=	my_paint

NAME1	= criterion

OBJ	=	$(SRC:.c=.o)

OBJ_TEST = $(SRC:.c=.o)	$(SRC_TEST:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)	$(CSFML)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME) -f

re : fclean all

debug:	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(DEBUG)

tests_run: $(OBJ_TEST)
						gcc -o $(NAME1) $(OBJ_TEST) -lcriterion --coverage
.PHONY: all clean fclean re
