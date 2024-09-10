/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** polemon
*/

#include "rpg.h"

t_text *loading_text_level(sfFont *font,sfVector2f pos)
{
    t_text *text_level = malloc(sizeof(t_text));
    if (text_level == NULL || font == NULL) {
        return NULL;
    }
    text_level->text = sfText_create();
    if (text_level->text == NULL)
        return NULL;
    text_level->fond = font;
    text_level->pos = pos;
    sfText_setFont(text_level->text,font);
    sfText_setFillColor(text_level->text,sfWhite);
    char const *message_level = "LEVEL";
    sfText_setString(text_level->text,message_level);
    sfText_setPosition(text_level->text,pos);
    return text_level;
}

t_textplayers *loading_text_players(sfFont *font)
{
    t_textplayers *textPlayers = malloc(sizeof(t_textplayers));
    if (!textPlayers || font == NULL) {
        return NULL;
    }
    textPlayers->text = sfText_create();
    if (textPlayers == NULL)
        return NULL;
    textPlayers->fond = font;
    textPlayers->pos = (sfVector2f){820,860};
    sfText_setFont(textPlayers->text,font);
    sfText_setFillColor(textPlayers->text,sfWhite);
    char const *message_players = "PLAYERS";
    sfText_setString(textPlayers->text,message_players);
    sfText_setPosition(textPlayers->text,textPlayers->pos);
    return textPlayers;
}

t_pourcent *loading_headlthbartext(sfFont *font)
{
    t_pourcent *text_score = malloc(sizeof(t_pourcent));
    if (text_score == NULL) {
        return NULL;
    }
    text_score->text = sfText_create();
    if (text_score->text == NULL)
        return NULL;
    sfText_setFont(text_score->text,font);
    sfText_setCharacterSize(text_score->text,15);
    sfText_setFillColor(text_score->text,sfBlack);
    char const *str = "100 / 100";
    sfText_setString(text_score->text,str);
    sfText_setPosition(text_score->text,(sfVector2f){1620,55});
    return text_score;
}
