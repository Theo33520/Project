##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

all: $(OBJ)
	make -C ./src/SDL2
	make -C ./src/SFML
	make -C ./src/Ncurses

clean:
	make fclean -C ./src/SDL2
	make fclean -C ./src/SFML
	make fclean -C ./src/Ncurses

fclean: clean
	make fclean -C ./src/SDL2
	make fclean -C ./src/SFML
	make fclean -C ./src/Ncurses

re: fclean all

.PHONY: all clean fclean re