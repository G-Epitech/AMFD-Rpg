/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** Display buttons components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

static void display_rectangle(button_t *button, renderer_t *renderer,
float scale)
{
    components_r_t *ressources = renderer->ressources->components;
    sfVector2u middle = sfTexture_getSize(ressources->button->middle);

    sfRectangleShape_setPosition(renderer->rectangle,
    (sfVector2f){button->position.x + 13 * button->scale, button->position.y});
    sfRectangleShape_setFillColor(renderer->rectangle, button->color);
    sfRectangleShape_setSize(renderer->rectangle,
    (sfVector2f) {scale * middle.x + 15 * button->scale, button->scale * 152});
    sfRenderWindow_drawRectangleShape(renderer->window, renderer->rectangle,
    NULL);
}

static float setup_text(button_t *button, renderer_t *renderer)
{
    components_r_t *ressources = renderer->ressources->components;
    sfFloatRect rect = sfText_getGlobalBounds(renderer->text);
    float total = 0;

    sfText_setString(renderer->text, button->title);
    sfText_setFont(renderer->text, renderer->font);
    sfText_setColor(renderer->text, button->text_color);
    sfText_setCharacterSize(renderer->text, 25 * button->scale);
    sfText_setPosition(renderer->text, (sfVector2f) {button->position.x +
    (25 * button->scale), (button->position.y + (button->scale * 152 / 2))
    - rect.height / 2});
    total = ((50 * button->scale) + rect.width) - (40 * button->scale);
    return total / sfTexture_getSize(ressources->button->middle).x;
}

static void display_middle(button_t *button, renderer_t *renderer, float scale)
{
    components_r_t *ressources = renderer->ressources->components;
    sfVector2f left = SIZE_UP(sfTexture_getSize(ressources->button->left),
    button->scale);

    sfSprite_setTexture(renderer->sprite, ressources->button->middle, sfTrue);
    sfSprite_setPosition(renderer->sprite, MIDDLE_POS(left, button->position));
    sfSprite_setScale(renderer->sprite, (sfVector2f) {scale, button->scale});
    sfRenderWindow_drawSprite(renderer->window, renderer->sprite, NULL);
}

static void display_button(button_t *button, renderer_t *renderer)
{
    components_r_t *ressources = renderer->ressources->components;
    sfVector2f left = SIZE_UP(sfTexture_getSize(ressources->button->left),
    button->scale);
    float scale = setup_text(button, renderer);

    display_rectangle(button, renderer, scale);
    sfSprite_setScale(renderer->sprite, (sfVector2f) {button->scale,
    button->scale});
    sfSprite_setTexture(renderer->sprite, ressources->button->left, sfTrue);
    sfSprite_setPosition(renderer->sprite, button->position);
    sfRenderWindow_drawSprite(renderer->window, renderer->sprite, NULL);
    display_middle(button, renderer, scale);
    sfSprite_setScale(renderer->sprite, (sfVector2f) {button->scale,
    button->scale});
    sfSprite_setTexture(renderer->sprite, ressources->button->right, sfTrue);
    sfSprite_setPosition(renderer->sprite, RIGHT_POS(left,
    sfTexture_getSize(ressources->button->middle), button->position, scale));
    sfRenderWindow_drawSprite(renderer->window, renderer->sprite, NULL);
    sfRenderWindow_drawText(renderer->window, renderer->text, NULL);
}

void display_components_buttons(renderer_t *renderer, app_t *app)
{
    list_t *buttons = renderer->components->buttons;
    node_t *node = buttons->first;
    button_t *button = NULL;

    while (node) {
        button = node->data.button;
        if (button->app_state == app->state) {
            display_button(button, renderer);
        }
        node = node->next;
    }
}
