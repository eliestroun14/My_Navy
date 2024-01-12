/*
** EPITECH PROJECT, 2024
** navy
** File description:
** get_info
*/
#include "my_navy.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"

static char *open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat filestat;
    char *buff = NULL;

    if (stat(filepath, &filestat) == -1)
        return NULL;
    buff = malloc(sizeof(char) * (filestat.st_size + 1));
    read(fd, buff, filestat.st_size);
    close(fd);
    buff[filestat.st_size] = '\0';
    return buff;
}

static int is_enought_arg(char **info)
{
    int i = 0;

    while (info[i] != NULL)
        i++;
    return i;
}

static int check_between_2_5(char *info, navy_t *ship)
{
    char **individual_info = my_str_to_word_array(info, ':');

    if (individual_info == NULL)
        return 0;
    if (my_getnbr(individual_info[0]) >= 2 && my_getnbr(individual_info[0])
        <= 5) {
        if (is_enought_arg(individual_info) != 3) {
            free_tab(individual_info);
            return 84;
        }
        fill_struct(individual_info, ship);
        free_tab(individual_info);
        return 0;
    }
    free_tab(individual_info);
    return 84;
}

int get_info(char *filepath, navy_t **tab)
{
    char *arg = open_file(filepath);
    char **info = my_str_to_word_array(arg, '\n');

    if (is_enought_arg(info) != 4)
        return 84;
    for (int i = 0; info[i] != NULL; i++) {
        if (check_between_2_5(info[i], tab[i]) == 84) {
            free_tab(info);
            return 84;
        }
    }
    free(arg);
    free_tab(info);
    return 0;
}
