/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** Events of buttons components
*/


#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/events/types.h"
#include "app/app.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

static bool on_attack(attack_t *attack, app_t *app,
sfEvent event, fight_t *fight)
{
    sfVector2f cursor = (sfVector2f) {event.mouseButton.x,
    event.mouseButton.y};

    if (attack->level > app->player->level)
        return false;
    if (attack->mana > fight->mana) {
        // Animation impossible
        return false;
    }
    if (cursor.x < attack->position.x || cursor.y < attack->position.y)
        return false;
    if (cursor.x > attack->position.x + ATTACK_BUTTON_SCALE.x)
        return false;
    if (cursor.y > attack->position.y + ATTACK_BUTTON_SCALE.y)
        return false;
    return true;
}

void event_components_attacks(renderer_t *renderer, app_t *app, sfEvent event)
{
    list_t *attacks = renderer->ressources->components->fight;
    node_t *node = attacks->first;
    attack_t *attack = NULL;

    if (!app->interaction || app->interaction->type != IT_FIGHT)
        return;
    if (app->interaction->data.fight->state != FT_PLAYER_ATTACK)
        return;
    while (node) {
        attack = node->data.attack;
        if (on_attack(attack, app, event, app->interaction->data.fight)) {
            app->interaction->data.fight->mana -= attack->mana;
            app->interaction->data.fight->enemy_life -= attack->damage;
            app->interaction->data.fight->state = FT_NPC_ATTACK;
            break;
        }
        node = node->next;
    }
}
