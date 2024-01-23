/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** play
*/
#include "my_navy.h"
#include "my.h"

int play(pos_t *coords, char **map_self, char **map_enemy)
{
    if (global.count == 8 && global.signal_value == PLAY) {
        coords->x = 84;
        coords->y = 84;
        my_putstr("attack :");
        global.count = 0;
        global.signal_value = 0;
        while (coords->x == 84 || coords->y == 84)
            *coords = get_line();
        send_signal(coords->x, global.pid);
        send_signal(coords->y, global.pid);
        global.print_map++;
        if (global.print_map == 2) {
        print_map(map, map_enemy);
        global.print_map = 0;
    }
    }
    return 0;
}
