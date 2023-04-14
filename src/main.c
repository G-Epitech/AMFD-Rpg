/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** @Hackers Quest 💻
** Main file
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "my/include/my.h"
#include "app/core/core.h"
#include "types/list/types.h"
#include "app/events/events.h"
#include "app/display/display.h"
#include "app/sound/sound_control.h"
#include "types/renderer/renderer.h"
#include "types/components/components.h"
#include "types/ressources/ressources.h"

void display_sounds(app_t *app)
{
    node_t *sounds = app->sound_board->sound_fx->first;
    node_t *themes = app->sound_board->sound_themes->first;

    while (sounds) {
        my_putstr(sounds->data.sound->title);
        my_put_nbr(sounds->data.sound->status);
        my_put_nbr(sounds->data.sound->loop);
        my_putchar('\n');
        sounds = sounds->next;
    }
    while (themes) {
        my_putstr(themes->data.theme->title);
        my_putchar(' ');
        my_put_nbr(themes->data.theme->status);
        my_putchar(' ');
        my_put_nbr(themes->data.theme->loop);
        my_putstr("\nApp states:");
        for (size_t i = 0; i < themes->data.theme->app_state_size; i++) {
            my_put_nbr(themes->data.theme->associated_app_state[i]);
            my_putchar(' ');
        }
        my_putchar('\n');
        themes = themes->next;
    }
}

int main(void)
{
    renderer_t *renderer = renderer_init();
    app_t *app = NULL;

    my_putchar('d');
    load_renderer(renderer);
    app = app_init();
    display_sounds(app);
    if (!renderer)
        return 84;
    if (!app) {
        renderer_destroy(renderer);
        return 84;
    }
    while (sfRenderWindow_isOpen(renderer->window)) {
        if (app_run(renderer, app) == 84)
            return 84;
    }
    renderer_destroy(renderer);
    return 0;
}
