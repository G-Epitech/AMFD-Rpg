/*
** EPITECH PROJECT, 2023
** loading_screen.c
** File description:
** Display loading screens
*/

#include "app/loading/types.h"
#include "types/renderer/renderer.h"

static void get_position(sfVector2f *position, sfRenderWindow *window)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);

    position->x = (float) win_size.x / 2;
    position->y = (float) win_size.y / 2;
}

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

    while (sfTime_asSeconds(elapsed) <= 4.5 &&
    sfRenderWindow_isOpen(renderer->window)) {
        sfSprite_setScale(objects->sprite, scale);
        loading_screen_events(renderer);
        sfRenderWindow_clear(renderer->window, sfBlack);
        sfRenderWindow_drawSprite(renderer->window, objects->sprite,
        NULL);
        sfRenderWindow_display(renderer->window);
        elapsed = sfClock_getElapsedTime(clock);
        if (sfTime_asSeconds(elapsed) <= 3.0) {
            scale.x += 0.0045;
            scale.y += 0.0045;
        }
    }
    sfClock_destroy(clock);
}

void loading_preload_screen(renderer_t *renderer)
{
    sfMusic *intro = sfMusic_createFromFile("assets/sounds/intro.ogg");
    sfTexture *preload_screen = sfTexture_createFromFile(LOGO_PATH, NULL);
    renderer_objects_t *objects = renderer->objects;
    sfVector2f position = {0, 0};

    get_position(&position, renderer->window);
    renderer_objects_reset_sprite(objects);
    sfMusic_play(intro);
    sfSprite_setTexture(objects->sprite, preload_screen, sfTrue);
    sfSprite_setPosition(objects->sprite, position);
    sfSprite_setOrigin(objects->sprite, (sfVector2f) {364, 66});
    zoom_screen(renderer);
    sfTexture_destroy(preload_screen);
    sfMusic_stop(intro);
    sfMusic_destroy(intro);
}
