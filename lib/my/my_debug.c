/*
** EPITECH PROJECT, 2022
** tests_my_putchar.c
** File description:
** char file
*/

#include "include/my.h"

void debug_nbr(char const *texte, int nbr)
{
    my_putstr(texte);
    my_putstr(" => ");
    my_put_nbr(nbr);
    my_putchar('\n');
}

void debug_str(char const *texte, const char *str)
{
    my_putstr(texte);
    my_putstr(" => ");
    my_putstr(str);
    my_putchar('\n');
}

void separator(void)
{
    my_putstr("===================");
    my_putchar('\n');
}
