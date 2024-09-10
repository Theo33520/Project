/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_text_health *loading_text_health(sfFont *font)
{
    t_text_health *health = malloc(sizeof(t_text));
    if (health == NULL || font == NULL) {
        error_handling("Error : Allocation memory\n");
        return NULL;
    }
    health->text = sfText_create();
    if (health->text == NULL) {
        error_handling("Error : Cannot load text\n");
        return NULL;
    }
    sfText_setFont(health->text,font);
    sfText_setCharacterSize(health->text,30);
    sfText_setFillColor(health->text,sfBlack);
    sfText_setString(health->text,"HEALTH");
    sfText_setPosition(health->text,(sfVector2f){1610,5});
    return health;
}

t_dialogue *create_sprite_for_dialogue(sfVector2f size,sfVector2f pos)
{
    t_dialogue *dialogue = malloc(sizeof(t_dialogue));
    if (dialogue == NULL) {
        error_handling("Error : Cannot Allocation memory !\n");
        return NULL;
    }
    dialogue->texture = sfTexture_createFromFile\
    ("./content/dialogue_box.png",NULL);
    if (dialogue->texture == NULL) {
        error_handling("Error : Cannot load textture\n");
        free(dialogue);
        return NULL;
    }
    dialogue->sprite = sfSprite_create();
    if (dialogue->sprite == NULL) {
        error_handling("Error : Cannot load sprite\n");
        sfTexture_destroy(dialogue->texture);
        free(dialogue);
        return NULL;
    }
    dialogue->pos = pos;
    dialogue->size = size;
    sfSprite_setTexture(dialogue->sprite,dialogue->texture,sfTrue);
    sfSprite_setPosition(dialogue->sprite,pos);
    sfSprite_setScale(dialogue->sprite,size);
    return dialogue;
}

t_text_figth *loading_fight_text(void)
{
    t_text_figth *text_fight = malloc(sizeof(t_text_figth));
    if (text_fight == NULL)
        return NULL;
    text_fight->texture = sfTexture_createFromFile("./content/fight.png",NULL);
    if (text_fight->texture == NULL)
        return NULL;
    text_fight->srpite = sfSprite_create();
    if (text_fight->srpite == NULL)
        return NULL;
    text_fight->pos = (sfVector2f){200,400};
    text_fight->size = (sfVector2f){0.5f,0.5f};
    sfSprite_setTexture(text_fight->srpite,text_fight->texture,sfTrue);
    sfSprite_setPosition(text_fight->srpite,text_fight->pos);
    sfSprite_setScale(text_fight->srpite,text_fight->size);
    return text_fight;
}

t_text_arrow *loading_arrow_text(void)
{
    t_text_arrow *text_fight = malloc(sizeof(t_text_arrow));
    if (text_fight == NULL)
        return NULL;
    text_fight->texture = sfTexture_createFromFile("./content/direction.png",NULL);
    if (text_fight->texture == NULL)
        return NULL;
    text_fight->srpite = sfSprite_create();
    if (text_fight->srpite == NULL)
        return NULL;
    text_fight->pos = (sfVector2f){260,500};
    text_fight->size = (sfVector2f){0.5f,0.5f};
    sfSprite_setTexture(text_fight->srpite,text_fight->texture,sfTrue);
    sfSprite_setPosition(text_fight->srpite,text_fight->pos);
    sfSprite_setScale(text_fight->srpite,text_fight->size);
    return text_fight;
}