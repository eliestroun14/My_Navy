/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** check_win_lose
*/
#include <stddef.h>
#include "my.h"

int check_win_lose(char **map_self)
{
    int cpt = 0;

    for (int i = 0; map_self[i] != NULL; i++)
        cpt += my_getnbr(map_self[i]);
    if (!cpt)
        return 0;
    return 1;
}
