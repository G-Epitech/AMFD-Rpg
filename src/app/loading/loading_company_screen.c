/*
** EPITECH PROJECT, 2023
** loading_screen.c
** File description:
** Display loading screens
*/

#include "app/loading/types.h"
#include "types/renderer/types.h"

void loading_screen_events(renderer_t *renderer)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(renderer->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(renderer->window);
        }
    }
}

void zoom_screen(renderer_t *renderer)
{
    renderer_objects_t *objects = renderer->objects;
    sfClock *clock = sfClock_create();
    sfTime elapsed = sfClock_getElapsedTime(clock);
    sfVector2f scale = (sfVector2f) {0.1, 0.1};

    while (sfTime_asSeconds(elapsed) <= 3 &&
    sfRenderWindow_isOpen(renderer->window)) {
        sfSprite_setScale(objects->sprite, scale);
        loading_screen_events(renderer);
        sfRenderWindow_clear(renderer->window, sfBlack);
        sfRenderWindow_drawSprite(renderer->window, objects->sprite,
        NULL);
        sfRenderWindow_display(renderer->window);
        elapsed = sfClock_getElapsedTime(clock);
        scale.x += 0.003;
        scale.y += 0.003;
    }
    sfClock_destroy(clock);
}

void loading_preload_screen(renderer_t *renderer)
{
    sfTexture *preload_screen = sfTexture_createFromFile(LOGO_PATH, NULL);
    renderer_objects_t *objects = renderer->objects;

    sfSprite_setTexture(objects->sprite, preload_screen, sfTrue);
    sfSprite_setPosition(objects->sprite, (sfVector2f) {960, 400});
    sfSprite_setOrigin(objects->sprite, (sfVector2f) {500, 450});
    zoom_screen(renderer);
    sfSprite_setOrigin(objects->sprite, (sfVector2f) {0, 0});
    sfTexture_destroy(preload_screen);
}
