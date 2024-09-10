##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##


LIBRARY 	= 	arcade_ncurses.so

SRC		= 	Ncurses.cpp

OBJ 	= 	$(SRC:.cpp=.o)

CPPFLAGS += -W -Wall -Wextra

CPPFLAGS += -std=c++17 -fPIC -rdynamic

LDFLAGS      	=	-shared -lncurses

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
		g++ $(OBJ) -o ../../$(LIBRARY) $(LDFLAGS)

.PHONY: all