/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** check_player
*/

#include <stdlib.h>
#include <stdbool.h>
#include "app/types.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"
#include "types/dialog_box/dialog_box.h"

static void check_inventory(cjson_t *player, bool *valid)
{
    cjson_array_t *array = cjson_get_prop_array_unsafe(player, "inventory");
    cjson_t *item = array ? array->first : NULL;
    int id = 0;
    bool active = false;

    if (!array) {
        *valid = false;
        return;
    }
    while (item && (*valid)) {
        if (!cjson_get_prop_int(item, "id", &id))
            *valid = false;
        if (!cjson_get_prop_bool(item, "active", &active))
            *valid = false;
        item = item->next;
    }
}

static void check_competences(cjson_t *player, bool *valid)
{
    cjson_array_t *array = cjson_get_prop_array_unsafe(player, "competences");
    cjson_t *item = array ? array->first : NULL;
    int id = 0;
    bool unlock = false;

    if (!array) {
        *valid = false;
        return;
    }
    while (item && (*valid)) {
        if (!cjson_get_prop_int(item, "id", &id))
            *valid = false;
        if (!cjson_get_prop_bool(item, "unlock", &unlock))
            *valid = false;
        item = item->next;
    }
}

static void check_singles(cjson_t *player, bool *valid)
{
    int getter = 0;
    char *props[6] = {"xp_max", "level", "credits",
    "state", "orientation", "skin_id"};

    for (size_t i = 0; i < 6; i++) {
        if (!cjson_get_prop_int(player, props[i], &getter))
            *valid = false;
    }
}

static void check_position(cjson_t *player, bool *valid)
{
    cjson_t *position = cjson_get_prop(player, "position");
    float getter = 0;

    if (!position) {
        *valid = false;
        return;
    }
    if (!cjson_get_prop_float(position, "x", &getter))
        *valid = false;
    if (!cjson_get_prop_float(position, "y", &getter))
        *valid = false;
}

void save_load_file_check_validity_player(cjson_t *player,
bool *valid)
{
    char *name = NULL;

    if (!cjson_get_prop_string(player, "name", &name))
        *valid = false;
    check_competences(player, valid);
    check_inventory(player, valid);
    check_singles(player, valid);
    check_position(player, valid);
    if (!(*valid))
        return free(name);
}
