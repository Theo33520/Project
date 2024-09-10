/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/

#include "../include/hunter.h"
#include "../my_printf/my.h"

void updategommebutton(sfRenderWindow* window, sfSprite* buttonYY,
GommeState* state)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    bool isButtonPressed = sfMouse_isButtonPressed(sfMouseLeft);
    if (mousePos.x >= 509 && mousePos.x <= 561 && mousePos.y >= 28
    && mousePos.y <= 72) {
        *state = isButtonPressed ? GommeState_Selected : GommeState_Hover;
    } else {
        *state = GommeState_Normal;
    }
    sfSprite_setTexture(buttonYY,
    sfTexture_createFromFile("./content/gomme1.png", NULL), sfTrue);
    sfSprite_setScale(buttonYY, (sfVector2f){0.04, 0.04});
    if (*state == GommeState_Selected) {
        sfSprite_setTexture(buttonYY,
        sfTexture_createFromFile("./content/gomme2.png", NULL), sfTrue);
    } else if (*state == GommeState_Hover) {
        sfSprite_setScale(buttonYY, (sfVector2f){0.08, 0.08});
    }
}
void check_coordonne(ButtonState* state, sfRenderWindow* window,
sfSprite* button)
{
    int x = sfMouse_getPosition(window).x;
    int y = sfMouse_getPosition(window).y;
    if (x >= 21 && x <= 98 && y >= 20 && y <= 82){
        update_window(state, window, button);
    }
}

void update_pencil_state(ButtonState* state, sfRenderWindow* window,
sfSprite* button)
{
    int x = sfMouse_getPosition(window).x;
    int y = sfMouse_getPosition(window).y; sfVector2f scale_button;
    switch (*state) {
        case STATE_IDLE: if (x >= 390 && x <= 449 && y >= 12 && y <= 55) {
                *state = STATE_HOVER; scale_button = (sfVector2f){0.13, 0.12};
                sfSprite_setScale(button, scale_button);
            }break; case STATE_HOVER: if (x < 390 || x > 449 ||
            y < 12 || y > 55) {
                *state = STATE_IDLE; scale_button = (sfVector2f){0.1, 0.1};
                sfSprite_setScale(button, scale_button);
            } else if (sfMouse_isButtonPressed(sfMouseLeft)) {
                *state = STATE_CLICKED;sfTexture* texture02 =
                sfTexture_createFromFile("./content/penb.png", NULL);
                scale_button = (sfVector2f) {0.13, 0.12};
                sfSprite_setTexture(button, texture02, sfTrue);
                sfSprite_setScale(button, scale_button);painting(window, button);
            } break; case STATE_CLICKED:
            if (!sfMouse_isButtonPressed(sfMouseLeft)) { *state = STATE_IDLE;
                scale_button = (sfVector2f) {0.1, 0.1}; sfSprite_setScale(button, scale_button);
            }break;check_coordonne(state,window,button);
    }
}

void update_window(ButtonState* state, sfRenderWindow* window,
sfSprite* button)
{
    int x = sfMouse_getPosition(window).x;
    int y = sfMouse_getPosition(window).y;
    sfVector2f scale_buttonn;
    if (x >= 21 && x <= 98 && y >= 20 && y <= 82){
        sfTexture *texture03 = sfTexture_createFromFile("./content/rectangle.png", NULL);
        sfSprite* *sprite = sfSprite_create();
        sfVector2f scale_buttonn  = {0.45, 0.45}, position_button = {21, 86};
        sfSprite_setTexture(button, texture03, sfTrue);
        sfSprite_setScale(button, scale_buttonn);
        sfSprite_setPosition(button, position_button);
    }
}

void mouseposition2(sfEvent event, sfRenderWindow* window,
sfSprite* button, sfSprite* buttonYY)
{
    static ButtonState state = STATE_IDLE;
    update_pencil_state(&state, window, button);
    update_window(&state, window, button);
    if (event.type == sfEvtMouseButtonPressed && state == STATE_CLICKED) {
        int x = sfMouse_getPosition(window).x;
        int y = sfMouse_getPosition(window).y;
    }
}

void display_color(sfRenderWindow* window, sfSprite* *sprite,
sfSprite* *button)
{

    sfSprite* *button22 = sfSprite_create();
    sfTexture* texture09 = sfTexture_createFromFile("./content/green.png", NULL);
    sfVector2f scale_buttonnn  = {0.1, 0.1}, position_button = {45, 86};
    sfSprite_setTexture(button22, texture09, sfTrue);
    sfSprite_setScale(button22, scale_buttonnn);
    sfRenderWindow_drawSprite(window, button22, NULL);
    sfRenderWindow_display(window);
}

int game_fuctions(sfEvent event, sfRenderWindow* window, int x_b)
{
    t_game_function *game = malloc(sizeof(t_game_function) * 8);
    load_background(window,game); color_yellow(window,game);
    color_green(window,game); color_red(window,game);
    color_blue(window,game); load_gomme(window,game);
    answer_gomme(window,game); load_pencil(window,game);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game[5].sprite, NULL);
        sfRenderWindow_drawSprite(window, game[0].sprite, NULL);
        sfRenderWindow_drawSprite(window, game[1].sprite, NULL);
        sfRenderWindow_drawSprite(window, game[3].sprite, NULL);
        sfRenderWindow_drawSprite(window, game[2].sprite, NULL);
        sfRenderWindow_drawSprite(window, game[4].sprite, NULL);
        sfRenderWindow_drawSprite(window, game[7].sprite, NULL);
        sfRenderWindow_drawSprite(window, game[6].sprite, NULL);
        sfRenderWindow_display(window);
        mouseposition2(event, window, game[7].sprite, game[6].sprite);
    } free(game); return 0;
}

void display2(sfRenderWindow* window, sfSprite* *sprite, sfSprite* *button)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, button, NULL);
    create_menu(window);
    sfRenderWindow_display(window);
}
