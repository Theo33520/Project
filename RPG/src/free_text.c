/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

static void free_text_health(t_text_health *text_h)
{
    if (text_h != NULL) {
        free(text_h->text);
        free(text_h);
    }
}

static void free_text_inhealbar(t_pourcent *pourcent)
{
    if (pourcent != NULL) {
        free(pourcent->text);
        free(pourcent);
    }
}

static void free_text_bull_text(t_bullText *text_bull)
{
    if (text_bull != NULL) {
        free(text_bull->text);
        free(text_bull);
    }
}

static void free_text_level(t_text *textlevel)
{
    if (textlevel != NULL) {
        free(textlevel->text);
        free(textlevel);
    }
}

static void free_text_players(t_textplayers *text_players)
{
    if (text_players != NULL) {
        free(text_players->text);
        free(text_players);
    }
}

void free_textgame(t_textGame *text_game)
{
    if (text_game != NULL) {
        free_text_health(text_game->text_h);
        free_text_inhealbar(text_game->text_inhealthBar);
        free_text_bull_text(text_game->text_in_bull);
        free_text_level(text_game->textLevel);
        free_text_players(text_game->textplayers);
        free(text_game);
    }
}
