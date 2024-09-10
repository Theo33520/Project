/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"
#include <SFML/Audio.h>


t_fire *loading_texture_fire(void)
{
    t_fire *fire = malloc(sizeof(t_fire));
    if (fire == NULL)
        return NULL;
    fire->texture = sfTexture_createFromFile("./content/galaxie.png", NULL);
    fire->sprite = sfSprite_create();
    fire->pos = (sfVector2f){1100, 400};
    fire->size = (sfVector2f){0.6f, 0.6f};
    sfSprite_setTexture(fire->sprite, fire->texture, sfTrue);
    sfSprite_setPosition(fire->sprite, fire->pos);
    sfSprite_setScale(fire->sprite, fire->size);
    return fire;
}

void free_texture_fire(t_fire *fire)
{
    sfTexture_destroy(fire->texture);
    sfSprite_destroy(fire->sprite);
    free(fire);
}


t_water *loading_texture_water(void)
{
    t_water *water = malloc(sizeof(t_water));
    if (water == NULL)
        return NULL;
    water->texture = sfTexture_createFromFile("./content/feux.png", NULL);
    water->sprite = sfSprite_create();
    water->pos = (sfVector2f){400, 470};
    water->size = (sfVector2f){0.2f, 0.2f};
    sfSprite_setTexture(water->sprite, water->texture, sfTrue);
    sfSprite_setPosition(water->sprite, water->pos);
    sfSprite_setScale(water->sprite, water->size);
    return water;
}


void free_texture_water(t_water *water) 
{
    sfTexture_destroy(water->texture);
    sfSprite_destroy(water->sprite);
    free(water);
}

t_fight *create_my_fight(void)
{
    t_fight *fight = malloc(sizeof(t_fight));
    if (fight == NULL)
        return NULL;
    fight->fire = loading_texture_fire();
    fight->water = loading_texture_water();
    return fight;
}

void free_fight(t_fight *fight)
{
    free_texture_fire(fight->fire);
    free_texture_water(fight->water);
}

void hanndle_attack(sfRenderWindow *window,sfSprite *sprite1,t_well *is_well,int k)
{
    int vie_mechant = 100;
    sfFont *font = sfFont_createFromFile("./content/BebasNeue-Regular.ttf");
    sfColor my_green = sfColor_fromRGB(0x0D,0x97,0x00);
    sfColor my_color = sfColor_fromRGB(255, 168, 22);
    sfColor my_red = sfColor_fromRGB(202,0,0);
    t_health *players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_green);
    t_text_Players1 *text_Players1 = create_text_play1((sfVector2f){1620,53},font,"100 / 100");
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite1);
    if (sfFloatRect_contains(&sprite_bounds,mouse_pos.x,mouse_pos.y) && !is_well->is_attacking) {
        int random_number = 0;
        srand(time(NULL));
        random_number = rand() % 16 + 15;
        vie_mechant = vie_mechant - random_number;
        char *live_menewto = int_to_str(vie_mechant);
        my_strcat(live_menewto," / 100");
        if (vie_mechant <= 0)
            sfRenderWindow_close(window);
        is_well->is_attacking = true;
        is_well->show_fire = true;
        sfSprite_setPosition(sprite1, (sfVector2f){1300, 100});
        k++;
        if (vie_mechant >= 80 && vie_mechant <= 100)
            players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_green);
        if (vie_mechant >= 30 && vie_mechant <= 79)
            players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_color);
        if (vie_mechant >= 0 && vie_mechant <= 29)
            players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_red);
        text_Players1 = create_text_play1((sfVector2f){1620,53},font,live_menewto);
    }
    sfRenderWindow_drawRectangleShape(window,players1->rectangle,NULL);
    sfRenderWindow_drawText(window,text_Players1->text,NULL);
}
