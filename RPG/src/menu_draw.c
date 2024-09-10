/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

void displayMenuSprites(sfRenderWindow* window) {
sfTexture* backMenuTexture = loadtexture("./content/back_menu.png");
    sfTexture* startTexture = loadtexture("./content/play.png");
    sfTexture* settingsTexture = loadtexture("./content/setting.png");
    sfTexture* exitTexture = loadtexture("./content/exit.png");
    sfSprite* backMenuSprite = createspritee(backMenuTexture, (sfVector2f){0, 0});
    sfSprite* startSprite = createspritee(startTexture, (sfVector2f){777, 500});
    sfSprite* settingsSprite = createspritee(settingsTexture, (sfVector2f){779, 600});
    sfSprite* exitSprite = createspritee(exitTexture, (sfVector2f){777, 700});
    while (sfRenderWindow_isOpen(window)) {
        handleevents(window);
        updatesprites(window, startSprite, settingsSprite, exitSprite);
        drawsprites(window, backMenuSprite, startSprite, settingsSprite, exitSprite);
    }
    sfSprite_destroy(backMenuSprite);
    sfSprite_destroy(startSprite);
    sfSprite_destroy(settingsSprite);
    sfSprite_destroy(exitSprite);
    sfTexture_destroy(backMenuTexture);
    sfTexture_destroy(startTexture);
    sfTexture_destroy(settingsTexture);
    sfTexture_destroy(exitTexture);
}

void mouseposition(sfEvent event, sfRenderWindow* window)
{
    int i = 0;
    if (event.type == sfEvtMouseButtonPressed) {
        int x = sfMouse_getPosition(window).x;
        int y = sfMouse_getPosition(window).y;
        printf("%i ,%i\n", x,y);
        if (x >= 781 && x <= 1187 && y >= 509 && y <= 544) {
            play_pokemon(i);
        }
        if (x >= 785 && x <= 1190 && y >= 607 && y <= 643) {
            how_to_play();
            printf("setting\n");
        }
        if (x >= 786 && x <= 1176 && y >= 713 && y <= 748) {
            sfRenderWindow_close(window);
        }
    }
}

sfRenderWindow* createRenderWindow()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create\
    (mode, "my_rpg", sfResize | sfClose, NULL);
    return window;
}

sfTexture* loadIntroTexture()
{
    sfTexture* introTexture = sfTexture_createFromFile\
    ("./content/intro.jpg", NULL);
    return introTexture;
}

sfTexture* loadBackMenuTexture()
{
    sfTexture* backMenuTexture = sfTexture_createFromFile\
    ("./content/back_menu.png", NULL);
    return backMenuTexture;
}
