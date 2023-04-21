/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialog_box
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/types.h"
#include "app/display/display.h"
#include "types/dialog_box/types.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

static void display_box(renderer_t *renderer)
{
    renderer_objects_t *objects = renderer->objects;
    sfTexture *texture = renderer->ressources->components->dialog_box;
    sfSprite *sprite = objects->sprite;

    renderer_objects_reset_sprite(objects);
    sfSprite_setPosition(sprite, DIALOG_BOX_POSITION);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

static void display_message(renderer_t *renderer, dialog_box_t *box)
{
    renderer_objects_t *objects = renderer->objects;
    sfText *text = objects->text;

    renderer_objects_reset_text(objects);
    sfText_setFont(text, renderer->font);
    sfText_setCharacterSize(text, 24);
    sfText_setColor(text, MAIN_COLOR);
    sfText_setString(text, box->message);
    sfText_setPosition(text, DIALOG_BOX_MESSAGE_POSITION);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

void display_dialog_box(renderer_t *renderer, dialog_box_t *dialog_box)
{
    if (!dialog_box->show)
        return;
    display_box(renderer);
    display_message(renderer, dialog_box);
    display_dialog_box_options(renderer, dialog_box);
}
