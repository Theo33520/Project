/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

unsigned int check_in_hopital(t_map *map)
{
    sfVector2f map_pos = sfSprite_getPosition(map->sprite);
    int x = map_pos.x;
    int y = map_pos.y;
    if (x >= -299.000000 && x <= 700.000000 && y >= -310.000000 && y <= 314.000000)
        return 1;
    return 0;
}

t_load_perso *create_my_perso(void)
{
    t_load_perso *load_perso = malloc(sizeof(t_load_perso));
    if (!load_perso)
        return NULL;
    load_perso->texture = sfTexture_createFromFile("./content/mechant.png",NULL);
    if (!load_perso->texture) {
        free(load_perso);
        return NULL;
    }
    load_perso->sprite = sfSprite_create();
    if (!load_perso->sprite) {
        sfTexture_destroy(load_perso->texture);
        free(load_perso);
        return NULL;
    }
    load_perso->pos = (sfVector2f){930,600};
    load_perso->size = (sfVector2f){0.1f,0.1f};
    sfSprite_setTexture(load_perso->sprite,load_perso->texture,sfTrue);
    sfSprite_setPosition(load_perso->sprite,load_perso->pos);
    sfSprite_setScale(load_perso->sprite,load_perso->size);
    return load_perso;
}

