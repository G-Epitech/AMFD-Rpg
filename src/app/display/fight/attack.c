/*
** EPITECH PROJECT, 2023
** attack.c
** File description:
** Fight choice
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/display/types.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/ressources/types.h"
#include "my/include/my.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"

static sfText *display_require_level(renderer_t *renderer, attack_t *attack)
{
    sfText *text = renderer->objects->text;

    renderer_objects_reset_text(renderer->objects);
    sfText_setPosition(text, (sfVector2f) {
        attack->position.x + FIGHT_ATTACK_RATIO.x,
        attack->position.y + FIGHT_ATTACK_RATIO.y,
    });
    sfText_setColor(text, TEXT_LOCK_COLOR);
    sfText_setCharacterSize(text, 17);
    sfText_setString(text, nbr_to_str(attack->level));
    return text;
}

static void display_button(player_t *player, renderer_t *renderer,
attack_t *attack)
{
    sfText *text = NULL;
    sfSprite *sprite = renderer->objects->sprite;
    icons_r_t *icons = renderer->ressources->icons;

    (void) player;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setPosition(sprite, attack->position);
    if (player->level >= attack->level) {
        sfSprite_setTexture(sprite, attack->texture, sfTrue);
    } else {
        sfSprite_setTexture(sprite, icons->attack_lock, sfTrue);
        text = display_require_level(renderer, attack);
    }
    if (attack->shake)
        sfSprite_setColor(sprite, sfRed);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    if (text)
        sfRenderWindow_drawText(renderer->window, text, NULL);
}

void display_fight_attack(renderer_t *renderer, app_t *app)
{
    fight_t *fight = app->interaction->data.fight;
    node_t *node = NULL;

    (void) renderer;
    if (fight->state != FT_PLAYER_ATTACK)
        return;
    node = renderer->ressources->components->fight->first;
    while (node) {
        display_button(app->player, renderer, node->data.attack);
        node = node->next;
    }
}
