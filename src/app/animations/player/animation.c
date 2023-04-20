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

static void restart_frames(animation_t *anim)
{
    if (anim->curr_frame == anim->frames_len + 1) {
        anim->curr_frame = 1;
    }
}

static void attribute_new_skin(list_t *animations, skin_t *skin,
player_t *player)
{
    node_t *node = animations->first;
    animation_t *anim = node->data.animation;
    int orientation_offset = 0;

    while (node) {
        anim = node->data.animation;
        if (anim->skin_id == skin->id && anim->state == player->state) {
            orientation_offset = player->orientation * anim->frames_len +
            anim->curr_frame - 1;
            sfTexture_destroy(skin->texture);
            anim->rect.left = orientation_offset * anim->rect.width;
            skin->texture = sfTexture_createFromFile(anim->file, &anim->rect);
            anim->curr_frame++;
            restart_frames(anim);
        }
        node = node->next;
    }
}

static void change_player_skin(list_t *anim, list_t *skins, player_t *player)
{
    node_t *node = skins->first;
    skin_t skin;

    while (node) {
        skin = node->data.skin;
        if (skin.id == player->skin_id) {
            attribute_new_skin(anim, &node->data.skin, player);
        }
        node = node->next;
    }
}

void animate_player(app_t *app, renderer_t *renderer)
{
    sfTime time = (sfTime) {0.0};
    float seconds = 0.0;

    time = sfClock_getElapsedTime(app->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.12) {
        change_player_skin(app->player_anim, renderer->ressources->skins,
        app->player);
        sfClock_restart(app->clock);
    }
}
