/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** game
*/
#include "my_navy.h"
#include "my.h"

int game(char **map_self, char **map_enemy)
{
    pos_t coords;

    while (1) {
        play(&coords);
        handle_coords(map_self, map_enemy);
        miss_hit(&coords, map_enemy);
        win_lose();
    }
    return 0;
}
