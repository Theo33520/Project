/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

unsigned int is_hopital(t_map *map)
{
    sfVector2f map_postion = sfSprite_getPosition(map->sprite);
    if (map_postion.x >=  -564.000000 && map_postion.x <= -429.000000 &&
map_postion.y >= -328.000000 && map_postion.y <= -325.000000)
        return 1;
    return 0;
}

unsigned int is_house1(t_map *map)
{
    sfVector2f map_postion = sfSprite_getPosition(map->sprite);
    if (map_postion.x >= -240.000000 && map_postion.x <= -171.000000 &&\
map_postion.y >= -679.000000 && map_postion.y <= -670.000000)
        return 1;
    return 0;
}

unsigned int is_house2(t_map *map)
{
    sfVector2f map_postion = sfSprite_getPosition(map->sprite);
    if (map_postion.x >= -246.000000 && map_postion.x <= -165.000000 &&\
map_postion.y >= -868.000000 && map_postion.y <= -865.000000)
        return 1;
    return 0;
}

unsigned int is_house3(t_map *map)
{
    sfVector2f map_postion = sfSprite_getPosition(map->sprite);
    if (map_postion.x >= 54.000000 && map_postion.x <= 117.000000 &&\
map_postion.y >= -772.000000 && map_postion.y <= -763.000000)
        return 1;
    return 0;
}

unsigned int is_pokecenter(t_map *map)
{
    sfVector2f map_postion = sfSprite_getPosition(map->sprite);
    if (map_postion.x >= -171.000000 && map_postion.x <= -111.000000 &&\
map_postion.y ==  -316.000000)
        return 1;
    return 0;
}
