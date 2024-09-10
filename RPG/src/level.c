/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_level *create_levelbar(sfColor color)
{
    t_level *level = malloc(sizeof(t_level));
    if (level == NULL) {
        error_handling("Error : Cannot load Allocation memory\n");
        return NULL;
    }
    level->rectangle = sfRectangleShape_create();
    level->color = color;
    if (level->rectangle == NULL) {
        error_handling("Error : Cannot load color or rectangle\n");
        return NULL;
    }
    sfColor contour_blue = sfColor_fromRGB(0x00,0x6D,0xAC);
    sfRectangleShape_setSize(level->rectangle,(sfVector2f){500,30});
    sfRectangleShape_setFillColor(level->rectangle,color);
    sfRectangleShape_setPosition(level->rectangle,(sfVector2f){800,900});
    sfRectangleShape_setOutlineThickness(level->rectangle,5);
    sfRectangleShape_setOutlineColor(level->rectangle,contour_blue);
    return level;
}
