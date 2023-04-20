/*
** EPITECH PROJECT, 2023
** choice.c
** File description:
** Fight choice
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/display/types.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "my/include/my.h"
#include "cjson/include/cjson.h"

static void display_choice_icon(char **choices, renderer_t *renderer,
int choice)
{
    sfSprite *sprite = renderer->objects->sprite;
    icons_r_t *icons = renderer->ressources->icons;

    renderer_objects_reset_sprite(renderer->objects);
    for (size_t i = 0; choices[i] != NULL; i++) {
        if ((int) i == choice)
            sfSprite_setTexture(sprite,icons->selector_true, sfTrue);
        else
            sfSprite_setTexture(sprite,icons->selector_false, sfTrue);
        sfSprite_setPosition(sprite, (sfVector2f) {
            FIGHT_CHOICE_RESPONSIVE.x - FIGHT_CHOICE_ICON_X,
            FIGHT_CHOICE_RESPONSIVE.y + FIGHT_CHOICE_RATIO * i
            + FIGHT_CHOICE_ICON_Y
        });
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    }
}

static void display_choice_text(renderer_t *renderer, int choice)
{
    sfText *text = renderer->objects->text;
    cjson_t *file = cjson_parse_file(FIGHT_CHOICE_CONFIG);
    cjson_array_t *array = cjson_get_array_unsafe(file);
    char **choices = cjson_array_to_string_array(array);

    renderer_objects_reset_text(renderer->objects);
    for (size_t i = 0; choices[i] != NULL; i++) {
        sfText_setString(text, choices[i]);
        sfText_setPosition(text, (sfVector2f) {
            FIGHT_CHOICE_RESPONSIVE.x,
            FIGHT_CHOICE_RESPONSIVE.y + FIGHT_CHOICE_RATIO * i
        });
        sfText_setCharacterSize(text, 30);
        if ((int) i == choice)
            sfText_setColor(text, TEXT_SELECT_COLOR);
        else
            sfText_setColor(text, TEXT_DEFAULT_COLOR);
        sfRenderWindow_drawText(renderer->window, text, NULL);
    }
    display_choice_icon(choices, renderer, choice);
}

static void display_title(char *title, renderer_t *renderer)
{
    sfText *text = renderer->objects->text;

    renderer_objects_reset_text(renderer->objects);
    sfText_setString(text, title);
    sfText_setPosition(text, FIGHT_CHOICE_TITLE_POSITION);
    sfText_setColor(text, TEXT_DEFAULT_COLOR);
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

void display_fight_choice(renderer_t *renderer, app_t *app)
{
    fight_t *fight = NULL;
    char *name = NULL;
    char *title = NULL;

    if (app->interaction->data.fight->state != FT_CHOICE)
        return;
    fight = app->interaction->data.fight;
    name = fight->npc->npc->name;
    title = my_strcat(name, FIGHT_CHOICE_TITLE);
    display_title(title, renderer);
    display_choice_text(renderer, fight->choice);
}
