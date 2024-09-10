/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include "../my_printf/my.h"
#include "../include/hunter.h"

void create_menu_sprite(MenuSprite* menu)
{
    menu->texture = sfTexture_createFromFile("./content/image", NULL);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    menu->scale = (sfVector2f){0.1f, 0.1f};
    sfSprite_setScale(menu->sprite, menu->scale);
    menu->position = (sfVector2f){130.0f, 30.0f};
    sfSprite_setPosition(menu->sprite, menu->position);
}

void create_menu_text(MenuText* menuText, sfFont* font,
const char* string, sfVector2f position)
{
    menuText->text = sfText_create();
    sfText_setString(menuText->text, string);
    sfText_setFillColor(menuText->text, sfBlack);
    sfText_setFont(menuText->text, font);
    sfText_setCharacterSize(menuText->text, 20);
    menuText->position = position;
    sfText_setPosition(menuText->text, position);
}

int create_menu(sfRenderWindow* window)
{
    Menu menu; sfEvent event;
    menu.sprite.sprite = sfSprite_create();
    sfFont* font = sfFont_createFromFile("./content/arial.ttf");
    create_menu_sprite(&menu.sprite);
    create_menu_text(&menu.text[0], font, "File",(sfVector2f){130.0f, 120.0f});
    create_menu_text(&menu.text[1], font, "Edit",(sfVector2f){190.0f, 120.0f});
    create_menu_text(&menu.text[2], font, "Help",(sfVector2f){250.0f, 120.0f});
    sfRenderWindow_drawSprite(window, menu.sprite.sprite, NULL);
    int x = sfMouse_getPosition(window).x;
    int y = sfMouse_getPosition(window).y;
    for (int i = 0; i < 3; i++) {
        if (x >= 109 && x <= 200 && y >= 2 && y <= 95)
            sfRenderWindow_drawText(window, menu.text[i].text, NULL);
        else
            sfText_setFillColor(menu.text[i].text, sfBlack);
    } sfRenderWindow_display(window);sfFont_destroy(font);
    sfSprite_destroy(menu.sprite.sprite);
    for (int i = 0; i < 3; i++) {
        sfText_destroy(menu.text[i].text);
    } return 0;
}

