/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** print_map
*/
#include <stddef.h>
#include "my_navy.h"
#include "my.h"

void print_map(char **map, char **map_enemy)
{
    my_putstr("my navy:\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
    }
    my_putstr("\n\nenemy navy:\n");
    for (int i = 0; map_enemy[i] != NULL; i++)
        my_putstr(map_enemy[i]);
    my_putstr("\n\n");
}
