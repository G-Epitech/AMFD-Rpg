/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** Events of buttons components
*/


#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/events/types.h"
#include "app/app.h"
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "app/animations/animations.h"
#include "my/include/my.h"
#include "app/utils/utils.h"

static bool on_attack(attack_t *attack, app_t *app,
sfEvent event, fight_t *fight)
{
    list_t *events = NULL;
    sfVector2f cursor = (sfVector2f) {event.mouseButton.x,
    event.mouseButton.y};

    if (attack->level > app->player->level)
        return false;
    if (cursor.x < attack->position.x || cursor.y < attack->position.y)
        return false;
    if (cursor.x > attack->position.x + ATTACK_BUTTON_SCALE.x)
        return false;
    if (cursor.y > attack->position.y + ATTACK_BUTTON_SCALE.y)
        return false;
    if (attack->mana > fight->mana) {
        events = animation_event_new(app);
        animations_shake_attack_add(events, attack);
        return false;
    }
    return true;
}

static void animation_attack(app_t *app, attack_t *attack)
{
    list_t *events = animation_event_new(app);
    char *attack_text = attack->title;

    attack_text = my_strcat(attack_text, "\n-");
    attack_text = my_strcat(attack_text, nbr_to_str(attack->damage));
    attack_text = my_strcat(attack_text, " PV");
    animations_floating_text_add(events, ATTACK_ANIM_COLOR,
    ATTACK_ANIM_POSITION, my_strdup(attack_text));
    free(attack_text);
}

static void attack_win(app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;
    sfTexture *icon = renderer->ressources->icons->happy;
    int xp = 0;

    if (app->interaction->data.fight->enemy_life <= 0) {
        xp = app->interaction->data.fight->npc->enemy->level;
        app->interaction->active = false;
        app->interaction->interaction = false;
        app->state = ST_INGAME;
        free(app->interaction->data.fight);
        events = animation_event_new(app);
        animations_screen_zoom_add(events, renderer->map_view, 70, 2);
        animations_notif_add(events, icon, ATTACKS_WIN_TITLE,
        ATTACKS_WIN_DESCRIPTION);
        utils_give_xp(renderer, app, xp);
    }
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
            animation_attack(app, attack);
            attack_win(app, renderer);
            break;
        }
        node = node->next;
    }
}
