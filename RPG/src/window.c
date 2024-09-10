/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

static unsigned int setup_background(t_window_game *window,t_map *map)
{
    if (map == NULL)
        return 84;
    if (map->textture != NULL)
        window->texture = map->textture;
    if (window->texture == NULL)
        return 84;
    if (map->sprite != NULL)
        window->sprite = map->sprite;
    return 0;
}


t_window_game *create_window_game(t_map *map)
{
    t_window_game *windows = malloc(sizeof(t_window_game));
    if (windows == NULL)
        return NULL;
    sfVideoMode mode = {1920,1080,32};
    windows->windows = sfRenderWindow_create\
    (mode,"MY RPG",sfResize | sfClose,NULL);
    sfRenderWindow_setFramerateLimit(windows->windows,60);
    if (windows->windows == NULL)
        return NULL;
    if (setup_background(windows,map) == 84) {
        free(windows);
        return NULL;
    }
    return windows;
}

int display_sprite_game(t_window_game *win,t_game *game,
int i,t_draw_inside *inside)
{
    if (win == NULL || game == NULL)
        return ERROR;
    sfBool is_touch = false;
    is_touch = keyboard_input(game,win);
    sfRenderWindow_drawSprite(win->windows, win->sprite, NULL);
    sfRenderWindow_drawSprite(win->windows,game->hero->sprite,NULL);
    sfRenderWindow_drawSprite(win->windows,game->inventory->sprite,NULL);
    if (!check_in_hopital(game->map) && !check_to_fight(game->map)) {
        sfRenderWindow_drawSprite(win->windows,game->sprite_fight->srpite,NULL);
        sfRenderWindow_drawSprite(win->windows,game->text_arrow->srpite,NULL);
    }
    unsigned int loop_hero = check_mouse_positon(win,game);
    int x = rand() % 3;
    if (x == 0)
        x += 3;
    if (!check_in_hopital(game->map))
        sfRenderWindow_drawSprite(win->windows,game->title->sprite,NULL);
    if (check_in_hopital(game->map)) {
        sfRenderWindow_drawSprite(win->windows,game->sprite1->sprite,NULL);
        sfRenderWindow_drawSprite(win->windows,game->sprite2->sprite,NULL);
        sfRenderWindow_drawSprite(win->windows,game->sprite3->sprite,NULL);
        sfRenderWindow_drawSprite(win->windows,inside->hostipal->sprite,NULL);
    }
    sfRenderWindow_drawSprite(win->windows,game->arrow->sprite,NULL);
    sfRenderWindow_drawRectangleShape\
    (win->windows,game->healtBar->rectangle,NULL);
    if (x == 1)
        sfRenderWindow_drawSprite(win->windows,game->salamesh->sprite,NULL);
    if (x== 2)
        sfRenderWindow_drawSprite(win->windows,game->carapuce->sprite,NULL);
    if (x == 3)
        sfRenderWindow_drawSprite(win->windows,game->bulbizare->sprite,NULL);
    if (!is_touch && !check_in_hopital(game->map)) {
        sfRenderWindow_drawSprite(win->windows,game->dialogue->sprite,NULL);
    }
    if (check_to_fight(game->map)) {
        sfRenderWindow_drawSprite(win->windows,game->dialogue->sprite,NULL);
        sfRenderWindow_drawSprite(win->windows,game->load_perso->sprite,NULL);
    }
    return SUCCESS;
}


int display_text_game(t_window_game *win, t_textGame *text_game,
t_game *game)
{
    if (win == NULL || text_game == NULL)
        return ERROR;
    sfBool is_touch = false;
    is_touch = keyboard_input(game,win);
    sfRenderWindow_drawText(win->windows,text_game->text_h->text,NULL);
    sfRenderWindow_drawText(win->windows,text_game->text_in_bull->text,NULL);
    sfRenderWindow_drawText\
    (win->windows,text_game->text_inhealthBar->text,NULL);
    if (check_to_fight(game->map))
        sfRenderWindow_drawText(win->windows,text_game->access->text,NULL);
    if(!is_touch && !check_in_hopital(game->map) && !check_to_fight(game->map))
        sfRenderWindow_drawText(win->windows,text_game->bull_Hopital->text,NULL);
    return SUCCESS;
}

bool check_inside(t_inside *inside, t_game *game,
t_window_game *win,t_draw_inside *draw)
{
    sfBool is_well = false;
    unsigned int is_hospital = is_hopital(game->map);
    unsigned int is_houseOne = is_house1(game->map);
    unsigned int is_houseTwo = is_house2(game->map);
    unsigned int is_houseThree = is_house3(game->map);
    unsigned int is_Pocketcenter = is_pokecenter(game->map);
    sfTexture *texture = win->texture;
    sfSprite *sprite = win->sprite;

    if (is_hospital == 1) {
        win->sprite = inside->pharmacy->sprite;
        game->map->sprite = win->sprite;
        is_well = true;
    }
    if (is_houseOne == 1) {
        win->sprite = inside->inside_one->sprite;
        game->map->sprite = win->sprite;
        is_well = true;
    }
    if (is_houseTwo == 1) {
        win->sprite = inside->inside_two->sprite;
        game->map->sprite = win->sprite;
        is_well = true;
    }
    if (is_houseThree == 1) {
        win->sprite = inside->inside_tree->sprite;
        game->map->sprite = win->sprite;
        is_well = true;
    }
    if (is_Pocketcenter == 1) {
        win->sprite = inside->inside_pocenter->sprite;
        game->map->sprite = win->sprite;
        is_well = true;
    }
    return is_well;
}
