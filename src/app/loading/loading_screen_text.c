/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** loading_screen_text
*/

#include <stdio.h>
#include <unistd.h>
#include "my/include/my.h"
#include "app/loading/types.h"
#include "app/loading/loading.h"
#include "types/renderer/renderer.h"

static void load_display_bar(renderer_t *renderer)
{
    sfTexture *texture = sfTexture_createFromFile(LOAD_TEXTURE, NULL);

    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(renderer->objects->sprite, texture, sfTrue);
    sfSprite_setPosition(renderer->objects->sprite, LOAD_POSITION);
    sfRenderWindow_drawSprite(renderer->window, renderer->objects->sprite,
    NULL);
    sfTexture_destroy(texture);
}

static void load_display_page(renderer_t *renderer, char *load_text)
{
    renderer_objects_t *objects = renderer->objects;
    sfFloatRect bound = {0, 0, 0, 0};

    sfText_setCharacterSize(objects->text, 40);
    sfText_setFont(objects->text, renderer->font);
    sfText_setFillColor(objects->text, TEXT_COLOR);
    sfText_setString(objects->text, load_text);
    bound = sfText_getGlobalBounds(objects->text);
    sfText_setPosition(objects->text, (sfVector2f) {960 - (bound.width / 2),
    800});
    sfRenderWindow_drawText(renderer->window, objects->text,
    NULL);
    load_display_bar(renderer);
}

static void load_display_small_text(renderer_t *renderer, char *load_text)
{
    renderer_objects_t *objects = renderer->objects;
    sfFloatRect bound = {0, 0, 0, 0};

    sfText_setCharacterSize(objects->text, 20);
    sfText_setString(objects->text, load_text);
    bound = sfText_getGlobalBounds(objects->text);
    sfText_setPosition(objects->text, (sfVector2f) {960 - (bound.width / 2),
    900});
    sfRenderWindow_drawText(renderer->window, objects->text,
    NULL);
}

void load_screen_add_bar(renderer_t *renderer, int stat, char *load_text,
char *info)
{
    sfTexture *texture = sfTexture_createFromFile(BAR_TEXTURE, NULL);

    sfRenderWindow_clear(renderer->window, BG_COLOR);
    load_display_page(renderer, load_text);
    load_display_small_text(renderer, info);
    sfSprite_setTexture(renderer->objects->sprite, texture, sfTrue);
    for (int i = 0; i < stat; i++) {
        sfSprite_setPosition(renderer->objects->sprite, (sfVector2f) {852 +
        (33 * i), 985});
        sfSprite_setScale(renderer->objects->sprite, (sfVector2f) {1, 1});
        sfRenderWindow_drawSprite(renderer->window, renderer->objects->sprite,
        NULL);
    }
    sfRenderWindow_display(renderer->window);
    loading_sleep(500);
    sfTexture_destroy(texture);
}

void load_screen_text_display(renderer_t *renderer, char *load_text)
{
        renderer->font = sfFont_createFromFile("assets/font.ttf");
    sfRenderWindow_clear(renderer->window, BG_COLOR);
    load_display_page(renderer, load_text);
    sfRenderWindow_display(renderer->window);
}
