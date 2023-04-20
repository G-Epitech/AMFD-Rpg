/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player
*/

#include <stdio.h>
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "app/competences_tree/competences_tree.h"

static void display_script_bash(node_t *competence, renderer_t *renderer)
{
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    if (COMPETENCE_UNLOCK(competence)) {
        sfSprite_setTexture(sprite, TEXTURE_BASH_UNLOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_BASH_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    } else {
        sfSprite_setTexture(sprite, TEXTURE_BASH_LOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_BASH_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    }
}

static void display_flipper(node_t *competence, renderer_t *renderer)
{
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    if (COMPETENCE_UNLOCK(competence)) {
        sfSprite_setTexture(sprite, TEXTURE_FLIPPER_UNLOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_FLIPPER_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    } else {
        sfSprite_setTexture(sprite, TEXTURE_FLIPPER_LOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_FLIPPER_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    }
}

static void display_brute_force(node_t *competence, renderer_t *renderer)
{
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    if (COMPETENCE_UNLOCK(competence)) {
        sfSprite_setTexture(sprite, TEXTURE_BRUTE_UNLOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_BRUTE_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    } else {
        sfSprite_setTexture(sprite, TEXTURE_BRUTE_LOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_BRUTE_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    }
}

static void display_go_buster(node_t *competence, renderer_t *renderer)
{
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    if (COMPETENCE_UNLOCK(competence)) {
        sfSprite_setTexture(sprite, TEXTURE_GOBUSTER_UNLOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_GOBUSTER_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    } else {
        sfSprite_setTexture(sprite, TEXTURE_GOBUSTER_LOCK, sfTrue);
        sfSprite_setPosition(sprite, POS_GOBUSTER_SPRITE);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    }
}

void display_competences_tree(renderer_t *renderer, app_t *app)
{
    list_t *competences = app->player->competences;
    node_t *temp_competence = competences->first;

    if (app->state != ST_IG_TREE_COMPETENCE)
        return;
    while (temp_competence != NULL) {
        if (COMPETENCE_ID(temp_competence) == SCRIPT_BASH_ID)
            display_script_bash(temp_competence, renderer);
        if (COMPETENCE_ID(temp_competence) == FLIPPER_ID)
            display_flipper(temp_competence, renderer);
        if (COMPETENCE_ID(temp_competence) == GO_BUSTER_ID)
            display_go_buster(temp_competence, renderer);
        if (COMPETENCE_ID(temp_competence) == BRUTE_FORCE_ID)
            display_brute_force(temp_competence, renderer);
        temp_competence = temp_competence->next;
    }
}
