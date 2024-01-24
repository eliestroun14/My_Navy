/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** check_win_lose
*/
#include <stddef.h>
#include "my.h"
#include "my_navy.h"

int check_win_lose(char **map_self, char **map_enemy)
{
    int cpt = 0;

    for (int i = 0; map_self[i] != NULL; i++) {
        for (int j = 0; map_self[i][j] != '\0'; j++)
            if (map_self[i][j] == 'x')
                cpt++;
    }
    if (cpt >= 14) {
        global.victory = -1;
        return 0;
    }
    cpt = 0;
    for (int i = 0; map_enemy[i] != NULL; i++) {
        for (int j = 0; map_enemy[i][j] != '\0'; j++)
            if (map_enemy[i][j] == 'x')
                cpt++;
    }
    if (cpt >= 14) {
        global.victory = 1;
        return 0;
    }
    return 1;
}
