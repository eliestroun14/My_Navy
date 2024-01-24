/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** win_lose
*/
#include "my.h"
#include "my_navy.h"

int win_lose(char **map_self, char **map_enemy)
{
    if (!check_win_lose(map_self, map_enemy)) {
        if (global.victory == 1) {
            print_map(map_self, map_enemy);
            my_putstr("I won\n");
            return 1;
        } else if (global.victory == -1) {
            print_map(map_self, map_enemy);
            my_putstr("enemy won\n");
            return 1;
        }
    }
    return 0;
}
