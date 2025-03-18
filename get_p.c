/*
** EPITECH PROJECT, 2022
** position
** File description:
** position
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int *get_p(int x, int y, char **map)
{
    int j = 0;
    int * tab = NULL;
    tab = (int *)malloc(sizeof(int) * 2);
    for ( int i = 0; i < x; i++) {
        for (j = 0; j < y; j++)
            (map[i][j] == 'P') ? tab[0] = i, tab[1] = j : 0;
    } return tab;
}
