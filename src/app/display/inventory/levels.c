/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** levels
*/

#include <stdlib.h>
#include "app/types.h"
#include "my/include/my.h"
#include "app/display/types.h"
#include "app/inventory/types.h"
#include "types/renderer/renderer.h"

static void display_inventory_intelligence_speed(renderer_t *renderer,
player_t *player)
{
    char *intelligence = nbr_to_str(player->xp);
    char *speed = nbr_to_str(player->xp);

    sfText_setPosition(renderer->objects->text,
    INVENTORY_INTELLIGENCE_LABEL_POS);
    sfText_setString(renderer->objects->text, intelligence);
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
    sfText_setPosition(renderer->objects->text,
    INVENTORY_SPEED_LABEL_POS);
    sfText_setString(renderer->objects->text, speed);
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
    free(intelligence);
    free(speed);
}

static void display_inventory_level_life(renderer_t *renderer,
player_t *player)
{
    char *level = nbr_to_str(player->xp);
    char *life = nbr_to_str(player->xp);
    char *label_level = my_strcat("Niv. ", level);
    char *label_life = my_strcat(level, player->xp == 1 ? " vie" : "  vies");

    sfText_setPosition(renderer->objects->text,
    INVENTORY_LEVEL_LABEL_POS);
    sfText_setString(renderer->objects->text, label_level);
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
    sfText_setPosition(renderer->objects->text,
    INVENTORY_LIFE_LABEL_POS);
    sfText_setString(renderer->objects->text, label_life);
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
    free(level);
    free(life);
    free(label_life);
    free(label_level);
}

void display_inventory_levels(renderer_t *renderer, app_t *app)
{
    renderer_objects_reset_text(renderer->objects);
    sfText_setFont(renderer->objects->text, renderer->font);
    sfText_setColor(renderer->objects->text, MAIN_COLOR);
    sfText_setCharacterSize(renderer->objects->text, 22);
    display_inventory_intelligence_speed(renderer, app->player);
    sfText_setCharacterSize(renderer->objects->text, 20);
    display_inventory_level_life(renderer, app->player);
}
