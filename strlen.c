/*
** EPITECH PROJECT, 2022
** strlen
** File description:
** my_strlen.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;
    for (i = 0 ; str[i] != '\0' ; i++)
        my_putchar(str[i]);
}
