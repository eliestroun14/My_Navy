/*
** EPITECH PROJECT, 2024
** navy
** File description:
** my_navy
*/

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct data_s {
    pos_t *pos_start;
    pos_t *pos_end;
    int is_touched;
    int len_boat;
} data_t;

typedef struct navy_s {
    data_t *data;
} navy_t;

//innit and free
navy_t **innit_tab(void);
char **innit_map(void);
int free_all(navy_t **tab, char **map);
int free_tab(char **tab);

//get info
int get_info(char *filepath, navy_t **tab);
int fill_struct(char **individual_info, navy_t *tab);
int get_map(navy_t **tab, char **map);

#endif /* !MY_NAVY_H_ */
