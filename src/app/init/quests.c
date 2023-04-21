/*
** EPITECH PROJECT, 2023
** quests.c
** File description:
** Quests initialisations
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/list/list.h"
#include "app/quests/types.h"
#include "cjson/include/cjson.h"

static list_t *load_chapter(char *config)
{
    list_t *quests = list_new();
    cjson_t *cjson = cjson_parse_file(config);
    cjson_array_t *array = NULL;
    quest_t *quest = NULL;

    if (!quests || !cjson)
        return NULL;
    cjson_get_array(cjson, &array);
    cjson = array->first;
    while (cjson) {
        quest = malloc(sizeof(quest_t));
        cjson_get_prop_string(cjson, "title", &quest->title);
        cjson_get_prop_string(cjson, "type", &quest->type);
        cjson_get_prop_int(cjson, "id", &quest->id);
        list_append(quests, node_new((node_data_t) quest));
        cjson = cjson->next;
    }
    return quests;
}

static list_t *load_quests(void)
{
    list_t *quests = list_new();
    cjson_t *cjson = cjson_parse_file(QUESTS_CONFIG);
    cjson_array_t *array = NULL;
    quests_t *chapter = NULL;

    if (!quests || !cjson)
        return NULL;
    cjson_get_array(cjson, &array);
    cjson = array->first;
    while (cjson) {
        chapter = malloc(sizeof(quests_t));
        if (!chapter)
            return NULL;
        cjson_get_prop_string(cjson, "title", &chapter->title);
        chapter->quests = load_chapter(cjson_get_prop_string_unsafe(cjson,
        "config"));
        list_append(quests, node_new((node_data_t) chapter));
        cjson = cjson->next;
    }
    return quests;
}

bool app_init_quests(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->quests = malloc(sizeof(app_quests_t));
    if (!app->quests)
        return false;
    app->quests->index_quest = 0;
    app->quests->index_quests = 0;
    app->quests->quests = load_quests();
    if (!app->quests->quests) {
        free(app->quests);
        return false;
    }
    return true;
}
