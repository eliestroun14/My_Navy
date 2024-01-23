/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** handle_coords
*/
#include "my_navy.h"

int check_map(pos_t coords, char **map)
{
    if (map[coords.x][coords.y] != '.') {
        map[coords.x][coords.y] = 'X';
        send_signal(HIT, global.pid);
    } else if (map[coords.x][coords.y] == '.') {
        send_signal(MISS, global.pid);
    }
    return 0;
}

int handle_coords(char **map)
{
    pos_t coords_recieved;

    if (global.count == 7 && global.signal_value < 9 &&
    global.signal_value > 0) {
        coords_recieved.x = global.signal_value;
        global.signal_value = 0;
        if (global.count == 15 && global.signal_value < 9 &&
        global.signal_value > 0) {
            coords_recieved.y = global.signal_value;
            global.signal_value = 0;
            global.count = 0;
            check_map(coords_recieved, map);
        }
    }
    return 0;
}
