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
#include "app/tasks/camera/camera.h"
#include "app/tasks/types.h"

static void display_time(renderer_t *renderer, app_t *app)
{
    char *char_second = NULL;
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 4);

    (void) app;
    sfText_setPosition(objects->text, (sfVector2f) {410, 230});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Temps :");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {560, 230});
    char_second = nbr_to_str((int) TIME_FLOAT(node->content.camera));
    sfText_setString(objects->text, char_second);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_life(renderer_t *renderer, app_t *app)
{
    char *char_life = NULL;
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 4);

    sfText_setPosition(objects->text, (sfVector2f) {410, 270});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Vie :");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {505, 270});
    char_life = nbr_to_str(CAMERA_LIFE(node));
    sfText_setString(objects->text, char_life);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_decorations(renderer_t *renderer)
{
    renderer_objects_t *objects = renderer->objects;

    sfText_setPosition(objects->text, (sfVector2f) {515, 830});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text,
    "Trouvez le code a 4 chiffres pour desactiver les cameras !");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {800, 250});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Code : ????");
    sfText_setCharacterSize(objects->text, 25);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {800, 300});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Votre reponse : ");
    sfText_setCharacterSize(objects->text, 25);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

void app_task_camera_display(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    renderer_objects_reset_text(objects);
    sfText_setCharacterSize(objects->text, 20);
    sfText_setFont(objects->text, renderer->font);
    display_time(renderer, app);
    display_life(renderer, app);
    display_decorations(renderer);
    sfText_setCharacterSize(objects->text, 25);
    display_equations(renderer, app);
    display_solution(renderer, app);
}
