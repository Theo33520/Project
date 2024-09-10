/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_inside *init_inside(void)
{
    t_inside *inside = malloc(sizeof(t_inside));
    if (inside == NULL)
        return NULL;
    inside->pharmacy = loading_pharmacy((sfVector2f){200,100},(sfVector2f)\
    {4.5f,4.5f});
    inside->inside_one = loading_house1((sfVector2f){200,100},(sfVector2f)\
    {4.5f,4.5f});
    inside->inside_two = loading_house2((sfVector2f){200,100},(sfVector2f)\
    {4.5f,4.5f});
    inside->inside_tree = loading_house3((sfVector2f){200,100},(sfVector2f)\
    {4.5f,4.5f});
    inside->inside_pocenter = loading_pokencenter((sfVector2f)\
    {200,100},(sfVector2f){2.5f,2.5f});
    return inside;
}
