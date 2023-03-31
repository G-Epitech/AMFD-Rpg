/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** Day 04, Task 05
*/

#include "include/my.h"

static int right_part(char const *str, int moins)
{
    long new = 0;
    int value = 0;

    while (*str != '\0' && *str >= '0' && *str <= '9') {
        if (new > 2147483647 || new < -2147483648)
            return 0;
        new *= 10;
        new += *str - '0';
        str++;
    }
    if (moins % 2 != 0){
        new = new * -1;
    }
    if (new > 2147483647 || new < -2147483648) {
        return 0;
    }
    value = new;
    return value;
}

int my_getnbr(char const *str)
{
    int have = 0;
    int moins = 0;
    int i = 0;
    char last = 0;

    while (have != 1 && str[i] != '\0') {
        last = 0;
        if (str[i] >= '0' && str[i] <= '9') {
            have = 1;
        } else {
            last = str[i];
            i++;
        }
        if (last == '-')
            moins++;
    }
    if (!have)
        return 0;
    return right_part(str, moins);
}
