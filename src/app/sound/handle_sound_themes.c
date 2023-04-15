/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions working with core to handle themes
*/

#include "app/app.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void check_start_song(sound_theme_t *theme)
{
    if (theme->status == sfPlaying)
        return;
    sfMusic_play(theme->music);
    theme->status = sfPlaying;
}

static void sound_theme_association(sound_theme_t *theme,
app_states_t app_state)
{
    bool state_is_associated = false;

    for (size_t i = 0; i < theme->app_state_size; i++) {
        if (theme->associated_app_state[i] == app_state) {
            state_is_associated = true;
            check_start_song(theme);
        }
    }
    if (state_is_associated == false) {
        sfMusic_pause(theme->music);
        theme->status = sfPaused;
    }
}

void handle_sound_themes(list_t *theme_list, app_states_t app_state)
{
    static app_states_t old_state = 0;
    node_t *theme = theme_list->first;

    if (app_state == old_state)
        return;
    old_state = app_state;
    while (theme) {
        sound_theme_association(theme->data.theme, app_state);
        theme = theme->next;
    }
}
