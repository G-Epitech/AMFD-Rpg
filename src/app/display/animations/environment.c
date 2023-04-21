/*
** EPITECH PROJECT, 2023
** back.c
** File description:
** Display back of the map
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "types/ressources/types.h"
#include "types/renderer/types.h"
#include "app/display/display.h"
#include "types/list/types.h"
#include "app/types.h"

static void display_anim_back(sfRenderWindow *window,
sfSprite *sprite, anim_t *anim)
{
    sfSprite_setTexture(sprite, anim->asset, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {1, 1});
    sfSprite_setTextureRect(sprite, anim->back_rect);
    sfSprite_setPosition(sprite, anim->position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_animations_environments_back(list_t *animations,
sfRenderWindow *window, sfSprite *sprite, worlds_t world)
{
    node_t *node = animations->first;

    while (node) {
        if (node->data.anim->world == world)
            display_anim_back(window, sprite, node->data.anim);
        node = node->next;
    }
}

static void display_anim_front(sfRenderWindow *window,
sfSprite *sprite, anim_t *anim, ressources_t *ressources)
{
    sfVector2f pos = {anim->position.x,
    anim->position.y - anim->front_rect.height};
    float delta_time =
    sfTime_asSeconds(sfClock_getElapsedTime(ressources->clock));

    if (delta_time - anim->time_elapsed >= anim->frame_duration) {
        if (anim->front_rect.left == (anim->nb_frame - 1) * anim->off_set) {
            anim->front_rect.left = 0;
        } else {
            anim->front_rect.left += anim->off_set;
        }
        anim->time_elapsed = delta_time;
    }
    sfSprite_setTexture(sprite, anim->asset, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {1, 1});
    sfSprite_setTextureRect(sprite, anim->front_rect);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_animations_environments_front(app_t *app,
sfRenderWindow *window, sfSprite *sprite, renderer_t *renderer)
{
    node_t *node = renderer->ressources->animations->first;

    while (node) {
        if (node->data.anim->world == app->world)
            display_anim_front(window, sprite, node->data.anim,
            renderer->ressources);
        node = node->next;
    }
}
