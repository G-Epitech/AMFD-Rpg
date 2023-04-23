/*
** EPITECH PROJECT, 2023
** enemy.c
** File description:
** Enemy attack
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "app/core/types.h"
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/types.h"
#include "types/players/players.h"
#include "app/core/core.h"
#include "app/core/types.h"
#include "types/list/types.h"
#include "app/app.h"
#include "app/network/network.h"
#include "app/animations/animations.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"
#include "app/quests/types.h"

static void applay_attack(cjson_t *node, app_t *app)
{
    list_t *events = animation_event_actual(app);
    char *attack = cjson_get_prop_string_unsafe(node, "title");
    int damage = cjson_get_prop_int_unsafe(node, "damage");

    attack = my_strcat(attack, "\n-");
    attack = my_strcat(attack, nbr_to_str(damage));
    attack = my_strcat(attack, " PV");
    app->player->life -= damage;
    animations_floating_text_add(events, sfRed, ATTACKS_POSITION,
    my_strdup(attack));
    free(attack);
}

static void teleport_player(app_t *app, list_t *events)
{
    if (app->quests->index_quests == 0 &&
    app->quests->index_quest == 2) {
        animations_screen_fade_add(events, false, WL_AYMERIC,
        AYMERIC_SPAWN);
    } else {
        animations_screen_fade_add(events, false, WL_PLAYER_HOME_2,
        PLAYER_DEFAULT_SPAWN);
    }
}

static void attack_loose(app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;
    sfTexture *icon = renderer->ressources->icons->hungry;

    if (app->player->life <= 0) {
        app->interaction->active = false;
        app->interaction->interaction = false;
        app->state = ST_INGAME;
        free(app->interaction->data.fight);
        events = animation_event_actual(app);
        animations_screen_zoom_add(events, renderer->map_view, 70, 2);
        events = animation_event_new(app);
        animations_notif_add(events, icon, ATTACKS_LOOSE_TITLE,
        ATTACKS_LOOSE_DESCRIPTION);
        teleport_player(app, events);
        app->player->life = app->player->life_max;
    } else {
        app->interaction->data.fight->state = FT_PLAYER_ATTACK;
    }
}

void core_fight_enemy(app_t *app, renderer_t *renderer)
{
    cjson_t *config = cjson_parse_file(ATTACKS_NPC_CONFIG);
    cjson_array_t *attacks = cjson_get_array_unsafe(config);
    cjson_t *node = NULL;
    fight_t *fight = app->interaction->data.fight;
    int index_attack = 0;
    size_t attack = 0;
    time_t t;

    srand((unsigned) time(&t));
    index_attack = rand() % fight->npc->enemy->nb_attacks;
    attack = fight->npc->enemy->attacks[index_attack];
    node = attacks->first;
    for (size_t i = 0; i < attack; i++) {
        node = node->next;
    }
    applay_attack(node, app);
    app->interaction->data.fight->round++;
    attack_loose(app, renderer);
    cjson_free(config);
}
