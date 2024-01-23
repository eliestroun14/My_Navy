/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** a
*/
#include "my_navy.h"
#include "my.h"

int update_map(SIGNAL_e signal, pos_t coords, char **map)
{
    my_putstr("result : ");
    my_putchar((coords.x + 'A' - 1));
    my_put_nbr(coords.y);
    if (signal == HIT) {
        my_putstr(":hit\n\n");
        map[coords.y - 1][coords.x - 1] = 'o';
    } else if (signal == MISS) {
        my_putstr(":missed\n\n");
    }
    send_signal(PLAY, global.pid);
    my_putstr("waiting for enemy's attack...\n\n");
    return 0;
}

int miss_hit(pos_t *coords, char **map)
{
    if (global.count == 8 &&
    (global.signal_value == HIT || global.signal_value == MISS)) {
        update_map(global.signal_value, *coords, map);
        global.count = 0;
        global.signal_value = 0;
        coords->x = 0;
        coords->y = 0;
    }
    return 0;
}
