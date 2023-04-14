/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Loads all sound themes
*/

#include <stddef.h>
#include <stdlib.h>
#include "app/sound/types.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"

static void set_theme_properties(sound_theme_t *theme)
{
    sfMusic_setLoop(theme->music, theme->loop);
    sfMusic_setVolume(theme->music, theme->volume);
}

static void theme_append(list_t *themes, cjson_t *theme_config)
{
    node_t *node = NULL;
    sound_theme_t *theme = malloc(sizeof(sound_theme_t));
    char *theme_file = NULL;

    theme->title = cjson_get_prop_string_unsafe(theme_config, "title");
    if (!cjson_get_prop_string(theme_config, "buffer", &theme_file))
        return;
    theme->music = sfMusic_createFromFile(theme_file);
    theme->volume = cjson_get_prop_float_unsafe(theme_config, "volume");
    theme->loop = cjson_get_prop_bool_unsafe(theme_config, "loop");
    theme->associated_app_state = cjson_get_prop_int_unsafe(theme_config,
    "app_state");
    theme->status = cjson_get_prop_int_unsafe(theme_config, "status");
    set_theme_properties(theme);
    node = node_new((node_data_t) theme);
    if (node) {
        list_append(themes, node);
    }
    free(theme_file);
}

list_t *sound_themes_load(void)
{
    list_t *themes = list_new();
    cjson_t *theme_config = cjson_parse_file(SOUND_THEME_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *theme = NULL;

    if (!theme_config)
        return NULL;
    if (!cjson_get_array(theme_config, &array)) {
        cjson_free(theme_config);
        return NULL;
    }
    theme = array->first;
    while (theme) {
        theme_append(themes, theme);
        theme = theme->next;
    }
    cjson_free(theme_config);
    return themes;
}
