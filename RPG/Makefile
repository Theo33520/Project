##
## EPITECH PROJECT, 2022
## B-CPE-101-BDX-1-1-myprintf-matteo.verdez
## File description:
## Makefile
##

NAME	= my_rpg

CC	= gcc -g -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

RM	= rm -f

SRCS	=	./src/main.c \
			./src/menu.c \
			./src/init_struct.c \
			./src/bar_level.c \
			./src/button.c \
			./src/healthbar.c \
			./src/heros.c \
			./src/text_hospital.c \
			./src/check_pos_house.c \
			./src/pharmacy.c \
			./src/window_exit.c \
			./src/menu_draw.c \
			./src/inventory.c \
			./src/collision.c \
			./src/level.c \
			./src/free_all.c \
			./src/in_inside.c \
			./src/error.c \
			./src/tittle.c \
			./src/map.c \
			./src/go_inside_house.c \
			./src/game.c \
			./src/sprite_inside.c \
			./src/free.c \
			./src/window.c \
			./src/free_text.c \
			./src/inside.c \
			./src/draw_inside.c \
			./src/sprite_house.c \
			./src/rect.c \
			./src/draw_intro.c \
			./src/positon_inside.c \
			./src/new_map.c \
			./src/picture.c \
			./src/how_to_play.c \
			./src/effect.c \
			./src/fight_pokemon.c \
			./src/menu_help.c


OBJS	= $(SRCS:.c=.o)

CPPFLAGS = -I ./include/

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
