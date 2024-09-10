/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_in_hopital *create_in_hopital(void)
{
    t_in_hopital *hopital = malloc(sizeof(t_in_hopital));
    if (hopital == NULL)
        return hopital;
    hopital->texture = sfTexture_createFromFile("./content/wait1.png", NULL);
    if (hopital->texture == NULL)
        return NULL;
    hopital->sprite = sfSprite_create();
    if (hopital->sprite == NULL)
        return NULL;
    hopital->pos = (sfVector2f){420,0};
    hopital->size = (sfVector2f){1.0f,1.0f};
    sfSprite_setTexture(hopital->sprite,hopital->texture,sfTrue);
    sfSprite_setPosition(hopital->sprite,hopital->pos);
    sfSprite_setScale(hopital->sprite,hopital->size);
    return hopital;
}