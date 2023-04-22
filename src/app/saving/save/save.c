/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <stdlib.h>
#include "app/app.h"
#include "my/include/my.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"
#include "types/renderer/renderer.h"
#include "app/animations/animations.h"
#include "types/dialog_box/dialog_box.h"

static void end_of_save(app_t *app, char *filename,
bool notify, saver_t *saver)
{
    list_t *events = NULL;
    renderer_t *renderer = saver ? saver->renderer : NULL;
    icons_r_t *icons = renderer ? renderer->ressources->icons : NULL;

    free(app->game_file);
    app->game_file = my_strdup(filename);
    if (!notify | !renderer)
        return;
    events = animation_event_new(app);
    animations_notif_add(events, icons->happy,
    "Partie enregistree",
    "Votre partie a ete enregistree\navec succes !");
}

void save_save(app_t *app, char *filename, bool notify, saver_t *saver)
{
    cjson_t *game = cjson_new(NULL);
    cjson_t *player = cjson_new(NULL);
    cjson_t *quests = cjson_new(NULL);

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
    end_of_save(app, filename, notify, saver);
}
