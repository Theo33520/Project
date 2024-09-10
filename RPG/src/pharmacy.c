/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_pharmacy *loading_pharmacy(sfVector2f pos, sfVector2f size)
{
    t_pharmacy *pharmacy = malloc(sizeof(t_pharmacy));
    if (!pharmacy)
        return NULL;
    pharmacy->texture = sfTexture_createFromFile\
    ("./content/pharmacy.png", NULL);
    if (pharmacy->texture == NULL)
        return NULL;
    pharmacy->sprite = sfSprite_create();
    if (pharmacy == NULL)
        return NULL;
    if (!pharmacy->sprite) {
        sfTexture_destroy(pharmacy->texture);
        free(pharmacy);
        return NULL;
    }
    pharmacy->pos = pos;
    pharmacy->size = size;
    sfSprite_setTexture(pharmacy->sprite,pharmacy->texture,sfTrue);
    sfSprite_setPosition(pharmacy->sprite,pos);
    sfSprite_setScale(pharmacy->sprite,size);
    return pharmacy;
}

t_inside_house1 *loading_house1(sfVector2f pos,sfVector2f size)
{
    t_inside_house1 *inside_house1 = malloc(sizeof(t_inside_house1));
    if (inside_house1 == NULL)
        return NULL;
    inside_house1->texture = sfTexture_createFromFile\
    ("./content/maison.png", NULL);
    if (inside_house1->texture == NULL)
        return NULL;
    inside_house1->sprite = sfSprite_create();
    if (inside_house1 == NULL)
        return NULL;
    if (inside_house1->sprite == NULL) {
        sfTexture_destroy(inside_house1->texture);
        free(inside_house1);
        return NULL;
    }
    inside_house1->pos = pos;
    inside_house1->size = size;
    sfSprite_setTexture(inside_house1->sprite,inside_house1->texture,sfTrue);
    sfSprite_setPosition(inside_house1->sprite,pos);
    sfSprite_setScale(inside_house1->sprite,size);
    return inside_house1;
}

t_inside_house2 *loading_house2(sfVector2f pos,sfVector2f size)
{
    t_inside_house2 *inside = malloc(sizeof(t_inside_house2));
    if (inside == NULL)
        return NULL;
    inside->texture = sfTexture_createFromFile("./content/maison.png", NULL);
    if (inside == NULL)
        return NULL;
    inside->sprite = sfSprite_create();
    if (inside->sprite == NULL) {
        sfTexture_destroy(inside->texture);
        free(inside);
        return NULL;
    }
    inside->pos = pos;
    inside->size = size;
    sfSprite_setTexture(inside->sprite,inside->texture,sfTrue);
    sfSprite_setPosition(inside->sprite,pos);
    sfSprite_setScale(inside->sprite,size);
    return inside;
}

t_inside_house3 *loading_house3(sfVector2f pos,sfVector2f size)
{
    t_inside_house3 *inside = malloc(sizeof(t_inside_house3));
    if (inside == NULL)
        return NULL;
    inside->texture = sfTexture_createFromFile("./content/maison.png", NULL);
    if (inside == NULL)
        return NULL;
    inside->sprite = sfSprite_create();
    if (inside->sprite == NULL) {
        sfTexture_destroy(inside->texture);
        free(inside);
        return NULL;
    }
    inside->pos = pos;
    inside->size = size;
    sfSprite_setTexture(inside->sprite,inside->texture,sfTrue);
    sfSprite_setPosition(inside->sprite,pos);
    sfSprite_setScale(inside->sprite,size);
    return inside;
}

t_inside_pockecenter *loading_pokencenter(sfVector2f pos,sfVector2f size)
{
    t_inside_pockecenter  *inside = malloc(sizeof(t_inside_pockecenter ));
    if (inside == NULL)
        return NULL;
    inside->texture = sfTexture_createFromFile\
    ("./content/pokecenter.png", NULL);
    if (inside == NULL)
        return NULL;
    inside->sprite = sfSprite_create();
    if (inside->sprite == NULL) {
        sfTexture_destroy(inside->texture);
        free(inside);
        return NULL;
    }
    inside->pos = pos;
    inside->size = size;
    sfSprite_setTexture(inside->sprite,inside->texture,sfTrue);
    sfSprite_setPosition(inside->sprite,pos);
    sfSprite_setScale(inside->sprite,size);
    return inside;
}
