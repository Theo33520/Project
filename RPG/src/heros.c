/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_heros *create_my_heros(sfVector2f origin,sfVector2f size)
{
    t_heros *heros = malloc(sizeof(t_heros));
    if (heros == NULL)
        return NULL;
    heros->texture = sfTexture_createFromFile("./content/hero.png", NULL);
    if (heros->texture == NULL)
        return NULL;
    heros->sprite = sfSprite_create();
    if (heros->sprite == NULL)
        return NULL;
    heros->size = size;
    heros->origin = origin;
    sfSprite_setTexture(heros->sprite,heros->texture,sfTrue);
    sfSprite_setOrigin(heros->sprite,origin);
    sfSprite_setScale(heros->sprite,size);
    return heros;
}
