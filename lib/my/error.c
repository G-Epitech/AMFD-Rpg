/*
** EPITECH PROJECT, 2022
** error
** File description:
** @Made by Math alias T1nt1n
** Error file
*/

#include "include/my.h"
#include <unistd.h>

static int my_put_error(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}

int error(char *str)
{
    my_put_error(str);
    return 84;
}
