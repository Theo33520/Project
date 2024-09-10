/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/

#include "../include/hunter.h"

void load_background(sfRenderWindow *window, t_game_function *game)
{
    game[0].texture =
    sfTexture_createFromFile("./content/1.1-Screen 1 (1).png", NULL);
    game[0].sprite = sfSprite_create();
    sfSprite_setTexture(game[0].sprite, game[0].texture, sfTrue);
}

void color_yellow(sfRenderWindow *window,t_game_function *game)
{
    game[1].texture = sfTexture_createFromFile("./content/jaune.png", NULL);
    game[1].sprite = sfSprite_create();
    sfSprite_setTexture(game[1].sprite, game[1].texture, sfTrue);
    sfSprite_setPosition(game[1].sprite, (sfVector2f){800, 10});
    sfSprite_setScale(game[1].sprite,(sfVector2f){0.036, 0.036});
}

void color_green(sfRenderWindow *window,t_game_function *game)
{
    game[2].sprite = sfSprite_create();
    game[2].texture = sfTexture_createFromFile("./content/green.png", NULL);
    sfSprite_setTexture(game[2].sprite, game[2].texture, sfTrue);
    sfSprite_setPosition(game[2].sprite, (sfVector2f){600, 20});
    sfSprite_setScale(game[2].sprite, (sfVector2f){0.12, 0.12});

}

void color_red(sfRenderWindow *window,t_game_function *game)
{
    game[3].texture = sfTexture_createFromFile("./content/rouge.png", NULL);
    game[3].sprite = sfSprite_create();
    sfSprite_setTexture(game[3].sprite, game[3].texture, sfTrue);
    sfSprite_setPosition(game[3].sprite, (sfVector2f){700, 20});
    sfSprite_setScale(game[3].sprite, (sfVector2f){0.099, 0.099});
}

void color_blue(sfRenderWindow *window,t_game_function *game)
{
    game[4].texture = sfTexture_createFromFile("./content/blue.png", NULL);
    game[4].sprite = sfSprite_create();
    sfSprite_setTexture(game[4].sprite,game[4].texture, sfTrue);
    sfSprite_setPosition(game[4].sprite, (sfVector2f){900, 12});
    sfSprite_setScale(game[4].sprite, (sfVector2f){0.03, 0.03});

}
