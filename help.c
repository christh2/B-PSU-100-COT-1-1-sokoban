/*
** EPITECH PROJECT, 2022
** help
** File description:
** help
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_putstr(char const *str);
int my_putchar(char c);

int my_strlen(char const *str);

void help_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map.txt\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map file representing the warehouse map, contai");
    my_putstr("ning ‘#’ for walls,\n");
    my_putstr("    ‘P’ for the player, ‘X’ for boxes and");
    my_putstr("    ‘O’ for storage locations.\n");
}
