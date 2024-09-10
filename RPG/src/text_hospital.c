/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_bull_hopital *loading_bull_hopital(sfFont *font)
{
    t_bull_hopital *bull_hopital = malloc(sizeof(t_bull_hopital));
    if (!bull_hopital)
        return NULL;
    bull_hopital->text = sfText_create();
    if (bull_hopital->text == NULL)
        return NULL;
    bull_hopital->font = font;
    if (bull_hopital->font == NULL)
        return NULL;
    bull_hopital->position = ((sfVector2f){640,825});
    sfText_setFont(bull_hopital->text,font);
    sfText_setCharacterSize(bull_hopital->text,26);
    sfText_setFillColor(bull_hopital->text,sfBlack);
    sfText_setString(bull_hopital->text,"Hello Sasha, welcome to pokemon your mission is as follows, you will have to find and \nrecover a pokeball that you will store in your backpack, after that you will have to \nfind the laboratory and you will have to choose a poemon after the 3 that we offer you, \nwe will tell you the rest of your mission there\n");
    sfText_setPosition(bull_hopital->text,bull_hopital->position);
    return bull_hopital;
}
