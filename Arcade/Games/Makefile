##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

all: $(OBJ)
	make -C ./src/Snacke
	make -C ./src/Nibbler

clean:
	make clean -C ./src/Snacke

fclean: clean
	make fclean -C ./src/Snacke

re: fclean all

.PHONY: all clean fclean re