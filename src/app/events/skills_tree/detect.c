/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events of skills tree
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "app/events/events.h"
#include "app/competences_tree/competences_tree.h"
#include "app/app.h"

static void detect_click_bash(app_t *app, renderer_t *renderer)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(renderer->window);
    sfVector2f world_pos =
    sfRenderWindow_mapPixelToCoords(renderer->window, mouse_pos, NULL);
    competences_node_t *skill = NULL;

    if (RECT_BASH_SPRITE(world_pos)
    && app->player->credits >= 1) {
        skill = find_skill(app, SCRIPT_BASH_ID);
        skill->unlock = true;
        app->player->credits -= 1;
        inventory_add_item_by_id(app, 10);
    }
}

static void detect_click_flipper(app_t *app, renderer_t *renderer)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(renderer->window);
    sfVector2f world_pos =
    sfRenderWindow_mapPixelToCoords(renderer->window, mouse_pos, NULL);
    competences_node_t *skill = NULL;

    if (RECT_FLIPPER(world_pos) && app->player->credits >= 3) {
        skill = find_skill(app, FLIPPER_ID);
        skill->unlock = true;
        app->player->credits -= 3;
    }
}

static void detect_click_go_buster(app_t *app, renderer_t *renderer)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(renderer->window);
    sfVector2f world_pos =
    sfRenderWindow_mapPixelToCoords(renderer->window, mouse_pos, NULL);
    competences_node_t *skill = NULL;
    competences_node_t *bash = find_skill(app, SCRIPT_BASH_ID);
    competences_node_t *flipper = find_skill(app, FLIPPER_ID);

    if (RECT_GOBUSTER(world_pos) && flipper->unlock && bash->unlock
    && app->player->credits >= 3) {
        skill = find_skill(app, GO_BUSTER_ID);
        skill->unlock = true;
        app->player->credits -= 3;
    }
}

static void detect_click_brute(app_t *app, renderer_t *renderer)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(renderer->window);
    sfVector2f world_pos =
    sfRenderWindow_mapPixelToCoords(renderer->window, mouse_pos, NULL);
    competences_node_t *buster = find_skill(app, GO_BUSTER_ID);
    competences_node_t *skill = NULL;

    if (RECT_BRUTE(world_pos) && buster->unlock && app->player->credits >= 5) {
        skill = find_skill(app, BRUTE_FORCE_ID);
        skill->unlock = true;
        app->player->credits -= 5;
    }
}

void event_handler_skills_tree(app_t *app, renderer_t *renderer)
{
    if (app->state != ST_IG_TREE_COMPETENCE)
        return;
    detect_click_bash(app, renderer);
    detect_click_flipper(app, renderer);
    detect_click_go_buster(app, renderer);
    detect_click_brute(app, renderer);
}
