/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onexit
*/

#include <stdbool.h>
#include "app/types.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"

static void save_load_file_check_validity_quests(cjson_t *quests,
bool *valid)
{
    int getter = 0;

    if (!cjson_get_prop_int(quests, "index_quest", &getter))
        *valid = false;
    if (!cjson_get_prop_int(quests, "index_quests", &getter))
        *valid = false;
}

bool save_load_file_check_validity(cjson_t *file)
{
    bool valid = true;
    cjson_t *player = cjson_get_prop(file, "player");
    cjson_t *quests = cjson_get_prop(file, "quests");
    int world = 0;

    if (!cjson_get_prop_int(file, "world", &world))
        valid = false;
    if (!player || !quests)
        valid = false;
    if (valid) {
        save_load_file_check_validity_quests(quests, &valid);
        save_load_file_check_validity_player(player, &valid);
    }
    return valid;
}
