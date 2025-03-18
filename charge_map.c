/*
** EPITECH PROJECT, 2022
** maps
** File description:
** maps
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
#include <string.h>

int get_o(int x, int y, char **map, char **map2);
char **str_array(char *str);
int mini_printf(const char *format, ...);
void help_h(void);
int *get_p(int x, int y, char **map);
int move_to_up(char **card, int Key, int *tab);
int move_to_down(char **card, int Key, int *tab);
int move_to_right(char **card, int Key, int *tab);
int move_to_left(char **card, int Key, int *tab);
int main(int ac, char **av);
int my_putstr(char const *str);
int my_putchar(char c);

int compt_lignes(char *buffer)
{
    int i = 0;
    int j = 0;
    for (; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n')
            j++;
    }
    return j;
}

int compt_cols(char *buffer)
{
    int i = 0, j = 0; int mx = 0;
    for (;buffer[i] != '\0'; i++) {
        j++;
        if (buffer[i] == '\n') {
            (j > mx) ? mx = j : mx;
            j = 0;
        }
    }
    return mx;
}

char *simple_tab(char *str)
{
    int i = 0; int j;
    struct stat cote;
    stat(str, &cote);
    int val = cote.st_size; int fd;
    char *buffer = malloc(sizeof(char) * (val + 1));
    fd = open(str, O_RDONLY);
    read(fd, buffer, val);
    buffer[val] = '\0';
    close(fd);
    return buffer;
}

char **str_array(char *str)
{
    int i = 0, j = 0, x = 0; int lignes = 0;
    lignes = compt_lignes(str);
    int cols = 0; cols = compt_cols(str);
    char **tab = NULL; tab = malloc(sizeof(char *) * (lignes + 1));
    for (i = 0; i < lignes; i++) {
        tab[i] = malloc(sizeof(char) * (cols + 1));
        tab[i][0] = '\0';
        for (x = 0; str[j] != '\0' && x < cols && str[j] != '\n'; j++) {
            tab[i][x] = str[j]; x++;
        }
        tab[i][x] = '\0'; j++; x = 0;
    } tab[i] = NULL;
    for (int y = 0; tab[y] != NULL; y++) {
    }
    return tab;
}

int window(int ac, char **av)
{
    int i = 0; char *buffer = NULL; buffer = simple_tab(av[1]);
    int lignes = compt_lignes(buffer); int cols = compt_cols(buffer);
    char **tab = str_array(buffer); char **table2 = table2 = str_array(buffer);
    initscr(); curs_set(false);
    keypad(stdscr, TRUE); refresh(); int c = 0; int *tab1 = NULL;
    while (c != 32) {
        clear();
        for (int y = 0; tab[y] != NULL; y++)
            printw("%s\n", tab[y]);
        c = getch();
        tab1 = get_p(lignes, cols, tab);
        move_to_down(tab, c, tab1); move_to_up(tab, c, tab1);
        move_to_right(tab, c, tab1); move_to_left(tab, c, tab1);
        if (get_o(lignes, cols, tab, table2) == 1) {
            endwin(); return 0;
        } refresh();
    } endwin();
    for (; tab[i] != NULL; i++) {
        free(tab[i]);
    } free(tab); free(buffer); return 0;
}
