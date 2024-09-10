##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##


LIBRARY 	= 	arcade_nibbler.so

SRC		= 	Nibbler.cpp

OBJ 	= 	$(SRC:.cpp=.o)

CPPFLAGS += -W -Wall -Wextra

CPPFLAGS += -std=c++17 -fPIC -rdynamic

LDFLAGS      	=	-shared -lsfml-graphics -lsfml-window -lsfml-system

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
		g++ $(OBJ) -o ../../$(LIBRARY) $(LDFLAGS)

.PHONY: all