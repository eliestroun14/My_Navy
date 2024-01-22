/*
** EPITECH PROJECT, 2024
** navy
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "my_navy.h"
#include <stdlib.h>
#include "my.h"

int print_dash_h(void)
{
    my_printf("USAGE :\n ./cmd [file] for player 1\n ./cmd [signal] [file] for\
player 2\n");
    return 0;
}

int init_map(char **map, navy_t **tab, char const *argv)
{
    if (get_info(argv, tab) == 84)
        return 84;
    get_map(tab, map);
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s\n", map[i]);
    }
    return 0;
}

int main(int argc, char const **argv)
{
    navy_t **tab = innit_tab();
    char **map = innit_map();

    if (argc < 2 || argc > 3) {
        my_printf("invalid number of parameter,\ntry ./[binary] -h\n");
        return 84;
    }
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return print_dash_h();
    if (argc == 2) {
        init_map(map, tab, argv[1]);
        player_1(map);
    }
    if (argc == 3) {
        init_map(map, tab, argv[2]);
        //send_signal();
    }
    free_all(tab, map);
    return 0;
}
