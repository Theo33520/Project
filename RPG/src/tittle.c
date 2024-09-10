/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_title *create_the_title(sfVector2f pos)
{
    t_title *title = malloc(sizeof(t_title));
    if (title == NULL)
        return NULL;
    title->texture = sfTexture_createFromFile("./content/tittle.png", NULL);
    if (title->texture == NULL)
        return NULL;
    title->sprite = sfSprite_create();
    if (title->sprite == NULL)
        return NULL;
    title->pos = pos;
    sfSprite_setTexture(title->sprite,title->texture,sfTrue);
    sfSprite_setPosition(title->sprite,pos);
    return title;
}
