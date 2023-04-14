/*
** EPITECH PROJECT, 2023
** my_rph
** File description:
** Sound controlling functions for the soundboard
*/

#include "app/sound/sound.h"
#include "my/include/my.h"
#include "types/list/list.h"

static int one_time_effect(sound_t *sound, int sound_effect)
{
    if (sound_effect == CLICK_MENU) {
        sfSound_play(sound->sound);
        return 1;
    }
    return 0;
}

void sound_control(list_t *sound_board, int sound_effect,
sfSoundStatus new_sound_status)
{
    node_t *sound_list = sound_board->first;
    int i = 0;

    while (i < sound_effect) {
        if (!sound_list)
            return;
        sound_list = sound_list->next;
        i++;
    }
    my_putstr(sound_list->data.sound->title);
    if (one_time_effect(sound_list->data.sound, sound_effect))
        return;
    sound_list->data.sound->status = new_sound_status;
}
