##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##


LIBRARY 	= 	arcade_sdl2.so

SRC		= 	SDL2.cpp

OBJ 	= 	$(SRC:.cpp=.o)

CPPFLAGS += -std=c++17 -fPIC -rdynamic

LDFLAGS      	=	-shared -lSDL2 -lSDL2_ttf

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
		g++ $(OBJ) -o ../../$(LIBRARY) $(LDFLAGS)

.PHONY: all