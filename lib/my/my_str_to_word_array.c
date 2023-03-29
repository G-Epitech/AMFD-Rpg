/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** Day 09, task04
*/

#include <stdlib.h>
#include "include/my.h"
#include <stdbool.h>
#include <stdio.h>

static bool is_space(char a)
{
    if (a == '=' || a == ' ' || a == '\0' || a == '\n') {
        return true;
    }
    return false;
}

static unsigned long allocation(char const *str)
{
    int memory = 1;

    for (int i = 0; i < my_strlen(str); i++) {
        if (i > 0 && !is_space(str[i]) && is_space(str[i - 1]))
            memory++;
    }
    return sizeof(char *) * (memory + 1) + sizeof(char) * my_strlen(str);
}

static int get_word(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_space(str[i])) {
            return i - 1;
        }
    }
    return my_strlen(str);
}

static char **fill_array(char **arr, char const *str)
{
    int key_arr = 0;
    int new_key = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (!is_space(str[i])) {
            new_key = get_word(&str[i]);
            arr[key_arr] = malloc(sizeof(char) * (new_key + 2));
            my_strncpy(arr[key_arr], &str[i], new_key + 1);
            arr[key_arr][new_key + 1] = '\0';
            i += (new_key);
            key_arr++;
        }
    }
    arr[key_arr] = NULL;
    return arr;
}

char **my_str_to_word_array (char const *str, char *del)
{
    char **arr = malloc(allocation(str));

    return fill_array(arr, str);
}
