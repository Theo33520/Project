/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

void free_hero(t_heros *heros)
{
    if (heros != NULL) {
        free(heros->texture);
        free(heros->sprite);
        free(heros);
    }
}

void free_map(t_map *map)
{
    if (map != NULL) {
        free(map->textture);
        free(map->sprite);
        free(map);
    }
}

void free_title(t_title *title)
{
    if (title != NULL) {
        free(title->texture);
        free(title->sprite);
        free(title);
    }
}

void free_arrow(t_arrow *arrow)
{
    if (arrow != NULL) {
        free(arrow->texture);
        free(arrow->sprite);
        free(arrow);
    }
}

void free_interdit(t_interdit *interdit)
{
    if (interdit != NULL) {
        free(interdit->texture);
        free(interdit->sprite);
        free(interdit);
    }
}
