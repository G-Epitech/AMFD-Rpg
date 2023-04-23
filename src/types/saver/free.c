/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdlib.h>
#include "app/saving/types.h"

void saver_free(saver_t *saver)
{
    if (!saver)
        return;
    free(saver);
}
