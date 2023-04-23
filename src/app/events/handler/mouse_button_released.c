/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "app/events/events.h"
#include "types/renderer/types.h"
#include "app/inventory/inventory.h"
#include "app/tasks/bruteforce/bruteforce.h"

void event_mouse_button_released(app_t *app, renderer_t *renderer,
sfEvent event)
{
    if (event.type != sfEvtMouseButtonReleased)
        return;
    if (app->dialog_box->show)
        return;
    if (app->state == ST_TASK_BRUTEFORCE)
        brute_force_released(renderer, app);
    if (app->state == ST_INVENTORY)
        inventory_onrelease(app, event);
}
