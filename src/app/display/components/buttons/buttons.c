/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** Display buttons components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/list/types.h"
#include "app/app.h"

static void display_rectangle(button_t *button, renderer_t *renderer)
{
    renderer_objects_t *objects = renderer->objects;

    renderer_objects_reset_rectangle(objects);
    sfRectangleShape_setPosition(objects->rectangle,
    (sfVector2f){button->position.x + 13 * button->scale,
    button->position.y});
    sfRectangleShape_setFillColor(objects->rectangle, button->color);
    sfRectangleShape_setSize(objects->rectangle, button->rect_scale);
    sfRenderWindow_drawRectangleShape(renderer->window, objects->rectangle,
    NULL);
}

static float setup_text(button_t *button, renderer_t *renderer)
{
    components_r_t *ressources = renderer->ressources->components;
    renderer_objects_t *objects = renderer->objects;
    sfFloatRect rect = {0, 0, 0, 0};
    float total = 0;

    sfText_setString(objects->text, button->title);
    sfText_setFont(objects->text, renderer->font);
    sfText_setColor(objects->text, button->text_color);
    sfText_setCharacterSize(objects->text, 30 * button->scale);
    rect = sfText_getGlobalBounds(objects->text);
    sfText_setPosition(objects->text, (sfVector2f) {button->position.x +
    (40 * button->scale), (button->position.y + (button->scale * 132 / 2))
    - rect.height / 2});
    total = ((80 * button->scale) + rect.width) - (40 * button->scale);
    return total / sfTexture_getSize(ressources->button->middle).x;
}

static void display_middle(button_t *button, renderer_t *renderer,
float scale)
{
    components_r_t *ressources = renderer->ressources->components;
    renderer_objects_t *objects = renderer->objects;
    sfVector2f left = SIZE_UP(sfTexture_getSize(ressources->button->left),
    button->scale);

    sfSprite_setTexture(objects->sprite, ressources->button->middle, sfTrue);
    sfSprite_setPosition(objects->sprite, MIDDLE_POS(left, button->position));
    sfSprite_setScale(objects->sprite, (sfVector2f) {scale, button->scale});
    sfRenderWindow_drawSprite(renderer->window, objects->sprite, NULL);
}

void display_button(button_t *button, renderer_t *renderer)
{
    components_r_t *ressources = renderer->ressources->components;
    renderer_objects_t *objects = renderer->objects;
    sfVector2f left = SIZE_UP(sfTexture_getSize(ressources->button->left),
    button->scale);
    float scale = setup_text(button, renderer);

    display_rectangle(button, renderer);
    sfSprite_setScale(objects->sprite, (sfVector2f) {button->scale,
    button->scale});
    sfSprite_setTexture(objects->sprite, ressources->button->left, sfTrue);
    sfSprite_setPosition(objects->sprite, button->position);
    sfRenderWindow_drawSprite(renderer->window, objects->sprite, NULL);
    display_middle(button, renderer, scale);
    sfSprite_setScale(objects->sprite, (sfVector2f) {button->scale,
    button->scale});
    sfSprite_setTexture(objects->sprite, ressources->button->right, sfTrue);
    sfSprite_setPosition(objects->sprite, RIGHT_POS(left,
    sfTexture_getSize(ressources->button->middle), button->position, scale));
    sfRenderWindow_drawSprite(renderer->window, objects->sprite, NULL);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

void display_components_buttons(renderer_t *renderer, app_t *app)
{
    list_t *buttons = renderer->components->buttons;
    node_t *node = buttons->first;
    button_t *button = NULL;

    while (node) {
        button = node->data.button;
        if (!button->always_display && !app_on_state(app, button->app_state,
        button->state_size)) {
            node = node->next;
            continue;
        }
        if (button->developer && !app->settings->developer) {
            node = node->next;
            continue;
        }
        display_buttons_dispatch(button, renderer);
        node = node->next;
    }
}
