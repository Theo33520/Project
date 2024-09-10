/*
** EPITECH PROJECT, 2022
** ddd
** File description:
** ddd
*/

#include "rpg.h"

t_round1 *loading_round(void)
{
    t_round1 *roudn1 = malloc(sizeof(t_round1));
    if (roudn1 == NULL)
        return NULL;
    roudn1->texture = sfTexture_createFromFile("./content/round1.png",NULL);
    if (roudn1->texture == NULL)
        return NULL;
    roudn1->sprite = sfSprite_create();
    if (roudn1->sprite == NULL)
        return NULL;
    roudn1->pos = (sfVector2f){650,850};
    roudn1->size = (sfVector2f){1.5f,1.5f};
    sfSprite_setTexture(roudn1->sprite,roudn1->texture,sfTrue);
    sfSprite_setPosition(roudn1->sprite,roudn1->pos);
    sfSprite_setScale(roudn1->sprite,roudn1->size);
    return roudn1;
}

t_round2 *loading_round2(void)
{
    t_round2 *roudn2 = malloc(sizeof(t_round2));
    if (roudn2 == NULL)
        return NULL;
    roudn2->texture = sfTexture_createFromFile("./content/round2.png",NULL);
    if (roudn2->texture == NULL)
        return NULL;
    roudn2->sprite = sfSprite_create();
    if (roudn2->sprite == NULL)
        return NULL;
    roudn2->pos = (sfVector2f){650,850};
    roudn2->size = (sfVector2f){1.5f,1.5f};
    sfSprite_setTexture(roudn2->sprite,roudn2->texture,sfTrue);
    sfSprite_setPosition(roudn2->sprite,roudn2->pos);
    sfSprite_setScale(roudn2->sprite,roudn2->size);
    return roudn2;
}

t_round3 *loading_round3(void)
{
    t_round3 *roudn3 = malloc(sizeof(t_round3));
    if (roudn3 == NULL)
        return NULL;
    roudn3->texture = sfTexture_createFromFile("./content/round3.png",NULL);
    if (roudn3->texture == NULL)
        return NULL;
    roudn3->sprite = sfSprite_create();
    if (roudn3->sprite == NULL)
        return NULL;
    roudn3->pos = (sfVector2f){650,850};
    roudn3->size = (sfVector2f){1.5f,1.5f};
    sfSprite_setTexture(roudn3->sprite,roudn3->texture,sfTrue);
    sfSprite_setPosition(roudn3->sprite,roudn3->pos);
    sfSprite_setScale(roudn3->sprite,roudn3->size);
    return roudn3;
}


t_fight_struct *loading_fight(void)
{
    t_fight_struct *fight_struct = malloc(sizeof(t_fight_struct));
    if (fight_struct == NULL)
        return NULL;
    if (loading_round == NULL)
        return NULL;
    fight_struct->round1 = loading_round();
    fight_struct->round2 = loading_round2();
    fight_struct->round3 = loading_round3();
    return fight_struct;
}