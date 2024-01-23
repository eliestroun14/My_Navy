/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** a
*/
#include "my_navy.h"

int update_map(SIGNAL_e signal, pos_t coords, char **map)
{
    my_putstr("result : ");
    my_putchar((coords.x + 'A'));
    my_put_nbr(coords.y);
    if (signal == HIT) {
        my_putstr(":hit\n\n");
        map[coords.x][coords.y] = 'o';
    } else if (signal == MISS) {
        my_putstr(":missed\n\n");
    }
    send_signal(PLAY, global.pid);
    my_putstr("waiting for enemy's attack...\n\n");
    return 0;
}

int miss_hit(pos_t *coords, char **map)
{
    if (global.count == 7 && global.signal_value == HIT) {
        update_map(global.signal_value, *coords, map);
        global.count = 0;
        global.signal_value = 0;
        coords->x = 0;
        coords->y = 0;
    }
    return 0;
}
