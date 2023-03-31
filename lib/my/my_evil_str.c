/*
** EPITECH PROJECT, 2022
** my_evil_str.c
** File description:
** Day 04, Task 04
*/

#include "include/my.h"

char * my_evil_str(char *str)
{
    int last = my_strlen(str);

    for (int i = 0; i != last / 2; i++) {
        my_swap_char(str + i,str + last - i - 1);
    }
    return str;
}
