/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_arrow *create_arrow(sfVector2f pos, sfVector2f size)
{
    t_arrow *arrow = malloc(sizeof(t_arrow));
    if (arrow == NULL)
        return NULL;
    arrow->texture = sfTexture_createFromFile("./content/arrow_back.png",NULL);
    if (arrow->texture == NULL)
        return NULL;
    arrow->sprite = sfSprite_create();
    if (arrow == NULL)
        return NULL;
    arrow->pos = pos;
    arrow->size = size;
    sfSprite_setTexture(arrow->sprite,arrow->texture,sfTrue);
    sfSprite_setPosition(arrow->sprite,pos);
    sfSprite_setScale(arrow->sprite,size);
    return arrow;
}

t_message *create_new_message(sfVector2f size,sfVector2f pos)
{
    t_message *message = malloc(sizeof(t_message));
    if (message == NULL)
        return NULL;
    message->texture = sfTexture_createFromFile("./content/message.png",NULL);
    if (message->texture == NULL)
        return NULL;
    message->sprite = sfSprite_create();
    if (message->sprite == NULL)
        return NULL;
    message->pos = pos;
    sfSprite_setTexture(message->sprite,message->texture,sfTrue);
    sfSprite_setScale(message->sprite,size);
    sfSprite_setPosition(message->sprite,pos);
    return message;
}

t_bullText *loading_text_bull(sfFont *font)
{
    t_bullText *bullText = malloc(sizeof(t_bullText));
    if (bullText == NULL)
        return bullText;
    bullText->text = sfText_create();
    if (bullText->text == NULL)
        return NULL;
    bullText->font = font;
    if (bullText->font == NULL)
        return NULL;
    bullText->position = ((sfVector2f){864,380});
    sfText_setCharacterSize(bullText->text,20);
    sfText_setFillColor(bullText->text,sfBlack);
    sfText_setString(bullText->text,"");
    sfText_setPosition(bullText->text,bullText->position);
    return bullText;
}

t_access *loading_assec_fight(sfFont *font)
{
    t_access *access = malloc(sizeof(t_access));
    if (access == NULL) {
        free(access);
        return NULL;
    }
    access->text = sfText_create();
    if (access->text == NULL) {
        free(access);
        return NULL;
    }
    access->font = font;
    if (access->font == NULL) {
        free(access);
        return NULL;
    }
    access->position = (sfVector2f){780,865};
    access->size = (sfVector2f){1.5f,1.5f};
    sfText_setFont(access->text,font);
    sfText_setCharacterSize(access->text,20);
    sfText_setFillColor(access->text,sfBlack);
    const char *msg = "To join the fight. Please press the F key on your device\n";
    sfText_setString(access->text,msg);
    sfText_setPosition(access->text,access->position);
    sfText_setScale(access->text,access->size);
    return access;
}