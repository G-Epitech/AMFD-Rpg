/*
** EPITECH PROJECT, 2023
** reload_json.c
** File description:
** Reload json
*/

#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "types/components/components.h"
#include "app/loading/loading.h"
#include "app/types.h"

int developer_reload_json(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) app;
    (void) button;
    ressources_free(renderer->ressources);
    renderer->ressources = ressources_load(renderer);
    load_screen_add_bar(renderer, 7, "Rechargelent des composents...",
    "Rechargement developpeur");
    renderer->components = components_load(renderer);
    return 0;
}
