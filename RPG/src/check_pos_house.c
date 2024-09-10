/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

// maison 1 maison 2 maison 3 infirmerie, infirmerie 2 hopital
bool check_house(t_map *map,sfBool is_find,t_map_collision *map_collision)
{
    sfVector2f map_postion = sfSprite_getPosition(map->sprite);
    if (map_postion.x >=  -252.000000 && map_postion.x <= -171.000000 &&
        map_postion.y >= -676.000000 && map_postion.y <= -663.000000) {
        return true;
    }
    if (map_postion.x >= -240.000000 && map_postion.x <=-177.000000 &&
        map_postion.y >= -859.000000 && map_postion.y <= -856.000000) {
        return true;
    }
    if (map_postion.x >= 54.000000 && map_postion.x <= 93.000000 &&
        map_postion.y >= -757.000000 && map_postion.y <= -738.000000) {
        return true;
    }
    if (map_postion.x >=  24.000000 && map_postion.x <= 66.000000 &&
        map_postion.y >= -430.000000 && map_postion.y <= -430.000000) {
        printf("INFIRMERIE\n");
        return true;
    }
    if (map_postion.x >=  -177.000000 && map_postion.x <= -114.000000 &&
        map_postion.y >= -307.000000 && map_postion.y <= -304.000000) {
        printf("INFIRMERIE2\n");
        return true;
    }
    if (map_postion.x >=  -561.000000 && map_postion.x <= -495.000000 &&
        map_postion.y >= -310.000000 && map_postion.y <= -307.000000) {
        printf("HOPITAL\n");
        return true;
    }
    return false;
}
