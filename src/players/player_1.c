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
#include <sys/types.h>

int player_1(char **map_self, char **map_enemy)
{
    pid_t process_id = getpid();

    global.signal_value = 0;
    global.count = 0;
    global.pid = -1;
    global.print_map = false;
    my_putstr("my_pid: ");
    my_put_nbr(process_id);
    my_putstr("\n\nwaiting for enemy connection...\n\n");
    while (1) {
        if (global.count == 8 && global.signal_value == P2_CONECTED) {
            my_putstr("enemy connected\n\n");
            global.count = 0;
            global.signal_value = 0;
            send_signal(P1_READY, global.pid);
            game(map_self, map_enemy);
        }
    }
}
