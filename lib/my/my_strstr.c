/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** Day 06, task05
*/

#include "include/my.h"

static int test (char *str, char const *to_find, int i, int x)
{
    if (str[x + i] != to_find[x]) {
        return 0;
    }
    return 1;
}

static int find(char *str, char const *to_find, int i)
{
    int ok = 1;
    if (str[i] == to_find[0]) {
        for (int x = 0; to_find[x] != '\0'; x++) {
            ok = test(str, to_find, i, x);
        }
    } else {
        return 0;
    }
    return ok;
}

char *my_strstr(char *str, char const *to_find)
{
    int pass = 0;

    if (my_strlen(to_find) < 1) {
        return str;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (find(str, to_find, i)) {
            return str + i;
        }
    }
    return 0;
}
