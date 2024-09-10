/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-seifdine.bargui
** File description:
** pencil
*/

#include <stdbool.h>
#include "../include/hunter.h"
#include "../my_printf/my.h"

/*main tu connais*/
int main(int argc, const char *const *argv, const char *const *env)
{
if (is_error(argc, argv, env) == 84)
        return 84;
    if (argc == 2 && argv[1][0] == '-') {
        menu_help();
        return (0);
    }else
    window_image_x_y();
    return (0);
}

/*si on enleve la varibale graphique il n'y aura pas de seg11*/
int is_error(int argc, const char *const *argv, const char *const *env)
{
    for (int i = 0; env[i] != NULL; i = i + 1){
        if (env[i][0] == 'D' && env[i][1] == 'I' && env[i][2] == 'S' && env[i]\
        [3] == 'P' && env[i][4] == 'L' && env[i][5] == 'A' && env[i][6] == 'Y')
            return (0);
    }
    return (84);
}
