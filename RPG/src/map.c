/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_map *create_my_map(sfVector2f pos,sfVector2f size)
{
    t_map *map = malloc(sizeof(t_map));
    if (map == NULL)
        return NULL;
    map->textture =  sfTexture_createFromFile("./content/map.png", NULL);
    if (map->textture == NULL)
        return NULL;
    map->sprite = sfSprite_create();
    if (map->sprite == NULL)
        return NULL;
    map->pos = pos;
    map->size = size;
    sfSprite_setTexture(map->sprite,map->textture,sfTrue);
    sfSprite_setPosition(map->sprite,pos);
    sfSprite_setScale(map->sprite,size);
    return map;

}

t_interdit *load_panneau(sfVector2f pos,sfVector2f size)
{
    t_interdit *interdit = malloc(sizeof(t_interdit));
    if (!interdit)
        return NULL;
    interdit->texture = sfTexture_createFromFile("./content/interdit.png",NULL);
    interdit->sprite = sfSprite_create();
    if (!interdit->sprite) {
        sfTexture_destroy(interdit->texture);
        free(interdit);
        return NULL;
    }
    interdit->pos = pos;
    interdit->size = size;
    sfSprite_setTexture(interdit->sprite,interdit->texture,sfTrue);
    sfSprite_setPosition(interdit->sprite,pos);
    sfSprite_setScale(interdit->sprite,size);
    return interdit;
}
