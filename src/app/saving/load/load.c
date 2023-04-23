/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/app.h"
#include "my/include/my.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"
#include "types/renderer/renderer.h"
#include "app/animations/animations.h"
#include "types/dialog_box/dialog_box.h"

static void notify_success(app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;
    icons_r_t *icons = renderer ? renderer->ressources->icons : NULL;

    if (!renderer)
        return;
    events = animation_event_new(app);
    animations_notif_add(events, icons->happy,
    "Partie restauree",
    "Votre partie a ete restauree\navec succes !");
}

static void notify_error(app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;
    icons_r_t *icons = renderer ? renderer->ressources->icons : NULL;

    if (!renderer)
        return;
    events = animation_event_new(app);
    animations_notif_add(events, icons->hungry,
    "Echec de l'ouverture",
    "Le fichier fourni n'existe pas \nou est corrompu.");
}

static void end_of_restore(app_t *app, renderer_t *renderer,
char *file, bool valid)
{
    if (valid) {
        app->state = ST_INGAME;
        notify_success(app, renderer);
        free(app->game_file);
        app->game_file = my_strdup(file);
    } else {
        notify_error(app, renderer);
    }
}

static bool save_load_restore(app_t *app, cjson_t *file)
{
    cjson_t *player = cjson_get_prop(file, "player");
    cjson_t *quests = cjson_get_prop(file, "quests");

    if (!player || !quests)
        return false;
    app->world = (worlds_t) cjson_get_prop_int_unsafe(file, "world");
    save_load_restore_player(app, player);
    save_load_restore_quests(app, quests);
    return true;
}

void save_load(app_t *app, char *filename, renderer_t *renderer)
{
    cjson_t *file = cjson_parse_file(filename);

    if (!file) {
        end_of_restore(app, renderer, filename, false);
        return;
    }
    if (!save_load_file_check_validity(file)) {
        end_of_restore(app, renderer, filename, false);
        return;
    }
    if (!save_load_restore(app, file)) {
        end_of_restore(app, renderer, filename, false);
        return;
    }
    cjson_free(file);
    end_of_restore(app, renderer, filename, true);
}
