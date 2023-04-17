/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** Events of buttons components
*/


#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/app.h"
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "app/sound/sound_control.h"

static bool on_button(button_t *button, app_t *app,
sfEvent event)
{
    sfVector2f cursor = (sfVector2f) {event.mouseButton.x,
    event.mouseButton.y};

    if (!button->always_display && !app_on_state(app, button->app_state,
    button->state_size))
        return false;
    if (button->developer && !app->settings->developer)
        return false;
    if (cursor.x < button->position.x || cursor.y < button->position.y)
        return false;
    if (cursor.x > button->position.x + button->rect_scale.x)
        return false;
    if (cursor.y > button->position.y + button->rect_scale.y)
        return false;
    return true;
}

void event_components_buttons(renderer_t *renderer, app_t *app, sfEvent event)
{
    list_t *buttons = renderer->components->buttons;
    node_t *node = buttons->first;
    button_t *button = NULL;

    while (node) {
        button = node->data.button;
        if (on_button(button, app, event) && button->next_state > 0) {
            sound_control(SOUND_FX, CLICK_MENU, sfPlaying);
            app->state = button->next_state;
            break;
        }
        if (on_button(button, app, event)) {
            sound_control(SOUND_FX, CLICK_MENU, sfPlaying);
            event_button_map[button->event].function(renderer, app, button);
            break;
        }
        node = node->next;
    }
}
