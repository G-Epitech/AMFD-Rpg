/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions working with core for animations
*/

#include <stdio.h>
#include "SFML/System/Export.h"
#include "app/app.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "types/ressources/ressources.h"

static void restart_frames(animation_t *anim)
{
    if (anim->curr_frame == anim->frames_len + 1) {
        anim->curr_frame = 1;
    }
}

animation_t *player_anim_get(int skin_id, enitity_state_t player_state,
list_t *animations)
{
    node_t *node = animations->first;
    animation_t *anim = node->data.animation;

    while (node) {
        anim = node->data.animation;
        if (anim->skin_id == skin_id && anim->state == player_state)
            return anim;
        restart_frames(anim);
        node = node->next;
    }
    return NULL;
}

static void attribute_new_rect(list_t *animations, player_t *player)
{
    animation_t *anim = player_anim_get(player->skin_id,
    player->state, animations);
    int orientation_offset = 0;

    if (!anim)
        return;
    orientation_offset = player->orientation * anim->frames_len +
    anim->curr_frame - 1;
    anim->rect.left = orientation_offset * anim->rect.width;
    player->rect = anim->rect;
    anim->curr_frame++;
    restart_frames(anim);
}

void animate_player(app_t *app)
{
    sfTime time = (sfTime) {0.0};
    float seconds = 0.0;

    time = sfClock_getElapsedTime(app->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.12) {
        attribute_new_rect(app->player_anim, app->player);
        sfClock_restart(app->clock);
    }
}
