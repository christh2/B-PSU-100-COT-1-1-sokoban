/*
** EPITECH PROJECT, 2022
** move
** File description:
** p.c
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

int get_o(int x, int y, char **map, char **map2)
{
    int o = 0, z = 0;
    int * tab = (int *)malloc(sizeof(int) * 2);
    for ( int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            map2[i][j] == 'O' ? o++ : 0;
            (map[i][j] == 'X') & (map2[i][j] == 'O') ? z++ : 0;
            (map[i][j] == ' ') & (map2[i][j] == 'O') ? map[i][j] = 'O' : 0;
        }
    }
    return 0;
}

int move_to_up(char **card, int Key, int *tab)
{
    int i = tab[0], j = tab[1], x = 0, y = 0;
    if (Key == KEY_UP) {
        if (card[i - 1][j] != '#' && card[i - 1][j] != 'X') {
            card[i][j] = ' '; card[i - 1][j] = 'P';
        }
        if (card[i][j] == 'P' && card[i - 1][j] == 'X' &&
            card[i - 2][j] == ' ') {
            card[i][j] = ' '; card[i - 1][j] = 'P'; card[i - 2][j] = 'X';
        }
        if (card[i][j] == 'P' && card[i - 1][j] == 'X' &&
            card[i - 2][j] == 'O') {
            card[i][j] = ' '; card[i - 1][j] = 'P'; card[i - 2][j] = 'X';
        }
    }
}

int move_to_down(char **card, int Key, int *tab)
{
    int i = tab[0], j = tab[1], x = 0, y = 0;
    if (Key == KEY_DOWN) {
        if (card[i + 1][j] != '#' && card[i + 1][j] != 'X') {
            card[i][j] = ' '; card[i + 1][j] = 'P';
        }
        if (card[i][j] == 'P' && card[i + 1][j] == 'X' &&
            card[i + 2][j] == ' ') {
            card[i][j] = ' '; card[i + 1][j] = 'P'; card[i + 2][j] = 'X';
        }
        if (card[i][j] == 'P' && card[i + 1][j] == 'X' &&
            card[i + 2][j] == 'O') {
            card[i][j] = ' '; card[i + 1][j] = 'P'; card[i + 2][j] = 'X';
        }
    }
}

int move_to_right(char **card, int Key, int *tab)
{
    int i = tab[0], j = tab[1], x = 0, y = 0;
    if (Key == KEY_RIGHT) {
        if (card[i][j + 1] != '#' && card[i][j + 1] != 'X') {
            card[i][j] = ' '; card[i][j + 1] = 'P';
        }
        if (card[i][j] == 'P' && card[i][j + 1] == 'X' &&
            card[i][j + 2] == ' ') {
            card[i][j] = ' '; card[i][j + 1] = 'P'; card[i][j + 2] = 'X';
        }
        if (card[i][j] == 'P' && card[i][j + 1] == 'X' &&
            card[i][j + 2] == 'O') {
            card[i][j] = ' '; card[i][j + 1] = 'P'; card[i][j + 2] = 'X';
        }
    }
}

int move_to_left(char **card, int Key, int *tab)
{
    int i = tab[0], j = tab[1], x = 0, y = 0;
    if (Key == KEY_LEFT) {
        if (card[i][j - 1] != '#' && card[i][j - 1] != 'X') {
            card[i][j] = ' '; card[i][j - 1] = 'P';
        }
        if (card[i][j] == 'P' && card[i][j - 1] == 'X' &&
            card[i][j - 2] == ' ') {
            card[i][j] = ' '; card[i][j - 1] = 'P'; card[i][j - 2] = 'X';
        }
        if (card[i][j] == 'P' && card[i][j - 1] == 'X' &&
            card[i][j - 2] == 'O') {
            card[i][j] = ' '; card[i][j - 1] = 'P'; card[i][j - 2] = 'X';
        }
    }
}
