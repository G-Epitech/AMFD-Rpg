/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions working with core to handle sound effects
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
    if (sound->status == sfPaused)
        sfSound_pause(sound->sound);
}

void handle_sound_effects(list_t *sound_fx)
{
    node_t *node = sound_fx->first;
    sound_t *current_sound = NULL;

    while (node) {
        current_sound = node->data.sound;
        if (sfSound_getStatus(current_sound->sound) != current_sound->status
        && current_sound->lone == false)
            update_sound(current_sound);
        node = node->next;
    }
}
