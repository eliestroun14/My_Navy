/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** game
*/
#include "my_navy.h"

int game(char **map_self, char **map_enemy)
{
    pos_t coords;

    while (1) {
        coords = play();
        handle_coords(map_self);
        miss_hit(&coords, map_enemy);
        win_lose();
    }
    return 0;
}
