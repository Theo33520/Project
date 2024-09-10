/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

sfSprite* createspritee(sfTexture* texture, sfVector2f position)
{
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    return sprite;
}

void handleevents(sfRenderWindow* window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        mouseposition(event, window);
    }
}

void updatesprites(sfRenderWindow* window, sfSprite* startSprite, \
sfSprite* settingsSprite, sfSprite* exitSprite)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect startBounds = sfSprite_getGlobalBounds(startSprite);
    sfFloatRect settingsBounds = sfSprite_getGlobalBounds(settingsSprite);
    sfFloatRect exitBounds = sfSprite_getGlobalBounds(exitSprite);
    if (sfFloatRect_contains(&startBounds, mousePos.x, mousePos.y)) {
        sfSprite_setScale(startSprite, (sfVector2f){1.1f, 1.1f});
    } else {
        sfSprite_setScale(startSprite, (sfVector2f){1.0f, 1.0f});
    }
    if (sfFloatRect_contains(&settingsBounds, mousePos.x, mousePos.y)){
    sfSprite_setScale(settingsSprite, (sfVector2f){1.1f, 1.1f});
    } else {
        sfSprite_setScale(settingsSprite, (sfVector2f){1.0f, 1.0f});
    }
    if (sfFloatRect_contains(&exitBounds, mousePos.x, mousePos.y)) {
        sfSprite_setScale(exitSprite, (sfVector2f){1.1f, 1.1f});
    } else {
        sfSprite_setScale(exitSprite, (sfVector2f){1.0f, 1.0f});
    }
}

void drawsprites(sfRenderWindow* window, sfSprite* backMenuSprite, \
sfSprite* startSprite, sfSprite* settingsSprite, sfSprite* exitSprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, backMenuSprite, NULL);
    sfRenderWindow_drawSprite(window, startSprite, NULL);
    sfRenderWindow_drawSprite(window, settingsSprite, NULL);
    sfRenderWindow_drawSprite(window, exitSprite, NULL);
    sfRenderWindow_display(window);
}

sfSprite* createsprite(sfTexture* texture)
{
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
