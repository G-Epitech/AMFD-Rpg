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
    if (sfMusic_getStatus(theme->music) == sfPlaying)
        return;
    sfMusic_setLoop(theme->music, sfTrue);
    sfMusic_play(theme->music);
}

static void sound_theme_association(sound_theme_t *theme,
app_states_t app_state, bool music_enabled)
{
    bool state_is_associated = false;

    for (size_t i = 0; i < theme->app_state_size; i++) {
        if (theme->associated_app_state[i] == app_state && music_enabled) {
            state_is_associated = true;
            check_start_song(theme);
        }
    }
    if (state_is_associated == false || !music_enabled)
        sfMusic_pause(theme->music);
}

void handle_sound_themes(list_t *theme_list, app_states_t app_state,
bool music_enabled)
{
    node_t *theme = theme_list->first;

    while (theme) {
        sound_theme_association(theme->data.theme, app_state, music_enabled);
        theme = theme->next;
    }
}
