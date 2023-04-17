/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Loads all sound fx from json config file
*/

#include <stddef.h>
#include <stdlib.h>
#include "app/sound/types.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"

static void set_sound_properties(sound_t *sound)
{
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    sfSound_setVolume(sound->sound, sound->volume);
    sfSound_setLoop(sound->sound, (sfBool) sound->loop);
}

static void get_sound_properties(sound_t *sound, cjson_t *sound_config)
{
    char *sound_file = NULL;

    sound->title = cjson_get_prop_string_unsafe(sound_config, "title");
    if (!cjson_get_prop_string(sound_config, "buffer", &sound_file))
        return;
    sound->buffer = sfSoundBuffer_createFromFile(sound_file);
    sound->volume = cjson_get_prop_float_unsafe(sound_config, "volume");
    sound->loop = cjson_get_prop_bool_unsafe(sound_config, "loop");
    sound->lone = cjson_get_prop_bool_unsafe(sound_config, "lone");
    sound->status = cjson_get_prop_int_unsafe(sound_config, "status");
    free(sound_file);
}

static void sound_append(list_t *sounds, cjson_t *sound_config)
{
    node_t *node = NULL;
    sound_t *sound = malloc(sizeof(sound_t));

    if (!sound)
        return;
    get_sound_properties(sound, sound_config);
    set_sound_properties(sound);
    node = node_new((node_data_t) sound);
    if (node) {
        list_append(sounds, node);
    } else if (sound->buffer) {
        sfSoundBuffer_destroy(sound->buffer);
    }
}

list_t *sound_fx_load(void)
{
    list_t *sounds = list_new();
    cjson_t *sound_config = cjson_parse_file(SOUND_FX_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *sound = NULL;

    if (!sound_config)
        return NULL;
    if (!cjson_get_array(sound_config, &array)) {
        cjson_free(sound_config);
        return NULL;
    }
    sound = array->first;
    while (sound) {
        sound_append(sounds, sound);
        sound = sound->next;
    }
    cjson_free(sound_config);
    return sounds;
}
