/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** npcs
*/


#include <stdlib.h>
#include "app/types.h"
#include "types/npc/npc.h"

bool app_init_npcs(app_t *app)
{
    app->npcs = npcs_load();
    return app->npcs ? true : false;
}
