/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdio.h>
#include "types/renderer/renderer.h"
#include "app/tasks/task.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "app/tasks/flipper/flipper.h"
#include "app/tasks/types.h"

static void display_time(renderer_t *renderer, app_t *app)
{
    char *char_second = NULL;
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 3);

    (void) app;
    sfText_setPosition(objects->text, (sfVector2f) {410, 230});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Temps :");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {560, 230});
    char_second = nbr_to_str((int) TIME_FLOAT(node->content.flipper));
    sfText_setString(objects->text, char_second);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_life(renderer_t *renderer, app_t *app)
{
    char *char_life = NULL;
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 3);

    sfText_setPosition(objects->text, (sfVector2f) {410, 270});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "vie :");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {505, 270});
    char_life = nbr_to_str(NB_LIFE_FLIPPER(node));
    sfText_setString(objects->text, char_life);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_nb_circle(renderer_t *renderer, app_t *app)
{
    char *char_nb_circle = NULL;
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 3);

    sfText_setPosition(objects->text, (sfVector2f) {410, 310});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Nombre de cercles :");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {730, 310});
    char_nb_circle = nbr_to_str(NB_CIRCLE_FLIPPER(node));
    sfText_setString(objects->text, char_nb_circle);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_circle(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 3);
    node_t *temp_circle = node->content.flipper.circles->first;
    sfVector2f pos;

    while (temp_circle) {
        if (STATUS_CIRCLE(temp_circle) == OPEN)
            sfCircleShape_setOutlineColor(objects->circle, COLOR_GRENN);
        else
            sfCircleShape_setOutlineColor(objects->circle, COLOR_RED);
        pos.x = POS_CIRCLE(temp_circle).x - RAYON_CIRCLE(temp_circle);
        pos.y = POS_CIRCLE(temp_circle).y - RAYON_CIRCLE(temp_circle);
        sfCircleShape_setOutlineThickness(objects->circle, 5);
        sfCircleShape_setFillColor(objects->circle, sfTransparent);
        sfCircleShape_setRadius(objects->circle, RAYON_CIRCLE(temp_circle));
        sfCircleShape_setPosition(objects->circle, pos);
        sfRenderWindow_drawCircleShape(renderer->window, objects->circle, NULL);
        temp_circle = temp_circle->next;
    }
}

void app_task_flipper_display(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    renderer_objects_reset_text(objects);
    sfText_setFont(objects->text, renderer->font);
    display_time(renderer, app);
    display_life(renderer, app);
    display_nb_circle(renderer, app);
    display_circle(renderer, app);
}
