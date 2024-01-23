/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** get_line
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_navy.h"
#include "my.h"

pos_t get_line(void)
{
    char *buff = NULL;
    size_t len = 0;
    pos_t coords = {84, 84};

    getline(&buff, &len, stdin);
    if (my_strlen(buff) != 3 || !is_char_upper(buff[0])) {
        my_putstr("\n\nWrong position\n\n");
        return coords;
    }
    coords.x = buff[0] - 'A' + 1;
    coords.y = my_getnbr(buff);
    if ((coords.x <= 0 || coords.x > 8) || (coords.y <= 0 || coords.y > 8)) {
        my_putstr("\n\nWrong position\n\n");
        my_putstr("attack :");
        coords.x = 84;
        coords.y = 84;
        return coords;
    }
    return coords;
}
