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

int get_line(void)
{
    char *buff = NULL;
    size_t len = 0;
    ssize_t read;
    int coord = 0;

    read = getline(&buff, &len, stdin);
    coord = my_getnbr(buff);
    return coord;
}