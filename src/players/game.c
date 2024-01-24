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
        if (win_lose(map_self, map_enemy))
            return 0;
        play(&coords, map_self, map_enemy);
        handle_coords(map_self, map_enemy);
        miss_hit(&coords, map_enemy);
    }
    return 1;
}
