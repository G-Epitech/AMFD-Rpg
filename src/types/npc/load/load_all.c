/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include "types/npc/npc.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"

static void npcs_load_from_array(list_t *npcs, cjson_array_t *array)
{
    char **configs = cjson_array_to_string_array(array);
    cjson_t *config = NULL;
    size_t i = 0;

    while (configs[i]) {
        config = cjson_parse_file(configs[i]);
        if (config) {
            npc_load(npcs, config);
        }
        cjson_free(config);
        i += 1;
    }
}

list_t *npcs_load(void)
{
    list_t *npcs = list_new();
    cjson_t *file = cjson_parse_file(NPC_CONFIG);
    cjson_array_t *array = NULL;

    if (!file || !npcs) {
        cjson_free(file);
        list_free(npcs);
        return NULL;
    }
    if (!cjson_get_array(file, &array)) {
        cjson_free(file);
        list_free(npcs);
        return NULL;
    }
    npcs_load_from_array(npcs, array);
    return npcs;
}
