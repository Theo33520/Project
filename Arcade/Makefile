##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = 	src/Main.cpp \
		./Core/Core.cpp \
		./Core/HandleMenu.cpp
LDFLAGS		=	-ldl

CPPFLAGS += -I./includes

CPPFLAGS	+=	-I./ -I./lib -I./Games -g -rdynamic

DEBUG = -g3

NAME	=	arcade

OBJ	=	$(SRC:.cpp=.o)


all:	graphic games core


graphic:
	make -C ./lib

games:
	make -C ./Games

core: 	$(OBJ)
			g++ -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME) -f
	rm ./lib/*.so -f
	rm ./lib/src/Ncurses/*.o -f
	rm ./Games/*.so -f
	rm ./Games/src/Nibbler/*.o -f
	rm ./Games/src/Snacke/*.o -f
	rm ./lib/src/SDL2/*.o -f
	rm ./lib/src/SFML/*.o -f

re : fclean all

debug:	$(OBJ)
			g++ -o $(NAME) $(OBJ) $(DEBUG)

.PHONY: all clean fclean re