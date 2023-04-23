/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialog_box
*/

#include "app/types.h"
#include "my/include/my.h"
#include "types/list/types.h"
#include "app/display/types.h"
#include "app/display/display.h"
#include "types/dialog_box/types.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

static char *get_input_start(char *input)
{
    int len = my_strlen(input);
    int diff = 0;

    if (len <= DIALOG_BOX_INPUT_MAX_VISIBLE_LEN)
        return input;
    diff = len - DIALOG_BOX_INPUT_MAX_VISIBLE_LEN;
    return (input + diff);
}

static void display_cursor(renderer_t *renderer, sfFloatRect bounds)
{
    renderer_objects_t *objects = renderer->objects;
    sfText *text = objects->text;
    sfVector2f position = {bounds.left + bounds.width, bounds.top};

    sfText_setString(text, "_");
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

static void display_text(renderer_t *renderer, char *input)
{
    renderer_objects_t *objects = renderer->objects;
    sfText *text = objects->text;
    sfFloatRect bounds = {0, 0, 0, 0};
    char *input_start = get_input_start(input);

    renderer_objects_reset_text(objects);
    sfText_setFont(text, renderer->font);
    sfText_setCharacterSize(text, DIALOG_BOX_INPUT_TEXT_SIZE);
    sfText_setColor(text, MAIN_COLOR);
    sfText_setString(text, input_start);
    sfText_setPosition(text, DIALOG_BOX_INPUT_TEXT_POSITION);
    sfRenderWindow_drawText(renderer->window, text, NULL);
    bounds = sfText_getGlobalBounds(text);
    display_cursor(renderer, bounds);
}

static void display_rect(renderer_t *renderer)
{
    sfRectangleShape *rectangle = renderer->objects->rectangle;
    float thickness = DIALOG_BOX_INPUT_RECT_OULTINE_SIZE;
    sfColor out_color = DIALOG_BOX_INPUT_RECT_OUT_COLOR;
    sfColor in_color = DIALOG_BOX_INPUT_RECT_IN_COLOR;

    renderer_objects_reset_rectangle(renderer->objects);
    sfRectangleShape_setPosition(rectangle, DIALOG_BOX_INPUT_RECT_POSITION);
    sfRectangleShape_setOutlineThickness(rectangle, thickness);
    sfRectangleShape_setOutlineColor(rectangle, out_color);
    sfRectangleShape_setFillColor(rectangle, in_color);
    sfRectangleShape_setSize(rectangle, DIALOG_BOX_INPUT_RECT_SIZE);
    sfRenderWindow_drawRectangleShape(renderer->window, rectangle, NULL);
}

void display_dialog_box_input(renderer_t *renderer, dialog_box_t *dialog_box)
{
    display_rect(renderer);
    display_text(renderer, dialog_box->input);
}
