/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialog_box
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/types.h"
#include "types/dialog_box/types.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

static void display_icon(renderer_t *renderer, bool selected,
sfVector2f position)
{
    sfSprite *sprite = renderer->objects->sprite;
    icons_r_t *icons = renderer->ressources->icons;

    position.y += DIALOG_BOX_ICON_MARGIN_TOP;
    renderer_objects_reset_sprite(renderer->objects);
    if (selected)
        sfSprite_setTexture(sprite, icons->selector_true, sfTrue);
    else
        sfSprite_setTexture(sprite, icons->selector_false, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

static void display_option(renderer_t *renderer, char *message,
bool selected, sfVector2f base)
{
    renderer_objects_t *objects = renderer->objects;
    sfText *text = objects->text;
    sfColor color = selected ? TEXT_SELECT_COLOR : TEXT_DEFAULT_COLOR;
    sfVector2f position = DIALOG_OPTION_POS_MARGIN(base);

    display_icon(renderer, selected, base);
    renderer_objects_reset_text(objects);
    sfText_setFont(text, renderer->font);
    sfText_setCharacterSize(text, 28);
    sfText_setColor(text, color);
    sfText_setString(text, message);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

void display_dialog_box_options(renderer_t *renderer,
dialog_box_t *dialog_box)
{
    int option = dialog_box->option;

    if (dialog_box->option1) {
        display_option(renderer, dialog_box->option1,
        option == 1, DIALOG_BOX_OPT1_POSITION);
    }
    if (dialog_box->option2) {
        display_option(renderer, dialog_box->option2,
        option == 2, DIALOG_BOX_OPT2_POSITION);
    }
    if (dialog_box->option3) {
        display_option(renderer, dialog_box->option3,
        option == 3, DIALOG_BOX_OPT3_POSITION);
    }
}
