/*
** EPITECH PROJECT, 2022
** day09
** File description:
** day09
*/
#include <SFML/Graphics.h>
#ifndef TEXT_H
    #define TEXT_H

typedef struct text_health {
    sfText *text;
    sfFont *fond;
    sfVector2f pos;
}t_text_health;

typedef struct text_level {
    sfText *text;
    sfFont *fond;
    sfVector2f pos;
}t_text;

typedef struct text_player {
    sfText *text;
    sfFont *fond;
    sfVector2f pos;
}t_textplayers;

typedef struct bull_text {
    sfText *text;
    sfFont *font;
    sfVector2f position;
}t_bullText;


typedef struct bull_hopital {
    sfText *text;
    sfFont *font;
    sfVector2f position;
}t_bull_hopital;

typedef struct bull_access {
    sfText *text;
    sfFont *font;
    sfVector2f position;
    sfVector2f size;
}t_access;

typedef struct dialogue_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_dialogue;

typedef struct players1Text_s {
    sfText *text;
    sfFont *font;
    sfVector2f position;
}t_text_Players1;

typedef struct players2Text_s {
    sfText *text;
    sfFont *font;
    sfVector2f position;
}t_text_Players2;
#endif /*TEXT_H*/
