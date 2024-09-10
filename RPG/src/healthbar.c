/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_healthbar *create_healthbar(sfVector2f pos ,sfVector2f size, sfColor color)
{
    t_healthbar *healthBar = malloc(sizeof(t_healthbar));
    if (healthBar == NULL)
        return NULL;
    healthBar->rectangle = sfRectangleShape_create();
    if (healthBar->rectangle == NULL)
        return NULL;
    healthBar->postion = pos;
    healthBar->size = size;
    healthBar->color = color;
    sfRectangleShape_setSize(healthBar->rectangle, size);
    sfRectangleShape_setFillColor(healthBar->rectangle, color);
    sfRectangleShape_setPosition(healthBar->rectangle, healthBar->postion);
    return healthBar;
}

t_health *create_players1(sfVector2f pos, sfVector2f size, sfColor color)
{
    t_health *health = malloc(sizeof(t_health));
    if (health == NULL)
        return NULL;
    health->rectangle = sfRectangleShape_create();
    if (health->rectangle == NULL) {
        free(health); // Libérer la mémoire allouée pour t_health
        return NULL;
    }
    health->pos = pos;
    health->size = size;
    health->color = color;
    sfRectangleShape_setSize(health->rectangle, size);
    sfRectangleShape_setFillColor(health->rectangle, color);
    sfRectangleShape_setPosition(health->rectangle, pos);
    return health;
}

t_health2 *create_players2(sfVector2f pos, sfVector2f size, sfColor color)
{
    t_health2 *health2 = malloc(sizeof(t_health));
    if (health2 == NULL)
        return NULL;
    health2->rectangle = sfRectangleShape_create();
    if (health2->rectangle == NULL) {
        free(health2); // Libérer la mémoire allouée pour t_health
        return NULL;
    }
    health2->pos = pos;
    health2->size = size;
    health2->color = color;
    sfRectangleShape_setSize(health2->rectangle, size);
    sfRectangleShape_setFillColor(health2->rectangle, color);
    sfRectangleShape_setPosition(health2->rectangle, pos);
    return health2;
}

t_text_Players1 *create_text_play1(sfVector2f pos,sfFont *font, const char *message)
{
    t_text_Players1 *Players1 = malloc(sizeof(t_text_Players1));
    if (Players1 == NULL)
        return NULL;
    Players1->text = sfText_create();
    if (Players1->text == NULL)
        return NULL;
    sfText_setFont(Players1->text,font);
    sfText_setCharacterSize(Players1->text,20);
    sfText_setFillColor(Players1->text,sfWhite);
    if (message == NULL)
        return NULL;
    sfText_setString(Players1->text,message);
    sfText_setPosition(Players1->text,pos);
    return Players1;
}

t_text_Players2 *create_text_play2(sfVector2f pos,sfFont *font, const char *message)
{
    t_text_Players2 *Players2 = malloc(sizeof(t_text_Players2));
    if (Players2 == NULL)
        return NULL;
    Players2->text = sfText_create();
    if (Players2->text == NULL)
        return NULL;
    sfText_setFont(Players2->text,font);
    sfText_setCharacterSize(Players2->text,20);
    sfText_setFillColor(Players2->text,sfWhite);
    if (message == NULL)
        return NULL;
    sfText_setString(Players2->text,message);
    sfText_setPosition(Players2->text,pos);
    return Players2;
}