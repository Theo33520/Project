/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"
#include <SFML/Audio.h>

t_game *init_game(void)
{
    t_game *game = malloc(sizeof(t_game));
    if (game == NULL)
        return NULL;
    game->hero = create_my_heros((sfVector2f){0.0f, 0.0f},(sfVector2f){0.9f, 0.9f});
    game->map = create_my_map((sfVector2f){0,-580},(sfVector2f){2.0f,2.0f});
    game->title = create_the_title((sfVector2f){500,0});
    game->inventory = create_inventory((sfVector2f){1800,300});
    game->arrow = create_arrow((sfVector2f){0,450},(sfVector2f){0.1f,0.1f});
    game->salamesh = inventory_salamesh((sfVector2f){1810,670},(sfVector2f){0.06f,0.06f});
    game->carapuce = inventory_carapuce((sfVector2f){1810,670},(sfVector2f){0.1f,0.1f});
    game->bulbizare = inventory_bulbizare((sfVector2f){1810,670},(sfVector2f){0.1f,0.1f});
    game->stop = load_panneau((sfVector2f){100,100},(sfVector2f){0.3f,0.3f});
    sfColor my_green = sfColor_fromRGB(0x0D,0x97,0x00);
    game->healtBar = create_healthbar((sfVector2f){1550,50},(sfVector2f){200,30},my_green);
    sfColor color_level = sfColor_fromRGB(0xFF,0xCC,0x03);
    game->level = create_levelbar(color_level);
    game->panneau = load_panneau((sfVector2f){100,100},(sfVector2f){0.3f,0.3f});
    game->rect = create_rect();
    sfSprite_setTextureRect(game->hero->sprite,game->rect->downRect);
    game->new_map = create_new_map((sfVector2f){0,-580},(sfVector2f){2.0f,2.0f});
    game->dialogue = create_sprite_for_dialogue((sfVector2f){1.0f,1.0f},(sfVector2f){600,800});
    game->sprite_fight = loading_fight_text();
    game->text_arrow = loading_arrow_text();
    game->load_perso = create_my_perso();
    game->sprite1 = loading_sprite1();
    game->sprite2 = loading_sprite2();
    game->sprite3 = loading_sprite3();
    return game;
}
bool keyboard_input_error(t_game *game,t_window_game *win,sfBool is_well)
{
    sfBool is_touch = false;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && is_well == false) {
        sfSprite_move(win->sprite,(sfVector2f){0.1f, 0.0f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->leftRect);
        is_touch = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && is_well == false) {
        sfSprite_move(win->sprite,(sfVector2f){-0.1f, 0.0f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->rightRect);
        is_touch = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && is_well == false) {
        sfSprite_move(win->sprite,(sfVector2f){0.0f, 0.1f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->UpRect);
        is_touch = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && is_well == false) {
        sfSprite_move(win->sprite,(sfVector2f){0.0f, -0.1f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->downRect);
        is_touch = true;
    }
    return is_touch;
}

bool keyboard_input(t_game *game,t_window_game *win)
{
    sfBool is_touch = false;
    sfBool is_well = check_collision(game->map);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && is_well == true) {
        sfSprite_move(win->sprite,(sfVector2f){1.0f, 0.0f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->leftRect);
        is_touch = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && is_well == true) {
        sfSprite_move(win->sprite,(sfVector2f){-1.0f, 0.0f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->rightRect);
        is_touch = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && is_well == true) {
        sfSprite_move(win->sprite,(sfVector2f){0.0f, 1.0f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->UpRect);
        is_touch = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && is_well == true) {
        sfSprite_move(win->sprite,(sfVector2f){0.0f, -1.0f});
        sfSprite_setTextureRect(game->hero->sprite,game->rect->downRect);
        is_touch = true;
    }
    keyboard_input_error(game,win,is_well);
    return is_touch;
}


t_textGame *init_textgame(void)
{
    t_textGame *text_game = malloc(sizeof(t_textGame));
    if (text_game == NULL)
        return NULL;
    sfFont *font = sfFont_createFromFile("./content/BebasNeue-Regular.ttf");
    text_game->text_h = loading_text_health(font);
    text_game->text_inhealthBar = loading_headlthbartext(font);
    text_game->text_in_bull = loading_text_bull(font);
    text_game->textLevel = loading_text_level(font,(sfVector2f){1220,860});
    text_game->textplayers = loading_text_players(font);
    text_game->bull_Hopital = loading_bull_hopital(font);
    text_game->access = loading_assec_fight(font);
    return text_game;
}

static int check_position_new(t_game *game,sfVideoMode mode)
{
    if (game == NULL)
        return ERROR;
    sfVector2f hero_pos = {(float)mode.width / 2,(float)mode.height / 2};
    sfSprite_setPosition(game->hero->sprite,hero_pos);
    hero_pos.x -= 20.0f;
    hero_pos.y -= 30.0f;
    sfSprite_setPosition(game->hero->sprite,hero_pos);
    return SUCCESS;

}

int play_pokemon(int i)
{
    t_window_game *win = NULL;
    t_game *game = NULL;
    t_textGame *text_game = NULL;
    sfBool is_touch = false;
    game = init_game();
    text_game = init_textgame();
    win = create_window_game(game->map);
    sfBool is_here = false;
    sfVideoMode mode = {1920,1080,32};
    if (win == NULL || game == NULL)
        return 84;
    sfMusic *music = sfMusic_createFromFile("./content/cute-intro.wav");
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(win->windows)) {
        handle_event(win);
        is_here =  check_collision(game->map);
        is_touch = keyboard_input(game,win);
        if (check_position_new(game,mode) == ERROR)
            return ERROR;
        if (check_to_fight(game->map) && sfKeyboard_isKeyPressed(sfKeyF)) {
            sfMusic_stop(music);
            fight_pokemon(i,win,game);
        }
        display_window_game(win,game,text_game,is_here, i);
    }
    sfRenderWindow_destroy(win->windows);
    free_game(game);
    sfMusic_destroy(music);
    //free_textgame(text_game);
    return SUCCESS;
}
