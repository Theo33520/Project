/*
** EPITECH PROJECT, 2022
** ddd
** File description:
** ddd
*/

#include "struct.h"
#include "message.h"
#include "text.h"

#ifndef hunter
    #define hunter

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include "struct.h"
    #include "message.h"
    #include "text.h"
    #include "window.h"
    #include "time.h"
    #include "fight.h"
    #include <stdio.h>
    #include <unistd.h>
    #define FrameLimite sfRenderWindow_setFramerateLimit




int window_image_x_y(void);
int game_fuctions(sfEvent event, sfRenderWindow* window, int x_b);

t_inventory_bulbizare *inventory_bulbizare(sfVector2f pos, sfVector2f size);
t_inventory_carapuce *inventory_carapuce(sfVector2f pos, sfVector2f size);
t_inventory_salamesh *inventory_salamesh(sfVector2f pos, sfVector2f size);
t_healthbar *create_healthbar(sfVector2f pos ,sfVector2f size, sfColor color);
t_title *create_the_title(sfVector2f pos);
t_inventory *create_inventory(sfVector2f pos);
t_arrow *create_arrow(sfVector2f pos, sfVector2f size);
t_message *create_new_message(sfVector2f size,sfVector2f pos);
t_heros *create_my_heros(sfVector2f origin,sfVector2f size);
t_text_health *loading_text_health(sfFont *font);
t_pourcent *loading_headlthbartext(sfFont *font);
t_level *create_levelbar(sfColor color);
t_text *loading_text_level(sfFont *font,sfVector2f pos);
t_textplayers *loading_text_players(sfFont *font);
t_bullText *loading_text_bull(sfFont *font);
t_map *create_my_map(sfVector2f pos,sfVector2f size);
t_map_collision *load_map_collions(sfVector2f pos, sfVector2f size);
t_interdit *load_panneau(sfVector2f pos,sfVector2f size);
t_pharmacy *loading_pharmacy(sfVector2f pos, sfVector2f size);
t_dialogue *create_sprite_for_dialogue(sfVector2f size,sfVector2f pos);

t_bull_hopital *loading_bull_hopital(sfFont *font);
bool check_house(t_map *map,sfBool is_find,t_map_collision *map_collision);
void error_handling(char const *error);
bool check_collision(t_map *map);
t_inside_house1 *loading_house1(sfVector2f pos,sfVector2f size);
t_inside_house2 *loading_house2(sfVector2f pos,sfVector2f size);
t_inside_house3 *loading_house3(sfVector2f pos,sfVector2f size);
t_inside_pockecenter *loading_pokencenter(sfVector2f pos,sfVector2f size);
#endif /* !hunter */
