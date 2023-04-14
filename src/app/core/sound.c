/*
** EPITECH PROJECT, 2023
** Core of the sound system
** File description:
** sound
*/

#include "app/app.h"
#include "types/list/types.h"
#include "my/include/my.h"

void update_sound(sound_t *sound)
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

void core_handle_sound(list_t *sound_board)
{
    node_t *node = sound_board->first;

    while (node) {
        if (sfSound_getStatus(node->data.sound->sound) !=
        node->data.sound->status)
            update_sound(node->data.sound);
        node = node->next;
    }
}
