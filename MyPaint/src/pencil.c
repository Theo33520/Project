/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/

#include <SFML/Graphics.h>
#include "../my_printf/my.h"

void handlevents(sfRenderWindow *window, sfBool *isDrawing)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
        if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
            sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
            if (mousePos.x >= 23 && mousePos.x <= 1578
            && mousePos.y >= 105 && mousePos.y <= 876) {
                *isDrawing = sfTrue;
            }
        } if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft) {
            *isDrawing = sfFalse;
        }
    }
}

void drawbrush(sfRenderWindow *window, sfRectangleShape *brush)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    if (mousePos.x >= 23 && mousePos.x <= 1578 && mousePos.y >= 105 &&
    mousePos.y <= 876) {
        sfVector2f brushPos = {mousePos.x, mousePos.y};
        sfRectangleShape_setPosition(brush, brushPos);
        sfRenderWindow_drawRectangleShape(window, brush, NULL);
    }
}

void hanndleyellow(sfRenderWindow* window, sfRectangleShape* brush)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    if (mousePos.x >= 509 && mousePos.x <= 561 && mousePos.y >= 28
    && mousePos.y <= 72) {
        sfRectangleShape_setFillColor(brush, sfWhite);
        sfRectangleShape_setSize(brush, (sfVector2f){30, 30});
    }

}

void handleyellowzone(sfRenderWindow* window, sfRectangleShape* brush)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    if (mousePos.x >= 605 && mousePos.x <= 658 && mousePos.y >= 30
    && mousePos.y <= 76) {
        sfRectangleShape_setFillColor(brush, sfGreen);
        sfRectangleShape_setSize(brush, (sfVector2f){10, 10});
    } if (mousePos.x >= 708 && mousePos.x <=  871 && mousePos.y >= 28
    && mousePos.y <= 79) {
        sfRectangleShape_setFillColor(brush, sfRed);
        sfRectangleShape_setSize(brush, (sfVector2f){10, 10});
    } if (mousePos.x >= 814 && mousePos.x <= 871 && mousePos.y >= 25
    && mousePos.y <= 76) {
        sfRectangleShape_setFillColor(brush, sfYellow);
        sfRectangleShape_setSize(brush, (sfVector2f){10, 10});
    } if (mousePos.x >= 914 && mousePos.x <= 970 && mousePos.y >= 27
    && mousePos.y <= 76) {
        sfRectangleShape_setFillColor(brush, sfBlue);
        sfRectangleShape_setSize(brush, (sfVector2f){10, 10});
    }
    hanndleyellow(window,brush);
}

int painting(sfRenderWindow* window, sfSprite* *button)
{
    sfBool isDrawing = sfFalse;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRectangleShape* brush = sfRectangleShape_create();
    sfRectangleShape_setSize(brush, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(brush, sfBlack);
    while (sfRenderWindow_isOpen(window)) {
        handlevents(window, &isDrawing);
        handleyellowzone(window, brush);
        /*if (isDrawing) {
            drawbrush(window, brush);
        }*/
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_display(window);
    } return 0;
}
