/*
** EPITECH PROJECT, 2022
** ddd
** File description:
** ddd
*/

#include "message.h"
#include "text.h"
#include "struct.h"
#ifndef FIGHT_H
    #define FIGHT_H



typedef struct is_well {
    bool is_attacking;
    bool is_attacking2;
    bool show_fire;
    bool water_firee;
}t_well;

typedef struct fire_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_fire;

typedef struct water_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_water;

typedef struct fight_pokemon {
    t_fire *fire;
    t_water *water;
}t_fight;

t_fight *create_my_fight(void);
void free_fight(t_fight *fight);
void hanndle_attack(sfRenderWindow *window,sfSprite *sprite1,t_well *is_well,int k);
#endif /*FIGHT*/