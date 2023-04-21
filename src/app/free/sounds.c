/*
** EPITECH PROJECT, 2023
** animations.c
** File description:
** Free animations
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/list/list.h"

static void free_sound_fx(list_t *sound_fx)
{
    node_t *sound_list = sound_fx->first;
    sound_t *sound_effect = NULL;

    while (sound_list) {
        sound_effect = sound_list->data.sound;
        sfSound_stop(sound_effect->sound);
        sfSound_destroy(sound_effect->sound);
        sfSoundBuffer_destroy(sound_effect->buffer);
        free(sound_effect->title);
        sound_list = sound_list->next;
    }
}

static void free_sound_theme(list_t *sound_themes)
{
    node_t *theme_list = sound_themes->first;
    sound_theme_t *theme = NULL;

    while (theme_list) {
        theme = theme_list->data.theme;
        sfMusic_stop(theme->music);
        sfMusic_destroy(theme->music);
        free(theme->title);
        free(theme->associated_app_state);
        theme_list = theme_list->next;
    }
}

void app_free_sounds(app_t *app)
{
    sound_board_t *soundboard = app->sound_board;

    free_sound_fx(soundboard->sound_fx);
    list_free(soundboard->sound_fx);
    free_sound_theme(soundboard->sound_themes);
    list_free(soundboard->sound_themes);
}
