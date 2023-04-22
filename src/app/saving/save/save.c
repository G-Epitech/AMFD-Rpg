/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include "app/app.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"

void save_save(app_t *app, char *filename, bool notify)
{
    cjson_t *game = cjson_new(NULL);
    cjson_t *player = cjson_new(NULL);
    cjson_t *quests = cjson_new(NULL);

    (void) notify;
    if (!game || !player || !quests) {
        cjson_free(game);
        cjson_free(player);
        cjson_free(game);
        return;
    }
    cjson_set_prop(game, "player", CJSON(player), CJSON_OBJECT_T);
    cjson_set_prop(game, "quests", CJSON(quests), CJSON_OBJECT_T);
    cjson_set_prop(game, "world", CJSON_NUMBER(app->world), CJSON_NUMBER_T);
    save_player(app->player, player);
    save_quests(app->quests, quests);
    cjson_export_to_file(game, filename);
    cjson_free(game);
}
