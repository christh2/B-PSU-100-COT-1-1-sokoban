/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
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

char **str_array(char *str);
char *simple_tab(char *str);
int window(int ac, char **av);
void help_h(void);
int my_putstr(char const *str);
int my_putchar(char c);

int verify_map(char **tab)
{
    int i = 0, j = 0;
    for (i = 0; tab[i] != NULL; i++) {
        for (j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] != '#' && tab[i][j] != 'X' && tab[i][j] != 'O' &&
                tab[i][j] != 'P' && tab[i][j] != ' ' && tab[i][j] != '\n') {
                return 84;
            }
        }
    } return 0;
}

int main(int ac, char **av)
{
    char *str = simple_tab(av[1]); int x = 0, y = 0;
    char **tab = str_array(str); int v = verify_map(tab);
    if (ac != 2 || v == 1) {
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help_h();
        return 0;
    }
    if (v == 84) {
        return 84;
    } else {
        window(ac, av);
    }
    return (0);
}
