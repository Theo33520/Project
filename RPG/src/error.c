/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

static int my_strlen(char const *str)
{
    int idx = 0;
    while (str[idx] != '\0') {
        idx += 1;
    }
    return idx;
}

void error_handling(char const *error)
{
    if (error == NULL)
        return;
    write(2,error,my_strlen(error));
}
