/*
** EPITECH PROJECT, 2022
** hexadecimal_maj
** File description:
** task01
*/

#include "my.h"

void my_put_hexadecimal_maj(int nb)
{
    char hexa[16] = "0123456789ABCDEF";
    int div = nb / 16;
    int mod = nb % 16;
    int index = mod;
    while (div >= 16) {
        index = div % 16;
        div = div / 16;
    }
    if (div < 16) {
        my_putchar(hexa[div]);
    }
    if (index != mod) {
        my_putchar(hexa[index]);
    }
    my_putchar(hexa[mod]);
}
