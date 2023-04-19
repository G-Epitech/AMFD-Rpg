/*
** EPITECH PROJECT, 2023
** dialogs.c
** File description:
** Dialogs NPC
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "app/display/types.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "my/include/my.h"
#include "types/list/list.h"

static void display_icon(renderer_t *renderer)
{
    sfSprite *sprite = renderer->objects->sprite;
    icons_r_t *icons = renderer->ressources->icons;

    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite,icons->selector_false, sfTrue);
    sfSprite_setPosition(sprite, DIALOGS_ICON_POSITION);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

static void display_text(char *content, renderer_t *renderer, int size,
sfVector2f position)
{
    sfText *text = renderer->objects->text;

    renderer_objects_reset_text(renderer->objects);
    sfText_setString(text, content);
    sfText_setPosition(text, position);
    sfText_setColor(text, TEXT_DEFAULT_COLOR);
    sfText_setCharacterSize(text, size);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

static void display_content(renderer_t *renderer, list_t *dialogs, int index)
{
    node_t *node = NULL;
    int i = 0;

    if (!dialogs || dialogs->len == 0)
        return;
    node = dialogs->first;
    while (node) {
        if (i == index) {
            display_text(node->data.npc_dialog.content, renderer, 25,
            DIALOGS_CONTENT_POSITION);
            return;
        }
        i += 1;
        node = node->next;
    }
}

void display_dialogs(renderer_t *renderer, app_t *app)
{
    interaction_dialogs_t *dialogs = NULL;

    if (app->interaction->type != IT_DIALOGS)
        return;
    dialogs = app->interaction->data.dialogs;
    display_text(dialogs->npc->npc->name, renderer, 36,
    DIALOGS_TITLE_POSITION);
    display_content(renderer, dialogs->npc->dialogs, dialogs->index);
    display_icon(renderer);
}
