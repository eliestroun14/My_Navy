/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** player_2
*/
#include "my_navy.h"
#include <sys/types.h>

int player_2(char **map_self, char **map_enemy, int pid)
{
    global.signal_value = 0;
    global.count = 0;
    global.pid = pid;
    pid_t process_id = getpid();

    my_putstr("my_pid: ");
    my_put_nbr(process_id);
    if (global.count == 7 && global.signal_value == P1_READY) {
        my_putstr("successfully connected");
        global.count = 0;
        global.signal_value = 0;
        send_signal(PLAY, global.pid);
        game(map_self, map_enemy);
    }
}