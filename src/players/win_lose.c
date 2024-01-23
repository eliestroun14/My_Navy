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
    if (global.count == 8 && global.signal_value == WIN) {
        print_map(map_self, map_enemy);
        my_putstr("I won\n");
        send_signal(LOSE, global.pid);
        return 1;
    } else if (global.count == 8 && global.signal_value == LOSE) {
        print_map(map_self, map_enemy);
        my_putstr("enemy won\n");
        return 1;
    }
    return 0;
}
