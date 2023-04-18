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

void display_anims(list_t *animations)
{
    node_t *node = animations->first;
    animation_t *anim = NULL;

    while (node) {
        anim = node->data.animation;
        my_putstr(anim->title);
        my_putstr(anim->file);
        my_put_nbr(anim->skin_id);
        my_put_nbr(anim->state);
        my_put_nbr(anim->frames_len);
        printf("Rect top:%d left:%d width:%d height:%d\n",
        anim->rect.top, anim->rect.left, anim->rect.width, anim->rect.height);
        node = node->next;
    }
}

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
    display_anims(app->animations);
    while (sfRenderWindow_isOpen(renderer->window)) {
        if (app_run(renderer, app) == 84)
            return 84;
    }
    renderer_destroy(renderer);
    app_free(app);
    return 0;
}
