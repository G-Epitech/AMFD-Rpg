/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "app/loading/loading.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static void anim_append_data(anim_t *anim, cjson_t *anim_config)
{
    char *back = cjson_get_prop_string_unsafe(anim_config, "back");
    char *front = cjson_get_prop_string_unsafe(anim_config, "front");
    char *collision = cjson_get_prop_string_unsafe(anim_config, "collision");

    anim->world = cjson_get_prop_int_unsafe(anim_config, "world");
    anim->back = sfTexture_createFromFile(back, NULL);
    anim->front = sfTexture_createFromFile(front, NULL);
    anim->collision = sfImage_createFromFile(collision);
    anim->speed = cjson_get_prop_float_unsafe(anim_config, "speed");
    anim->off_set = cjson_get_prop_float_unsafe(anim_config, "offset");
    free(back);
    free(front);
    free(collision);
}

static void anim_append(list_t *animations, cjson_t *anim_config,
renderer_t *renderer)
{
    node_data_t data;
    node_t *node = NULL;
    anim_t *anim = malloc(sizeof(anim_t));

    if (!anim)
        return;
    data.anim = anim;
    node = node_new(data);
    if (!node) {
        free(anim);
        return;
    }
    anim_append_data(anim, anim_config);
    list_append(animations, node);
}

void animations_load(renderer_t *renderer, list_t *animations)
{
    cjson_t *anims_config = cjson_parse_file(RESSOURCES_ANIMATIONS_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *anim = NULL;

    if (!anims_config)
        return;
    if (!cjson_get_prop_array(anims_config, "animations", &array))
        return cjson_free(anims_config);
    anim = array->first;
    while (anim) {
        anim_append(animations, anim, renderer);
        anim = anim->next;
    }
    cjson_free(anims_config);
}