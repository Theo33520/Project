/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/

#include "../include/hunter.h"
#include "../my_printf/my.h"

int mouseposition(sfEvent event, sfRenderWindow* window)
{
    int i = 0;
    if (event.type == sfEvtMouseButtonPressed){
    int x = sfMouse_getPosition(window).x;
    int y = sfMouse_getPosition(window).y;
    my_printf("%d\n", x);
    my_printf("%d\n", y);
    if (x >= 654 && x <= 958 && y >= 331 && y <= 574) {
            game_fuctions(event, window, i);
        }
    }
}

int window_picture(sfRenderWindow *window, sfEvent event,
sfSprite *sprite, sfSprite *button)
{
    while (sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
        }
    }
    display(window, sprite, button);
    mouseposition(event, window);
}

int window_image_x_y(void)
{
    sfVideoMode video_mode = {1600, 900, 32, 32};
    sfRenderWindow* window; sfEvent event;
    sfTexture* *texture = sfTexture_createFromFile("./content/rrrr.jpg", NULL);
    sfSprite* *sprite = sfSprite_create(), *button = sfSprite_create();
    sfTexture* *texture02 = sfTexture_createFromFile("./content/aaaz.png",NULL);
    sfVector2f scale_button = {0.26, 0.26}, position_button = {660, 300};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(button, texture02, sfTrue);
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, position_button);
    window = sfRenderWindow_create(video_mode, "MY_PAINT",\
    sfClose | sfResize, NULL);
    while (sfRenderWindow_isOpen(window)){
        window_picture(window,event,sprite,button);
    }
}

void display(sfRenderWindow* window, sfSprite* *sprite, sfSprite* *button)
{
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_display(window);
}
