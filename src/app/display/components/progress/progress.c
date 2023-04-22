/*
** EPITECH PROJECT, 2023
** progress.c
** File description:
** Display progress bar components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/list/types.h"
#include "app/app.h"

static void get_scale(progress_t *progress, sfVector2f *scale)
{
    sfVector2f total = {0, PROGRESS_RECT.y};

    total.x += PROGRESS_RECT.x * 50;
    total.x += PROGRESS_LEFT_BORDER_RECT.width;
    total.x += PROGRESS_RIGHT_BORDER_RECT.width;
    scale->x = progress->size.x / total.x;
    scale->y = progress->size.y / total.y;
}

static void display_borders(progress_t *progress, renderer_t *renderer,
sfVector2f scale)
{
    components_r_t *ressources = renderer->ressources->components;
    sfSprite *sprite = renderer->objects->sprite;
    sfVector2f right_pos = {
        progress->position.x + progress->size.x,
        progress->position.y
    };

    right_pos.x -= (float) PROGRESS_LEFT_BORDER_RECT.width * scale.x;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, ressources->progress, sfTrue);
    sfSprite_setTextureRect(sprite, PROGRESS_LEFT_BORDER_RECT);
    sfSprite_setPosition(sprite, progress->position);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    sfSprite_setTextureRect(sprite, PROGRESS_RIGHT_BORDER_RECT);
    sfSprite_setPosition(sprite, right_pos);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

static void display_sectors(progress_t *progress, renderer_t *renderer,
sfVector2f scale, int value)
{
    components_r_t *ressources = renderer->ressources->components;
    sfSprite *sprite = renderer->objects->sprite;
    sfVector2f position = progress->position;
    sfIntRect rect = {PROGRESS_COLOR_POS.x, PROGRESS_COLOR_POS.y,
    PROGRESS_RECT.x, PROGRESS_RECT.y};

    position.x += (float) PROGRESS_LEFT_BORDER_RECT.width * scale.x;
    rect.left += progress->color * (PROGRESS_MARGIN + PROGRESS_RECT.x);
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, ressources->progress, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, scale);
    for (int i = 0; i < value; i++) {
        sfSprite_setPosition(sprite, position);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
        position.x += PROGRESS_RECT.x * scale.x;
    }
}

static void display_remaining(progress_t *progress, renderer_t *renderer,
sfVector2f scale, int value)
{
    sfSprite *sprite = renderer->objects->sprite;
    sfVector2f position = progress->position;

    position.x += (float) PROGRESS_LEFT_BORDER_RECT.width * scale.x;
    position.x += PROGRESS_RECT.x * scale.x * value;
    if (50 - value > 0) {
        sfSprite_setTextureRect(sprite, PROGRESS_SEPARATOR_RECT);
        sfSprite_setPosition(sprite, position);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
        position.x += PROGRESS_RECT.x * scale.x;
    }
    sfSprite_setTextureRect(sprite, PROGRESS_EMPTY_RECT);
    for (int i = 0; i < (50 - value - 1); i++) {
        sfSprite_setPosition(sprite, position);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
        position.x += PROGRESS_RECT.x * scale.x;
    }
}

void display_progress(progress_t *progress, renderer_t *renderer, app_t *app)
{
    sfVector2f scale = {0, 0};
    progress_getter_value_t getter = progress_getters[progress->getter_value];
    int value = 0;

    if (getter)
        value = getter(app, progress) / 2;
    if (value < 0)
        value = 0;
    get_scale(progress, &scale);
    display_borders(progress, renderer, scale);
    display_sectors(progress, renderer, scale, value);
    display_remaining(progress, renderer, scale, value);
}
