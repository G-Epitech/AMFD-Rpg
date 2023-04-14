/*
** EPITECH PROJECT, 2023
** Core of the sound system
** File description:
** sound
*/

#include "app/app.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void update_sound(sound_t *sound)
{
    if (sound->status == sfPlaying) {
        sfSound_play(sound->sound);
        return;
    }
    if (sound->status == sfStopped) {
        sfSound_stop(sound->sound);
        return;
    }
    if (sound->status == sfPaused) {
        sfSound_pause(sound->sound);
    }
}

static int is_one_time_sound(sound_t *sound)
{
    if (my_strcmp(sound->title, "click_menu") == 0 ||
    my_strcmp(sound->title, "menu_theme") == 0)
        return 0;
    return 1;
}

void core_handle_sound(list_t *sound_board)
{
    node_t *node = sound_board->first;
    sound_t *current_sound = NULL;

    while (node) {
        current_sound = node->data.sound;
        if (sfSound_getStatus(current_sound->sound) !=
        current_sound->status && is_one_time_sound(current_sound))
            update_sound(current_sound);
        node = node->next;
    }
}
