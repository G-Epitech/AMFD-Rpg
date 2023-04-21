/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player
*/

#include <stdio.h>
#include "app/display/display.h"
#include "app/animate_player/animation.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void display_specific_player(renderer_t *renderer, player_t *player)
{
    sfSprite *sprite = renderer->objects->sprite;
    list_t *skins = renderer->ressources->skins;
    const skin_t *skin = ressources_get_skin(skins, player->skin_id);

    if (!skin)
        return;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, skin->texture, sfTrue);
    sfSprite_setTextureRect(sprite, player->rect);
    sfSprite_setPosition(sprite, player->position);
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}

void display_player(renderer_t *renderer, app_t *app)
{
    list_t *players = app->players;
    node_t *node = players->first;
    player_t *player = NULL;

    while (node) {
        player = node->data.player;
        display_specific_player(renderer, player);
        node = node->next;
    }
}
