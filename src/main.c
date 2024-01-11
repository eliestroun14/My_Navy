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

int main(int argc, char **argv)
{
    navy_t **tab = innit_tab();
    char **map = innit_map();

    if (get_info(argv[1], tab) == 84)
        return 84;
    get_map(tab, map);
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s\n", map[i]);
    }
    free_all(tab, map);
    return 0;
}
