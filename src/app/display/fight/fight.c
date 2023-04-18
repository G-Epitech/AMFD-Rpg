/*
** EPITECH PROJECT, 2023
** fight.c
** File description:
** Fight main
*/

#include "app/display/display.h"
#include "app/types.h"
#include "types/renderer/types.h"
#include "types/renderer/renderer.h"
#include "app/display/types.h"
#include "my/include/my.h"

static void display_round(renderer_t *renderer, app_t *app)
{
    sfText *text = renderer->objects->text;

    renderer_objects_reset_text(renderer->objects);
    sfText_setString(text, nbr_to_str(app->interaction->data.fight->round));
    sfText_setCharacterSize(text, 28);
    sfText_setPosition(text, (sfVector2f) {1555, 130});
    sfText_setColor(text, TEXT_DEFAULT_COLOR);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

void display_fight(renderer_t *renderer, app_t *app)
{
    if (app->state != ST_FIGHT ||
    !app->interaction->active ||
    app->interaction->type != IT_FIGHT)
        return;
    display_fight_choice(renderer, app);
    display_fight_attack(renderer, app);
    display_round(renderer, app);
}
