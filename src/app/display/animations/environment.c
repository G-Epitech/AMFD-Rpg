/*
** EPITECH PROJECT, 2023
** back.c
** File description:
** Display back of the map
*/

#include <SFML/Graphics.h>
#include "types/ressources/types.h"
#include "types/renderer/types.h"
#include "app/display/display.h"
#include "types/list/types.h"
#include "app/types.h"

static void display_anim_back(sfRenderWindow *window,
sfSprite *sprite, anim_t *anim)
{
    sfSprite_setTexture(sprite, anim->asset, sfTrue);
    sfSprite_setPosition(sprite, anim->position);
    sfSprite_setScale(sprite, (sfVector2f) {1, 1});
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