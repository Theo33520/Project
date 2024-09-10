/*
** EPITECH PROJECT, 2022
** day09
** File description:
** day09
*/
#include <SFML/Graphics.h>
#ifndef STRUCT_H
    #define STRUCT_H

    #define FAILURE 84
    #define SUCCESS 0

typedef struct arrow_back_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_arrow;

typedef struct t_inventory_bulbizare_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_inventory_bulbizare;

typedef struct inventory_salamesh_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_inventory_salamesh;

typedef struct t_inventory_carapuce_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_inventory_carapuce;

typedef struct heros_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f origin;
    sfVector2f size;
}t_heros;

typedef struct pourcent_s {
    sfText *text;
    sfFont *fond;
    sfVector2f pos;
}t_pourcent;

typedef struct level_s {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f postion;
    sfVector2f size;
}t_level;

typedef struct sprite_rect {
    sfIntRect upRect;
    sfIntRect downRect;
    sfIntRect leftRect;
    sfIntRect rightRect;
}t_sprite_rect;

typedef struct map_s {
    sfTexture *textture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_map;

typedef struct new_map_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_new_map;

typedef struct map_collision_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfImage *picture;
}t_map_collision;

typedef struct interdit_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_interdit;

typedef struct in_hopital {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_in_hopital;

typedef struct in_house {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_in_house;

typedef struct pharmacy_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_pharmacy;

typedef struct inside_house1 {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_inside_house1;

typedef struct inside_house2 {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_inside_house2;

typedef struct inside_house3 {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_inside_house3;

typedef struct inside_pokecenter_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_inside_pockecenter;
#endif /*STRUCT*/
