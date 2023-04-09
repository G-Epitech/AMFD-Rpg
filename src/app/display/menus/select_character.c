/*
** EPITECH PROJECT, 2023
** select_character.c
** File description:
** Display menus
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "types/character/types.h"

static void display_refuse_character(renderer_t *renderer, sfVector2f position)
{
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, renderer->ressources->icons->refuse, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

static void display_valid_character(renderer_t *renderer, sfVector2f position)
{
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, renderer->ressources->icons->valid, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

void display_select_character(renderer_t *renderer, app_t *app)
{
    if (app->state != ST_CHOICE)
        return;
    if (app->player->skin_id == STX_LUCAS)
        display_valid_character(renderer, VALID_LUCAS);
    if (app->player->skin_id == STX_TOM)
        display_valid_character(renderer, VALID_TOM);
    if (app->partner->skin_id == STX_LUCAS)
        display_refuse_character(renderer, REFUSE_LUCAS);
    if (app->partner->skin_id == STX_TOM)
        display_refuse_character(renderer, REFUSE_TOM);
}
