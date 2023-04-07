/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bruteforce/bruteforce.h"
#include "app/tasks/bruteforce/types.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "app/tasks/types.h"

static void display_objectif(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    (void) app;
    sfText_setPosition(objects->text, (sfVector2f) {410, 300});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Objectif :");
    sfText_setCharacterSize(objects->text, 20);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {570, 300});
    sfText_setColor(objects->text, sfWhite);
    sfText_setCharacterSize(objects->text, 20);
    sfText_setString(objects->text, nbr_to_str(OBJECTIF(app)));
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_time(renderer_t *renderer, app_t *app)
{
    char *char_second = NULL;
    renderer_objects_t *objects = renderer->objects;

    (void) app;
    sfText_setPosition(objects->text, (sfVector2f) {410, 260});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "timer :");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {525, 260});
    char_second = nbr_to_str((int) TIME_FLOAT(NODE_BRUTE));
    sfText_setString(objects->text, char_second);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_clicker(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    sfText_setPosition(objects->text, (sfVector2f) {410, 220});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Nombre de cliques :");
    sfText_setCharacterSize(objects->text, 20);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {730, 220});
    sfText_setColor(objects->text, sfWhite);
    sfText_setCharacterSize(objects->text, 20);
    sfText_setString(objects->text, nbr_to_str(NB_CLICK(app)));
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_cliquer(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    sfText_setPosition(objects->text, (sfVector2f) {790, 780});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Cliquez !");
    sfText_setCharacterSize(objects->text, SIZE_TEXT(app));
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

void app_task_brute_display(renderer_t *renderer, app_t *app)
{
    display_clicker(renderer, app);
    display_time(renderer, app);
    display_objectif(renderer, app);
    display_cliquer(renderer, app);
}
