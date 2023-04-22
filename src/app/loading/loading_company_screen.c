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

    while (sfTime_asSeconds(elapsed) <= 2.7 &&
    sfRenderWindow_isOpen(renderer->window)) {
        sfSprite_setScale(objects->sprite, scale);
        loading_screen_events(renderer);
        sfRenderWindow_clear(renderer->window, sfBlack);
        sfRenderWindow_drawSprite(renderer->window, objects->sprite,
        NULL);
        sfRenderWindow_display(renderer->window);
        elapsed = sfClock_getElapsedTime(clock);
        scale.x += 0.0045;
        scale.y += 0.0045;
    }
    sfClock_destroy(clock);
}

void loading_preload_screen(renderer_t *renderer)
{
    sfMusic *intro = sfMusic_createFromFile("assets/sounds/intro.ogg");
    sfTexture *preload_screen = sfTexture_createFromFile(LOGO_PATH, NULL);
    renderer_objects_t *objects = renderer->objects;

    sfMusic_play(intro);
    sfSprite_setTexture(objects->sprite, preload_screen, sfTrue);
    sfSprite_setPosition(objects->sprite, (sfVector2f) {960, 440});
    sfSprite_setOrigin(objects->sprite, (sfVector2f) {500, 450});
    zoom_screen(renderer);
    sfSprite_setOrigin(objects->sprite, (sfVector2f) {0, 0});
    sfTexture_destroy(preload_screen);
    sfMusic_stop(intro);
    sfMusic_destroy(intro);
}
