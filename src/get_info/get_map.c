/*
** EPITECH PROJECT, 2024
** navy
** File description:
** get_map
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "my_navy.h"
#include <stdlib.h>
#include "my.h"

void fill_map(navy_t *ship, char **map)
{
    if (ship->data->pos_start->x == ship->data->pos_end->x) {
        for (int i = ship->data->pos_start->y; i
            <= ship->data->pos_end->y; i++) {
            map[i][ship->data->pos_start->x] = ship->data->len_boat + 48;
        }
    }
    if (ship->data->pos_start->y == ship->data->pos_end->y)
        for (int i = ship->data->pos_start->x; i
            <= ship->data->pos_end->x; i++) {
            map[ship->data->pos_start->y][i] = ship->data->len_boat + 48;
        }
}

int get_map(navy_t **tab, char **map)
{
    for (int i = 0; tab[i] != NULL; i++) {
        fill_map(tab[i], map);
    }
}
