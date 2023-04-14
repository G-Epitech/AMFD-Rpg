/*
** EPITECH PROJECT, 2023
** my_rph
** File description:
** Sound controlling functions for the soundboard
*/

#include "app/sound/sound.h"
#include "my/include/my.h"
#include "types/list/list.h"

void sound_control(list_t *sound_board, int sound_index,
sfSoundStatus new_sound_status)
{
    node_t *sound_list = sound_board->first;
    int i = 0;

    while (i < sound_index) {
        if (!sound_list)
            return;
        sound_list = sound_list->next;
        i++;
    }
    my_putstr(sound_list->data.sound->title);
    sound_list->data.sound->status = new_sound_status;
}
