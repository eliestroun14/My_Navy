/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** play
*/
#include "my_navy.h"

pos_t play(void)
{
    pos_t coords;

    coords.x = 84;
    coords.y = 84;
    if (global.count == 7 && global.signal_value == PLAY) {
        global.count = 0;
        global.signal_value = 0;
        while (coords.x == 84 || coords.y == 84)
            coords = get_line();
        send_signal(coords.x, global.pid);
        send_signal(coords.y, global.pid);
    }
    return coords;
}
