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

void display_vector(sfVector2f v)
{
    printf(" vector x:%.0f y:%.0f\n", v.x, v.y);
}

void display_entry(list_t *maps)
{
    node_t *node = maps->first;
    node_t *entry = NULL;
    entry_t *entry_obj = NULL;
    int i = 0;

    while (node) {
        if (!node->data.map->entry)
            break;
        entry = node->data.map->entry->first;
        printf("World %d\n", node->data.map->world);
        while (entry) {
            entry_obj = entry->data.entry;
            printf("%d: Dir %d, child %d, tile_size %d", i, entry_obj->direction,
            entry_obj->child, entry_obj->tile_size);
            display_vector(entry_obj->pos);
            display_vector(entry_obj->player_spawn);
            entry = entry->next;
        }
        printf("----------------\n");
        i++;
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
    display_entry(renderer->ressources->maps);
    while (sfRenderWindow_isOpen(renderer->window)) {
        if (app_run(renderer, app) == 84)
            return 84;
    }
    renderer_destroy(renderer);
    app_free(app);
    return 0;
}
