/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

bool check_pos_inside(t_map *map)
{
    sfVector2f pos = sfSprite_getPosition(map->sprite);
    int x = pos.x;
    int y = pos.y;
    sfBool is_well = false;
    if (x >= 95.000000 && x <= 236.000000 &&\
    y >= -311.000000 && y <= -251.000000)
        return is_well = true;
    return is_well = false;
}

bool check_pos_house(t_map *map)
{
    sfVector2f pos = sfSprite_getPosition(map->sprite);
    int x = pos.x;
    int y = pos.y;
    sfBool is_well = false;
    if (x >= 68.000000 && x <= 173.000000 && y >= 190.000000 && y <= 277.000000)
        return is_well = true;
    return false;
}
