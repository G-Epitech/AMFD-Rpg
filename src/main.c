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

int main(void)
{
    renderer_t *renderer = renderer_init();
    app_t *app = NULL;

    load_renderer(renderer);
    app = app_init(renderer);
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
    app_free(app);
    return 0;
}
