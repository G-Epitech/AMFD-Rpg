/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include "app/app.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"

void save_quests(app_quests_t *quests, cjson_t *export)
{
    cjson_set_prop(export, "index_quests",
    CJSON_NUMBER(quests->index_quests), CJSON_NUMBER_T);
    cjson_set_prop(export, "index_quest",
    CJSON_NUMBER(quests->index_quest), CJSON_NUMBER_T);
}
