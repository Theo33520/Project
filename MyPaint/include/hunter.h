/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/


#ifndef hunter
    #define hunter


    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <stdbool.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <stdio.h>
    #include <unistd.h>
    #define FrameLimite sfRenderWindow_setFramerateLimit

    typedef struct game_funcion_s {
        sfSprite *sprite;
        sfTexture *texture;
    }t_game_function;

    typedef enum {
        STATE_IDLE,
        STATE_HOVER,
        STATE_CLICKED
    } ButtonState;

    typedef enum GommeState_s {
        GommeState_Normal,
        GommeState_Selected,
        GommeState_Hover
    }GommeState;

    typedef struct menu_sprite_s{
        sfSprite* sprite;
        sfTexture* texture;
        sfVector2f scale;
        sfVector2f position;
    } MenuSprite;

    typedef struct menu_text_s{
        sfText* text;
        sfVector2f position;
    } MenuText;

    typedef struct menu_s{
        MenuSprite sprite;
        MenuText text[3];
    } Menu;

int mouseposition(sfEvent event, sfRenderWindow* window);
int window_image_x_y(void);
int game_fuctions(sfEvent event, sfRenderWindow* window, int x_b);
int create_menu(sfRenderWindow* window);
void load_background(sfRenderWindow *window, t_game_function *game);
void color_yellow(sfRenderWindow *window,t_game_function *game);
void color_green(sfRenderWindow *window,t_game_function *game);
void color_red(sfRenderWindow *window,t_game_function *game);
void color_blue(sfRenderWindow *window,t_game_function *game);
void load_gomme(sfRenderWindow *window,t_game_function *game);
void answer_gomme(sfRenderWindow *window,t_game_function *game);
void load_pencil(sfRenderWindow *window, t_game_function *game);


#endif /* !hunter */
