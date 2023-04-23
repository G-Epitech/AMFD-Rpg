/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdlib.h>
#include "app/saving/types.h"

saver_t *saver_new(void)
{
    saver_t *saver = malloc(sizeof(saver_t));

    if (!saver)
        return NULL;
    saver->window = NULL;
    saver->close_window = false;
    saver->renderer = NULL;
    return saver;
}
