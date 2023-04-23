/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include "app/app.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"

static void save_export_player_map_data(player_t *player, cjson_t *export)
{
    sfVector2f position = player->position;
    cjson_t *export_position = cjson_new(NULL);

    if (!export_position)
        return;
    cjson_set_prop(export_position, "x", CJSON(position.x), CJSON_NUMBER_T);
    cjson_set_prop(export_position, "y", CJSON(position.y), CJSON_NUMBER_T);
    cjson_set_prop(export, "position",
    CJSON(export_position), CJSON_OBJECT_T);
    cjson_set_prop(export, "orientation",
    CJSON_NUMBER(player->orientation), CJSON_NUMBER_T);
    cjson_set_prop(export, "state",
    CJSON_NUMBER(player->state), CJSON_NUMBER_T);
}

static void save_export_stats(player_t *player, cjson_t *export)
{
    cjson_set_prop(export, "credits",
    CJSON_NUMBER(player->credits), CJSON_NUMBER_T);
    cjson_set_prop(export, "xp_max",
    CJSON_NUMBER(player->xp_max), CJSON_NUMBER_T);
    cjson_set_prop(export, "level",
    CJSON_NUMBER(player->level), CJSON_NUMBER_T);
}

void save_player(player_t *player, cjson_t *export)
{
    cjson_set_prop(export, "name", CJSON(player->name), CJSON_STRING_T);
    cjson_set_prop(export, "skin_id",
    CJSON_NUMBER(player->skin_id), CJSON_NUMBER_T);
    save_export_player_map_data(player, export);
    save_export_stats(player, export);
    save_export_inventory(player->inventory, export);
    save_export_competences(player->competences, export);
}
