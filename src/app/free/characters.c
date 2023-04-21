/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** Frees players and npcs
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/list/list.h"
#include "types/npc/types.h"
#include "types/players/types.h"
#include "my/include/my.h"

void app_free_players(app_t *app)
{
    list_free(app->player->inventory);
}
