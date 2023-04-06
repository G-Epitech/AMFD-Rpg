/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** loading_screen_text
*/

#include <unistd.h>
#include "my/include/my.h"
#include "app/loading/types.h"
#include "types/renderer/types.h"

void load_screen_text_display(renderer_t *renderer, char *load_text)
{
    renderer_objects_t *objects = renderer->objects;

    sfRenderWindow_clear(renderer->window, sfWhite);
    sfText_setCharacterSize(objects->text, 40);
    renderer->font = sfFont_createFromFile("assets/font.ttf");
    sfText_setFont(objects->text, renderer->font);
    sfText_setFillColor(objects->text, sfBlack);
    sfText_setPosition(objects->text, (sfVector2f) {800, 900});
    sfText_setString(objects->text, load_text);
    sfRenderWindow_drawText(renderer->window, objects->text,
    NULL);
    sfRenderWindow_display(renderer->window);
}
