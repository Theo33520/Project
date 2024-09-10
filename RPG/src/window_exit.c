/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"
#include <SFML/Audio.h>

unsigned int exit_inside_house(t_game *game,t_window_game *win)
{
    if (game == NULL || win == NULL)
        return ERROR;
    if (check_pos_inside(game->map) == true) {
        game->map = create_my_map((sfVector2f)\
        {-428.000000,-323.000000},(sfVector2f){2.0f,2.0f});
        win->sprite = game->map->sprite;
    }
    if (check_pos_house(game->map) == true) {
        game->map = create_my_map((sfVector2f)\
        {-82.000000,-784.000000},(sfVector2f){2.0f,2.0f});
        win->sprite = game->map->sprite;
    }
    return SUCCESS;
}

void display_window_game(t_window_game *window,t_game *game,
t_textGame *text_game,sfBool is_here, int i)
{
    t_inside *inside = init_inside();
    t_draw_inside *inside_draw = loading_draw_to_inside();
    sfBool is_well = check_inside(inside,game,window,inside_draw);
    sfRenderWindow_clear(window->windows, sfBlack);
    if (exit_inside_house(game,window) == ERROR)
        return;
    if (display_sprite_game(window,game, i,inside_draw) == ERROR)
        return;
    if (!is_here)
        sfRenderWindow_drawSprite(window->windows,game->panneau->sprite,NULL);
    if (display_text_game(window,text_game,game) == ERROR)
            return;
    sfRenderWindow_display(window->windows);
}

unsigned int check_mouse_positon(t_window_game *win,t_game *game)
{
    while(sfRenderWindow_pollEvent(win->windows,&win->event)) {
        if (win->event.type == sfEvtMouseButtonPressed) {
            int x = sfMouse_getPositionRenderWindow(win->windows).x;
            int y = sfMouse_getPositionRenderWindow(win->windows).y;
            if (x >= 180 && x <= 353 & y >= 87 && y <= 257)
                return 1;
            if (x >= 579 && x <= 778 && y >= 104 && y <= 272)
                return 2;
            if (x >= 986 && x <= 1208 && y >= 105 && y <= 253)
                return 3;
        }
    }
    return 0;
}

void handle_event(t_window_game *window,t_game *game)
{
    while (sfRenderWindow_pollEvent(window->windows, &window->event)) {
        switch (window->event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(window->windows);
                break;
            case sfEvtMouseButtonPressed:
                int x = sfMouse_getPositionRenderWindow(window->windows).x;
                int y = sfMouse_getPositionRenderWindow(window->windows).y;

                if (x >= 0 && x <= 40 && y >= 435 && y <= 515) {
                    sfRenderWindow_close(window->windows);
                    break;
                }
            default:
                break;
        }
    }
}
