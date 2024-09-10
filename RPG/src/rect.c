/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_rect *create_rect(void)
{
    t_rect *rect = malloc(sizeof(t_rect));
    if (rect == NULL)
        return NULL;
    rect->UpRect = (sfIntRect){14, 14, 31, 49};
    rect->downRect = (sfIntRect){14, 83, 31, 50};
    rect->leftRect = (sfIntRect){14, 149, 36, 48};
    rect->rightRect = (sfIntRect){11, 218, 34, 45};
    return rect;
}
