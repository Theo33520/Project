/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

t_inventory *create_inventory(sfVector2f pos)
{
    t_inventory *inventory = malloc(sizeof(t_inventory));
    if (inventory == NULL)
        return NULL;
    inventory->texture = sfTexture_createFromFile("./content/inventaire.png", NULL);
    if (inventory->texture == NULL)
        return NULL;
    inventory->sprite = sfSprite_create();
    if (inventory->sprite == NULL)
        return NULL;
    inventory->pos = pos;
    sfSprite_setTexture(inventory->sprite,inventory->texture,sfTrue);
    sfSprite_setPosition(inventory->sprite,pos);
    return inventory;
}

t_inventory_salamesh *inventory_salamesh(sfVector2f pos, sfVector2f size)
{
    t_inventory_salamesh *salamesh = malloc(sizeof(t_inventory_salamesh));
    if (salamesh == NULL)
        return NULL;
    salamesh->texture = sfTexture_createFromFile("./content/salamesh.png",NULL);
    if (salamesh->texture == NULL)
        return NULL;
    salamesh->sprite = sfSprite_create();
    if (salamesh == NULL)
        return NULL;
    salamesh->pos = pos;
    salamesh->size = size;
    sfSprite_setTexture(salamesh->sprite,salamesh->texture,sfTrue);
    sfSprite_setPosition(salamesh->sprite,pos);
    sfSprite_setScale(salamesh->sprite,size);
    return salamesh;
}

t_inventory_carapuce *inventory_carapuce(sfVector2f pos, sfVector2f size)
{
    t_inventory_carapuce *carapuce = malloc(sizeof(t_inventory_carapuce));
    if (carapuce == NULL)
        return NULL;
    carapuce->texture = sfTexture_createFromFile("./content/carapuce.png",NULL);
    if (carapuce->texture == NULL)
        return NULL;
    carapuce->sprite = sfSprite_create();
    if (carapuce == NULL)
        return NULL;
    carapuce->pos = pos;
    carapuce->size = size;
    sfSprite_setTexture(carapuce->sprite,carapuce->texture,sfTrue);
    sfSprite_setPosition(carapuce->sprite,pos);
    sfSprite_setScale(carapuce->sprite,size);
    return carapuce;
}

t_inventory_bulbizare *inventory_bulbizare(sfVector2f pos, sfVector2f size)
{
    t_inventory_bulbizare *bulbizare = malloc(sizeof(t_inventory_bulbizare));
    if (bulbizare == NULL)
        return NULL;
    bulbizare->texture = sfTexture_createFromFile("./content/bulbizare.png",NULL);
    if (bulbizare->texture == NULL)
        return NULL;
    bulbizare->sprite = sfSprite_create();
    if (bulbizare == NULL)
        return NULL;
    bulbizare->pos = pos;
    bulbizare->size = size;
    sfSprite_setTexture(bulbizare->sprite,bulbizare->texture,sfTrue);
    sfSprite_setPosition(bulbizare->sprite,pos);
    sfSprite_setScale(bulbizare->sprite,size);
    return bulbizare;
}
