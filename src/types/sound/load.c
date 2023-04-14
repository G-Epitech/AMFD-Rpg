/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Loads sounds from config file
*/

#include <stddef.h>
#include <stdlib.h>
#include "app/sound/sound.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"

sound_board_t *load_sound_board(void)
{
    sound_board_t *sound_board = malloc(sizeof(sound_board_t));

    if (!sound_board)
        return NULL;
    sound_board->sound_fx = sound_fx_load();
    sound_board->sound_themes = sound_themes_load();
    return sound_board;
}
