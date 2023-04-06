/*
** EPITECH PROJECT, 2023
** main_menu.c
** File description:
** Display menus
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void display_main_menu(renderer_t *renderer, app_t *app)
{
    if (app->state != ST_MAIN_MENU)
        return;
    sfText_setString(renderer->objects->text, GAME_TITLE);
    sfText_setFont(renderer->objects->text, renderer->font);
    sfText_setCharacterSize(renderer->objects->text, 64);
    sfText_setPosition(renderer->objects->text, (sfVector2f) {532, 292});
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
}
