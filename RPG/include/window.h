/*
** EPITECH PROJECT, 2022
** ddd
** File description:
** ddd
*/

#include "message.h"
#include "text.h"
#include "struct.h"
#ifndef WINDOW_H
    #define WINDOW_H
    #include <stdlib.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #define ERROR 84
    #define CHECK_PTR NULL
typedef struct rect_s {
    sfIntRect UpRect;
    sfIntRect downRect;
    sfIntRect leftRect;
    sfIntRect rightRect;
}t_rect;

typedef struct window_game_s {
    sfRenderWindow *windows;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent  event;
}t_window_game;

typedef struct text_fight_s {
    sfTexture *texture;
    sfSprite *srpite;
    sfVector2f pos;
    sfVector2f size;
}t_text_figth;

typedef struct load_perso_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_load_perso;

typedef struct sprite1_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_sprite1;

typedef struct sprite2_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_sprite2;

typedef struct sprite3_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_sprite3;

typedef struct text_arrow {
    sfTexture *texture;
    sfSprite *srpite;
    sfVector2f pos;
    sfVector2f size;
}t_text_arrow;

typedef struct winner_s {
    sfTexture *texture;
    sfSprite *srpite;
    sfVector2f pos;
    sfVector2f size;
}t_winner;

typedef struct game_s {
    t_heros *hero;
    t_map *map;
    t_title *title;
    t_inventory *inventory;
    t_inventory_salamesh *salamesh;
    t_inventory_bulbizare *bulbizare;
    t_inventory_carapuce *carapuce;
    t_arrow *arrow;
    t_interdit *stop;
    t_healthbar *healtBar;
    t_level *level;
    t_rect *rect;
    t_interdit *panneau;
    t_new_map *new_map;
    t_dialogue *dialogue;
    t_text_figth *sprite_fight;
    t_text_arrow *text_arrow;
    t_load_perso *load_perso;
    t_sprite1 *sprite1;
    t_sprite2 *sprite2;
    t_sprite3 *sprite3;
}t_game;

typedef struct text_game_s {
    t_text_health *text_h;
    t_pourcent *text_inhealthBar;
    t_bullText *text_in_bull;
    t_text *textLevel;
    t_textplayers *textplayers;
    t_bull_hopital *bull_Hopital;
    t_access *access;
}t_textGame;

typedef struct inside_s {
    t_pharmacy *pharmacy;
    t_inside_house1 *inside_one;
    t_inside_house2 *inside_two;
    t_inside_house3 *inside_tree;
    t_inside_pockecenter *inside_pocenter;
}t_inside;

typedef struct draw_inside {
    t_in_hopital *hostipal;
}t_draw_inside;

typedef struct round1_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_round1;

typedef struct round2_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_round2;

typedef struct round3_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
}t_round3;

typedef struct fight_struct {
    t_round1 *round1;
    t_round2 *round2;
    t_round3 *round3;
}t_fight_struct;

t_window_game *create_window_game(t_map *map);
t_game *init_game(void);
void display_window_game(t_window_game *window,t_game *game,t_textGame\
*text_game,sfBool is_here, int i);
void free_game(t_game *game);
t_inside *init_inside(void);
t_rect *create_rect(void);
unsigned int is_hopital(t_map *map);
unsigned int is_house1(t_map *map);
unsigned int is_house2(t_map *map);
unsigned int is_house3(t_map *map);
unsigned int is_pokecenter(t_map *map);
bool check_habitat(t_map *map);
bool check_pos_inside(t_map *map);
bool check_pos_house(t_map *map);
t_new_map *create_new_map(sfVector2f pos,sfVector2f size);
bool keyboard_input(t_game *game,t_window_game *win);
unsigned int check_in_hopital(t_map *map);
t_in_hopital *create_in_hopital(void);
t_draw_inside *loading_draw_to_inside(void);
bool check_to_fight(t_map *map);
int fight_pokemon(int i,t_window_game *win,t_game *game);
t_round1 *loading_round(void);
t_round2 *loading_round2(void);
t_round3 *loading_round3(void);
t_fight_struct *loading_fight(void);
t_access *loading_assec_fight(sfFont *font);
t_text_figth *loading_fight_text(void);
t_load_perso *create_my_perso(void);
t_text_arrow *loading_arrow_text(void);
t_sprite1 *loading_sprite1(void);
t_sprite2 *loading_sprite2(void);
t_sprite3 *loading_sprite3(void);
unsigned int check_mouse_positon(t_window_game *win,t_game *game);
t_health *create_players1(sfVector2f pos,sfVector2f size,sfColor color);
t_health2 *create_players2(sfVector2f pos, sfVector2f size, sfColor color);
t_text_Players1 *create_text_play1(sfVector2f pos,sfFont *font, const char *message);
t_text_Players2 *create_text_play2(sfVector2f pos,sfFont *font, const char *message);
void how_to_play();
#endif /*WINDOW*/