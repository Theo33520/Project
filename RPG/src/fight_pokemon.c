/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"
#include <SFML/Audio.h>

sfSprite* create_sprite(const char* filepath, sfVector2f position, sfVector2f scale)
{
    sfTexture* texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void handle_events(sfRenderWindow* window, sfSprite** sprites)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed){
            sfRenderWindow_close(window);
        }
        else if (event.type == sfEvtMouseButtonPressed) {
            sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);
            if (mouse_position.x > 200 && mouse_position.x < 300 && mouse_position.y > 200 && mouse_position.y < 300){
                printf("Attaque\n");
                sfSprite_destroy(sprites[5]);
                sfSprite_destroy(sprites[6]);
                sprites[5] = NULL;
                sprites[6] = NULL;
                sprites[5] = create_sprite("./content/battle.png", (sfVector2f){900, 900}, (sfVector2f){0.5f, 0.5f});
                sprites[6] =create_sprite("./content/battle.png", (sfVector2f){1000, 1000}, (sfVector2f){0.5f, 0.5f});
            } else if (mouse_position.x > 500 && mouse_position.x < 600 && mouse_position.y > 500 && mouse_position.y < 600){
                printf("Attaque\n");
                sfSprite_destroy(sprites[5]);
                sfSprite_destroy(sprites[6]);
                sprites[5] = NULL;
                sprites[6] = NULL;
                sprites[5] = create_sprite("./content/battle.png", (sfVector2f){900, 900}, (sfVector2f){0.5f, 0.5f});
                sprites[6] = create_sprite("./content/battle.png", (sfVector2f){1000, 1000}, (sfVector2f){0.5f, 0.5f});
            }
        }
    }
}

sfRenderWindow* create_window(int width, int height, const char* title)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

sfSprite** create_sprites()
{
    sfSprite** sprites = (sfSprite**) malloc(6 * sizeof(sfSprite*));
    sprites[0] = create_sprite("./content/arene.jpg", (sfVector2f){0, 0}, (sfVector2f){1.f, 1.f});
    sprites[1] = create_sprite("./content/mechant.png", (sfVector2f){400, 470}, (sfVector2f){0.3, 0.3});
    sprites[2] = create_sprite("./content/salamesh.png", (sfVector2f){1200, 350}, (sfVector2f){0.2, 0.2});
    sprites[3] = create_sprite("./content/carapuce.png", (sfVector2f){1200, 570}, (sfVector2f){0.3, 0.3});
    sprites[4] = create_sprite("./content/bulbizare.png", (sfVector2f){1200, 570}, (sfVector2f){0.3, 0.3});
    sprites[5] = create_sprite("./content/battle.png", (sfVector2f){200, 100}, (sfVector2f){0.5f, 0.5f});
    sprites[6] = create_sprite("./content/battle.png", (sfVector2f){200, 100}, (sfVector2f){0.5f, 0.5f});
    return sprites;
}

#include <stdlib.h>
#include <stdbool.h>

char* int_to_str(int nb)
{
    bool is_negative = nb < 0;
    if (is_negative) {
        nb = -nb;
    }
    int size = 1;
    int tmp = nb;
    while (tmp >= 10) {
        size++;
        tmp /= 10;
    }
    if (is_negative) {
        size++;
    }
    char* str = (char*) malloc(sizeof(char) * (size + 1));
    str[size] = '\0';
    int i = size - 1;
    while (nb >= 10) {
        str[i] = nb % 10 + '0';
        nb /= 10;
        i--;
    }
    str[i] = nb + '0';
    if (is_negative) {
        str[0] = '-';
    }
    return str;
}

char  *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = my_strlen(dest);
    while (src[i] != '\0') {
        dest[a + i] = src[i];
        i++;
    }
    dest[a + i] = '\0';
    return dest;
}



