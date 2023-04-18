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

static void attribute_new_skin(list_t *animations, skin_t *skin,
player_t *player)
{
    node_t *node = animations->first;
    animation_t *anim = node->data.animation;

    my_put_nbr(anim->curr_frame);
    my_putchar('d');
    if (anim->curr_frame == anim->frames_len + 1) {
        my_putchar('e');
        anim->rect.left -= (anim->frames_len * anim->rect.width);
        printf("Rect left %d\n", anim->frames_len * anim->rect.width);
        anim->curr_frame = 1;
    }
    while (node) {
        anim = node->data.animation;
        if (anim->skin_id == skin->id && anim->state == player->state) {
            sfTexture_destroy(skin->texture);
            printf("Rect top:%d left:%d width:%d height:%d\n",
        anim->rect.top, anim->rect.left, anim->rect.width, anim->rect.height);
            skin->texture = sfTexture_createFromFile(anim->file, &anim->rect);
            anim->curr_frame++;
            anim->rect.left += anim->rect.width;
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
    if (seconds > 0.17) {
        change_player_skin(app->animations, renderer->ressources->skins,
        app->player);
        sfClock_restart(app->clock);
    }
}
