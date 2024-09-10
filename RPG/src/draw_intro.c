/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

void displayIntro(sfRenderWindow* window, sfSprite* introSprite)
{
    sfClock* clock = sfClock_create();
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 2) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, introSprite, NULL);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
}

void cleanup(sfSprite* introSprite, sfSprite* backMenuSprite, sfTexture* introTexture, sfTexture* backMenuTexture, sfRenderWindow* window)
{
    sfSprite_destroy(introSprite);
    sfSprite_destroy(backMenuSprite);
    sfTexture_destroy(introTexture);
    sfTexture_destroy(backMenuTexture);
    sfRenderWindow_destroy(window);
}

int menu_3_choice()
{
    sfRenderWindow* window = createRenderWindow();
    sfTexture* introTexture = loadIntroTexture();
    sfTexture* backMenuTexture = loadBackMenuTexture();
    sfSprite* introSprite = createsprite(introTexture);
    sfSprite* backMenuSprite = createsprite(backMenuTexture);
    displayIntro(window, introSprite);
    while (sfRenderWindow_isOpen(window)){
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
            }
        }
        displayMenuSprites(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, backMenuSprite, NULL);
        sfRenderWindow_display(window);
    }
    cleanup(introSprite, backMenuSprite, introTexture, backMenuTexture, window);
    return 0;
}