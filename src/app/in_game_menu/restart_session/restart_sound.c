/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Restarts all sounds
*/

#include "app/types.h"
#include "types/list/list.h"

void restart_sound(sound_board_t *soundboard)
{
    node_t *node = soundboard->sound_themes->first;
    sound_theme_t *theme = NULL;

    while (node) {
        theme = node->data.theme;
        sfMusic_stop(theme->music);
        theme->status = sfStopped;
        node = node->next;
    }
}
