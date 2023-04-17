/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free
*/

#include <stdlib.h>
#include "app/dependencies.h"

void app_free(app_t *app)
{
    size_t member = 0;

    if (!app)
        return;
    while (app_free_members[member]) {
        app_free_members[member](app);
        member += 1;
    }
    free(app);
}
