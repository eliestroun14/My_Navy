/*
** EPITECH PROJECT, 2024
** navy
** File description:
** fill_struct
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "my_navy.h"
#include <stdlib.h>
#include "my.h"

int fill_struct(char **individual_info, navy_t *ship)
{
    ship->data->len_boat = my_getnbr(individual_info[0]);
    ship->data->pos_start->x = individual_info[1][0] - 65;
    ship->data->pos_start->y = individual_info[1][1] - 48 - 1;
    ship->data->pos_end->x = individual_info[2][0] - 65;
    ship->data->pos_end->y = individual_info[2][1] - 48 - 1;
}
