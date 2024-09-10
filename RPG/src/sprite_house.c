/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"
#include <SFML/Audio.h>

t_sprite1 *loading_sprite1(void)
{
    t_sprite1 *sprite1 = malloc(sizeof(t_sprite1));
    if (sprite1 == NULL)
        return NULL;
    sprite1->texture = sfTexture_createFromFile("./content/salamesh.png",NULL);
    if (sprite1->texture == NULL) {
        free(sprite1);
        return NULL;
    }
    sprite1->sprite = sfSprite_create();
    if (sprite1->sprite == NULL) {
        sfTexture_destroy(sprite1->texture);
        free(sprite1);
        return NULL;
    }
    sprite1->pos = (sfVector2f){200,100};
    sprite1->size = (sfVector2f){0.1f,0.1f};
    sfSprite_setTexture(sprite1->sprite,sprite1->texture,sfTrue);
    sfSprite_setPosition(sprite1->sprite,sprite1->pos);
    sfSprite_setScale(sprite1->sprite,sprite1->size);
    return sprite1;
}


t_sprite2 *loading_sprite2(void)
{
    t_sprite2 *sprite2 = malloc(sizeof(t_sprite2));
    if (sprite2 == NULL)
        return NULL;
    sprite2->texture = sfTexture_createFromFile("./content/carapuce.png",NULL);
    if (sprite2->texture == NULL) {
        free(sprite2);
        return NULL;
    }
    sprite2->sprite = sfSprite_create();
    if (sprite2->sprite == NULL) {
        sfTexture_destroy(sprite2->texture);
        free(sprite2);
        return NULL;
    }
    sprite2->pos = (sfVector2f){600,100};
    sprite2->size = (sfVector2f){0.2f,0.2f};
    sfSprite_setTexture(sprite2->sprite,sprite2->texture,sfTrue);
    sfSprite_setPosition(sprite2->sprite,sprite2->pos);
    sfSprite_setScale(sprite2->sprite,sprite2->size);
    return sprite2;
}


t_sprite3 *loading_sprite3(void)
{
    t_sprite3 *sprite3 = malloc(sizeof(t_sprite3));
    if (sprite3 == NULL)
        return NULL;
    sprite3->texture = sfTexture_createFromFile("./content/bulbizare.png",NULL);
    if (sprite3->texture == NULL) {
        free(sprite3);
        return NULL;
    }
    sprite3->sprite = sfSprite_create();
    if (sprite3->sprite == NULL) {
        sfTexture_destroy(sprite3->texture);
        free(sprite3);
        return NULL;
    }
    sprite3->pos = (sfVector2f){1000,100};
    sprite3->size = (sfVector2f){0.2f,0.2f};
    sfSprite_setTexture(sprite3->sprite,sprite3->texture,sfTrue);
    sfSprite_setPosition(sprite3->sprite,sprite3->pos);
    sfSprite_setScale(sprite3->sprite,sprite3->size);
    return sprite3;
}
