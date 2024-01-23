/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** handle_coords
*/
#include "my_navy.h"
#include "my.h"
#include <stdio.h>

int check_map(pos_t coords, char **map, char **map_enemy)
{
    my_printf("result: %c%d", (coords.x + 'A' - 1), coords.y);
    if (map[coords.y - 1][coords.x - 1] != '.') {
        map[coords.y - 1][coords.x - 1] = 'X';
        my_putstr(":hit\n\n");
        send_signal(HIT, global.pid);
    } else if (map[coords.y - 1][coords.x - 1] == '.') {
        my_putstr(":missed\n\n");
        send_signal(MISS, global.pid);
    }
    if (!check_win_lose(map, map_enemy)) {
        send_signal(WIN, global.pid);
        return 0;
    }
    if (global.print_map)
        print_map(map, map_enemy);
    global.print_map = !global.print_map;
    return 0;
}

int handle_coords(char **map, char **map_enemy)
{
    pos_t coords_recieved;

    if (global.count == 8 && global.signal_value < 9 &&
    global.signal_value > 0) {
        coords_recieved.x = global.signal_value;
        global.signal_value = 0;
        while (global.count != 16);
        if (global.count == 16 && global.signal_value < 9 &&
        global.signal_value > 0) {
            coords_recieved.y = global.signal_value;
            global.signal_value = 0;
            global.count = 0;
            check_map(coords_recieved, map, map_enemy);
        }
    }
    return 0;
}
