/*
** EPITECH PROJECT, 2022
** ddd
** File description:
** ddd
*/


#include "rpg.h"

t_draw_inside *loading_draw_to_inside(void)
{
    t_draw_inside *inside = malloc(sizeof(t_draw_inside));
    if (inside == NULL)
        return NULL;
    inside->hostipal = create_in_hopital();
    return inside;
}