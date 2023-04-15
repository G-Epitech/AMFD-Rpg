/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions working with core to handle app volume
*/

#include "app/app.h"
#include "types/list/types.h"

static void update_sound_fx_volume(float volume_offset, list_t *sound_fx_list)
{
    node_t *sound_fx = sound_fx_list->first;
    sound_t *curr_sound = NULL;

    while (sound_fx) {
        curr_sound = sound_fx->data.sound;
        curr_sound->volume += volume_offset;
        sfSound_setVolume(curr_sound->sound, curr_sound->volume);
        sound_fx = sound_fx->next;
    }
}

static void update_sound_theme_volume(float volume_offset,
list_t *sound_theme_list)
{
    node_t *sound_theme = sound_theme_list->first;
    sound_theme_t *theme = NULL;

    while (sound_theme) {
        theme = sound_theme->data.theme;
        theme->volume += volume_offset;
        sfMusic_setVolume(theme->music, theme->volume);
        sound_theme = sound_theme->next;
    }
}

void handle_sound_volume(float app_volume, sound_board_t *sound_board)
{
    static float old_app_volume = 15.0;
    float volume_offset = 0.0;

    if (old_app_volume == app_volume)
        return;
    volume_offset = (app_volume - old_app_volume) / 2;
    update_sound_fx_volume(volume_offset, sound_board->sound_fx);
    update_sound_theme_volume(volume_offset, sound_board->sound_themes);
}
