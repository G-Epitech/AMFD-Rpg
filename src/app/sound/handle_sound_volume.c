/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions working with core to handle app volume
*/

#include "app/app.h"
#include "types/list/types.h"

static float get_volume_percentage(float app_volume, float audio_volume)
{
    return (audio_volume * (app_volume / 100));
}

static void update_sound_fx_volume(float app_volume, list_t *sound_fx_list)
{
    node_t *sound_fx = sound_fx_list->first;
    sound_t *curr_sound = NULL;
    float new_volume = 0.0;

    while (sound_fx) {
        curr_sound = sound_fx->data.sound;
        new_volume = get_volume_percentage(app_volume,
        curr_sound->volume);
        sfSound_setVolume(curr_sound->sound, new_volume);
        sound_fx = sound_fx->next;
    }
}

static void update_sound_theme_volume(float app_volume,
list_t *sound_theme_list)
{
    node_t *sound_theme = sound_theme_list->first;
    sound_theme_t *theme = NULL;
    float new_volume = 0.0;

    while (sound_theme) {
        theme = sound_theme->data.theme;
        new_volume = get_volume_percentage(app_volume,
        theme->volume);
        sfMusic_setVolume(theme->music, new_volume);
        sound_theme = sound_theme->next;
    }
}

void handle_sound_volume(float app_volume, sound_board_t *sound_board)
{
    static float old_app_volume = 60.0;

    if (old_app_volume == app_volume)
        return;
    old_app_volume = app_volume;
    update_sound_fx_volume(app_volume, sound_board->sound_fx);
    update_sound_theme_volume(app_volume, sound_board->sound_themes);
}
