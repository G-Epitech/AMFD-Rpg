/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Loads animations from config file
*/

#include <stddef.h>
#include <stdlib.h>
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"
#include "app/animate_player/type.h"
#include "app/app.h"

static void get_animation_properties(animation_t *anim, cjson_t *anim_config)
{
    anim->title = cjson_get_prop_string_unsafe(anim_config, "title");
    anim->skin_id = cjson_get_prop_int_unsafe(anim_config, "skin_id");
    anim->file = cjson_get_prop_string_unsafe(anim_config, "asset");
    anim->state = cjson_get_prop_int_unsafe(anim_config, "state");
    anim->frames_len = cjson_get_prop_int_unsafe(anim_config, "frame_len");
    anim->curr_frame = 1;
    anim->rect.top = cjson_get_prop_int_unsafe(anim_config, "top");
    anim->rect.left = cjson_get_prop_int_unsafe(anim_config, "left");
    anim->rect.width = cjson_get_prop_int_unsafe(anim_config, "width");
    anim->rect.height = cjson_get_prop_int_unsafe(anim_config, "height");
}

static void animation_append(cjson_t *anim_config, list_t *animations)
{
    node_t *node = NULL;
    animation_t *anim = malloc(sizeof(animation_t));

    if (!anim)
        return;
    get_animation_properties(anim, anim_config);
    node = node_new((node_data_t) anim);
    if (node) {
        list_append(animations, node);
    }
    return;
}

static list_t *load_animations(void)
{
    list_t *animations = list_new();
    cjson_t *anim_config = cjson_parse_file(ANIMATION_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *animation = NULL;

    if (!anim_config)
        return NULL;
    if (!cjson_get_array(anim_config, &array)) {
        cjson_free(anim_config);
        return NULL;
    }
    animation = array->first;
    while (animation) {
        animation_append(animation, animations);
        animation = animation->next;
    }
    cjson_free(anim_config);
    return animations;
}

bool app_init_player_animations(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->player_anim = load_animations();
    return app->player_anim ? true : false;
}
