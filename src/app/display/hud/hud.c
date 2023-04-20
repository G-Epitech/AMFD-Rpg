/*
** EPITECH PROJECT, 2023
** hud.c
** File description:
** Display hud quests
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "app/display/types.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "my/include/my.h"
#include "types/list/list.h"
#include "app/quests/quests.h"

static float display_text(renderer_t *renderer, char *title,
sfVector2f position, int size)
{
    sfText *text = renderer->objects->text;
    sfFloatRect rect = {0, 0, 0, 0};

    renderer_objects_reset_text(renderer->objects);
    sfText_setString(text, title);
    sfText_setCharacterSize(text, size);
    rect = sfText_getGlobalBounds(text);
    if (rect.height > 28)
        sfText_setPosition(text, (sfVector2f) {position.x, position.y - 12});
    else
        sfText_setPosition(text, position);
    sfRenderWindow_drawText(renderer->window, text, NULL);
    return rect.height;
}

void display_hud(renderer_t *renderer, app_t *app)
{
    quests_t *quests = core_quests_get(app);
    quest_t *quest = core_quest_get(app);
    float size = 0;

    if (app->state != ST_INGAME)
        return;
    size = display_text(renderer, quest->title, QUESTS_CONTENT_POS, 15);
    if (size > 21)
        display_text(renderer, quests->title, QUESTS_TITLE_POS, 20);
    else
        display_text(renderer, quests->title, QUESTS_TITLE_POS_UP, 20);
}
