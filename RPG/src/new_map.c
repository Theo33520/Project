/*
** EPITECH PROJECT, 2022
** day09
** File description:
** day09
*/

#include "window.h"
#include "struct.h"

t_new_map *create_new_map(sfVector2f pos,sfVector2f size)
{
    t_new_map *new_map = malloc(sizeof(t_new_map));
    if (new_map == NULL)
        return NULL;
    new_map->texture = sfTexture_createFromFile("./content/map.png",NULL);
    if (new_map->texture == NULL)
        return NULL;
    new_map->sprite = sfSprite_create();
    if (new_map->sprite == NULL)
        return NULL;
    new_map->pos = pos;
    new_map->size = size;
    sfSprite_setTexture(new_map->sprite,new_map->texture,sfTrue);
    sfSprite_setPosition(new_map->sprite,pos);
    sfSprite_setScale(new_map->sprite,size);
    return new_map;
}

sfTexture* loadtexture(const char* filePath)
{
    return sfTexture_createFromFile(filePath, NULL);
}