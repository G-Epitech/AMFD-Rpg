/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** loading_screen_text
*/

#include <unistd.h>
#include "app/loading/types.h"
#include "types/renderer/types.h"
#include "my/include/my.h"

void load_screen_text_display(renderer_t *renderer, char *load_text)
{
    sfRenderWindow_clear(renderer->window, sfWhite);
    sfText_setCharacterSize(renderer->text, 40);
    sfText_setFont(renderer->text, sfFont_createFromFile(FONT_PATH));
    sfText_setFillColor(renderer->text, sfBlack);
    sfText_setPosition(renderer->text, (sfVector2f) {800, 900});
    sfText_setString(renderer->text, load_text);
    sfRenderWindow_drawText(renderer->window, renderer->text,
    NULL);
    sfRenderWindow_display(renderer->window);
}
