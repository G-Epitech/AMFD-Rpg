/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/app.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"

void save_load_restore_quests(app_t *app, cjson_t *quests_file)
{
    int index_quest = 0;
    int index_quests = 0;

    cjson_get_prop_int(quests_file, "index_quest", &index_quest);
    cjson_get_prop_int(quests_file, "index_quests", &index_quests);
    app->quests->index_quest = index_quest;
    app->quests->index_quests = index_quests;
}
