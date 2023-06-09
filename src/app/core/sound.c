/*
** EPITECH PROJECT, 2023
** Core of the sound system
** File description:
** sound
*/

#include "app/app.h"
#include "types/list/types.h"
#include "app/sound/sound_control.h"

void core_handle_sound(app_t *app)
{
    handle_sound_effects(app->sound_board->sound_fx);
    handle_sound_themes(app->sound_board->sound_themes,
    app->state, app->settings->music);
    handle_sound_volume(app->settings->volume, app->sound_board);
}
