/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/


/* tiret h tu connais*/
#include "../my_printf/my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include "../my_printf/my.h"
#include "../include/hunter.h"

int menu_help(void)
{
    my_printf("%s", "\nMY_PAINT");
}

void load_gomme(sfRenderWindow *window, t_game_function *game)
{
    game[5].sprite = sfSprite_create();
    sfSprite_setTexture(game[5].sprite, game[0].texture, sfTrue);
}

void answer_gomme(sfRenderWindow *window, t_game_function *game)
{
    game[6].sprite = sfSprite_create();
    sfSprite_setTexture(game[6].sprite,
    sfTexture_createFromFile("./content/gomme1.png", NULL), sfTrue);
    sfSprite_setScale(game[6].sprite, (sfVector2f){0.04, 0.04});
    sfSprite_setPosition(game[6].sprite, (sfVector2f){500, 20});
}

void load_pencil(sfRenderWindow *window, t_game_function *game)
{
    game[7].sprite = sfSprite_create();
    game[7].texture = sfTexture_createFromFile("./content/penw.png", NULL);
    sfSprite_setTexture(game[7].sprite, game[7].texture, sfTrue);
    sfSprite_setScale(game[7].sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setPosition(game[7].sprite, (sfVector2f){400, 20});
}
