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

void app_task_brute_display(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    sfText_setPosition(objects->text, (sfVector2f) {980, 220});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Nomber de clique :");
    sfText_setCharacterSize(objects->text, 20);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {980, 220});
    sfText_setColor(objects->text, sfWhite);
    sfText_setCharacterSize(objects->text, 20);
    sfText_setString(objects->text, nbr_to_str(NB_CLICK(app)));
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}