int my_strlen(char const *str)
{
    if (str == NULL)
        return 0;
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

t_well *init_bool(void)
{
    t_well *is_well = malloc(sizeof(t_well));
    if (is_well == NULL)
        return NULL;
    is_well->is_attacking = false;
    is_well->is_attacking2 = false;
    is_well->show_fire = false;
    is_well->water_firee = false;
    return is_well;
}

void handle_game_logic(sfRenderWindow* window, sfSprite** sprites, int i,t_window_game *win,t_game *game)
{
    char* pokemon = "seif";
    int vie_gentil = 100;
    int vie_mechant = 100;
    int x = 530;
    int direction = 1;
    unsigned int  loop = check_mouse_positon(win,game);
    t_fight_struct *fight_struct = loading_fight();
    t_fight *fight = create_my_fight();
    sfSprite* sprite1 = create_sprite("./content/battle.png", (sfVector2f){200, 100}, (sfVector2f){0.5f, 0.5f});
    t_well *is_well = init_bool();
    sfColor my_green = sfColor_fromRGB(0x0D,0x97,0x00);
    sfColor my_color = sfColor_fromRGB(255, 168, 22);
    sfColor my_red = sfColor_fromRGB(202,0,0);
    t_health *players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_green);
    t_health2 *players2 = create_players2((sfVector2f){200,50},(sfVector2f){200,30},my_green);
    sfClock* clock = sfClock_create();
    sfMusic *music = sfMusic_createFromFile("./content/boxe.wav");
    sfMusic *applau = sfMusic_createFromFile("./content/applau.wav");
    int k = 0;
    sfFont *font = sfFont_createFromFile("./content/BebasNeue-Regular.ttf");
    t_text_Players1 *text_Players1 = create_text_play1((sfVector2f){1620,53},font,"100 / 100");
    t_text_Players2 *text_Players2 = create_text_play2((sfVector2f){270,53},font,"100 / 100");
    sfMusic_play(music);
    loop = rand() % 3;
    if (loop == 0)
        loop += 3;
    while (sfRenderWindow_isOpen(window)){
        handle_events(window, sprites);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprites[0], NULL);
        sfRenderWindow_drawSprite(window, sprites[1], NULL);
        sfSprite_setPosition(sprites[1], (sfVector2f){x, 470});
        if (loop == 1){
            sfSprite_setPosition(sprites[2], (sfVector2f){x+700, 600});
            sfRenderWindow_drawSprite(window, sprites[2], NULL);
            pokemon = "salamesh";
        }
        if (loop == 2){
            sfSprite_setPosition(sprites[3], (sfVector2f){x+700, 600});
            sfRenderWindow_drawSprite(window, sprites[3], NULL);
            pokemon = "carapuce";
        }
        if (loop == 3){
            sfSprite_setPosition(sprites[4], (sfVector2f){x+700, 600});
            sfRenderWindow_drawSprite(window, sprites[4], NULL);
            pokemon = "bulbizar";
        }
        sfRenderWindow_drawSprite(window, sprites[1], NULL);
        sfRenderWindow_display(window);
        x += direction * 1;
        if (x > 580) {
            direction = -1;
        } else if (x < 520) {
            direction = 1;
        }
        sfMusic_play(applau);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
            sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite1);
            if (sfFloatRect_contains(&sprite_bounds, mouse_pos.x, mouse_pos.y)) {
                if (!is_well->is_attacking) {
                    int random_number;
                    srand(time(NULL));
                    random_number = rand() % 16 + 15;
                    vie_mechant = vie_mechant - random_number;
                   char *live_menewto = int_to_str(vie_mechant);
                   my_strcat(live_menewto," / 100");
                   if (vie_mechant <= 0){
                    sfRenderWindow_close(window);
                   }
                    is_well->is_attacking = true;
                    is_well->show_fire = true;
                    sfSprite_setPosition(sprite1, (sfVector2f){1300, 100});
                    k++;
                    if (vie_mechant >= 80 && vie_mechant <= 100)
                        players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_green);
                    if (vie_mechant >= 30 && vie_mechant <= 79)
                        players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_color);
                    if (vie_mechant >= 0 && vie_mechant <= 29)
                        players1 = create_players1((sfVector2f){1550,50},(sfVector2f){200,30},my_red);
                    text_Players1 = create_text_play1((sfVector2f){1620,53},font,live_menewto);
                } else {
                    int random_number2;
                    srand(time(NULL));
                    random_number2 = rand() % 16 + 15;
                    vie_gentil = vie_gentil - random_number2;
                    char *live_gentil = int_to_str(vie_gentil);
                    my_strcat(live_gentil," / 100");
                    if (vie_gentil <= 0){
                    sfRenderWindow_close(window);
                   }
                    is_well->is_attacking = false;
                    is_well->water_firee = true;
                    sfSprite_setPosition(sprite1, (sfVector2f){200, 100});
                    if (vie_gentil >= 80 && vie_gentil <= 100)
                        players2 = create_players2((sfVector2f){200,50},(sfVector2f){200,30},my_green);
                    if (vie_gentil >= 30 && vie_gentil <= 79)
                        players2 = create_players2((sfVector2f){200,50},(sfVector2f){200,30},my_color);
                    if (vie_gentil >= 0 && vie_gentil <= 29)
                        players2 = create_players2((sfVector2f){200,50},(sfVector2f){200,30},my_red);
                    text_Players2 = create_text_play2((sfVector2f){270,53},font,live_gentil);
                }
            }
        }
        if (is_well->show_fire) {
            sfTime elapsed_time = sfClock_getElapsedTime(clock);
            if (sfTime_asSeconds(elapsed_time) < 3.0) {
                sfRenderWindow_drawSprite(window,fight->fire->sprite, NULL);
            } else {
                is_well->show_fire = false;
                sfClock_restart(clock);
            }
        }
        if (is_well->water_firee) {
            sfTime elapsed_time = sfClock_getElapsedTime(clock);
            if (sfTime_asSeconds(elapsed_time) < 3.0) {
                sfRenderWindow_drawSprite(window, fight->water->sprite, NULL);
            } else {
                is_well->water_firee = false;
                sfClock_restart(clock);
            }
        }
        if (k <= 2)
            sfRenderWindow_drawSprite(window,fight_struct->round1->sprite,NULL);
        else if (k == 3 || k == 4) {
            sfRenderWindow_drawSprite(window,fight_struct->round2->sprite,NULL);
        }
        else {
            sfRenderWindow_drawSprite(window,fight_struct->round3->sprite,NULL);
            sfMusic_play(music);
        }
        sfRenderWindow_drawSprite(window, sprite1, NULL);
        sfRenderWindow_drawRectangleShape(window,players1->rectangle,NULL);
        sfRenderWindow_drawRectangleShape(window,players2->rectangle,NULL);
        sfRenderWindow_drawText(window,text_Players1->text,NULL);
        sfRenderWindow_drawText(window,text_Players2->text,NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprites[0]);
    sfSprite_destroy(sprites[1]);
    sfSprite_destroy(sprites[2]);
    sfSprite_destroy(sprites[3]);
    sfSprite_destroy(sprites[4]);
    free(sprites);
    free_fight(fight);
}

int fight_pokemon(int i,t_window_game *win,t_game *game)
{
    sfRenderWindow* window = create_window(1920, 1080, "Ma fenêtre");
    sfSprite** sprites = create_sprites();
    handle_game_logic(window, sprites, i,win,game);

}
