/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** player_1
*/
#include "my.h"
#include "my_navy.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>

pos_t play(void)
{
    pos_t coords;

    if (global.signal_value == PLAY) {
        coords.x = get_line();
        coords.y = get_line();
        send_signal(coords.x, global.pid);
        send_signal(coords.y, global.pid);
    }
    return coords;
}

int miss_hit(pos_t *coords)
{
    if (global.signal_value == HIT) {
        //update_map(1, coords/*, map*/);
        coords->x = 0;
        coords->y = 0;
    } else if (global.signal_value == MISS) {
        //update_map(0, coords/*, map*/);
        coords->x = 0;
        coords->y = 0;
    }
    return 0;
}

int handle_coords(void)
{
    pos_t coords_recieved;

    if (global.count == 7 && global.signal_value < 9 && global.signal_value > 0) {
        coords_recieved.x = global.signal_value;
        global.signal_value = 0;
        if (global.count == 15 && global.signal_value < 9 && global.signal_value > 0) {
            coords_recieved.y = global.signal_value;
            global.signal_value = 0;
            global.count = 0;
            //check_map(coords_recieved);
        }
    }
    return 0;
}

int game(void)
{
    pos_t coords;

    while (1) {
        coords = play();
        handle_coords();
        miss_hit(&coords);
        //win_lose();
    }
}

int player_1(char **map)
{
    global.signal_value = 0;
    global.count = 0;
    global.pid = -1;

    write(1, "waiting for a player", my_strlen("waiting for a player"));
    if (global.count == 7 && global.signal_value == P2_CONECTED) {
        global.count = 0;
        global.signal_value = 0;
        send_signal(P1_READY, global.pid);
        game();
    }
    return 0;
}