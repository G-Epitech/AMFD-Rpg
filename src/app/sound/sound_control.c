/*
** EPITECH PROJECT, 2023
** my_rph
** File description:
** Sound controlling functions for the soundboard
*/

#include "app/sound/sound.h"
#include "my/include/my.h"
#include "types/list/list.h"

void sound_control(list_t *sound_board, int sound_effect,
sfSoundStatus new_sound_status)
{
    node_t *sound_list = sound_board->first;
    sound_t *curr_sound = NULL;
    int i = 0;

    while (i < sound_effect) {
        if (!sound_list)
            return;
        sound_list = sound_list->next;
        i++;
    }
    curr_sound = sound_list->data.sound;
    if (curr_sound->lone)
        sfSound_play(curr_sound->sound);
    curr_sound->status = new_sound_status;
}
