/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "app/loading/loading.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

void inventory_load(renderer_t *renderer, inventory_r_t *inventory)
{
    load_screen_add_bar(renderer, 5, "Chargement des ressources...",
    "Chargement de l'inventaire");
    if (!inventory)
        return;
}
