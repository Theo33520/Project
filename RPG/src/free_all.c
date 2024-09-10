/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

static void free_healthbar(t_healthbar *healbar)
{
    if (healbar != NULL) {
        free(healbar->rectangle);
        free(healbar);
    }
}

static void free_level(t_level *level)
{
    if (level != NULL) {
        free(level->rectangle);
        free(level);
    }
}

void free_game(t_game *game)
{
    if (game != NULL) {
        free_hero(game->hero);
        free_map(game->map);
        free_title(game->title);
        free_arrow(game->arrow);
        free_interdit(game->stop);
        free_healthbar(game->healtBar);
        free_level(game->level);
        free(game);
    }
}
