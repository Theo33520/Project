/*
** EPITECH PROJECT, 2022
** day09
** File description:
** day09
*/
#include <SFML/Graphics.h>
#ifndef MESSAGE_H
    #define MESSAGE_H

typedef struct message_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
}t_message;

typedef struct healthbar_s {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f postion;
    sfVector2f size;
}t_healthbar;

typedef struct health_players_s {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
}t_health;

typedef struct health_players2_s {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
}t_health2;

typedef struct title_game {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
}t_title;

typedef struct inventory_game {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
}t_inventory;

#endif /*Message*/
