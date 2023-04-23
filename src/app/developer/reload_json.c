/*
** EPITECH PROJECT, 2023
** reload_json.c
** File description:
** Reload json
*/

#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "types/components/components.h"
#include "app/shop/shop.h"
#include "app/loading/loading.h"
#include "app/types.h"

int developer_reload_json(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) app;
    (void) button;
    ressources_free(renderer->ressources);
    renderer->ressources = ressources_load(renderer);
    load_screen_add_bar(renderer, 7, "Rechargement des composents...",
    "Rechargement developpeur");
    map_charge_collision_textures(renderer->ressources->maps);
    return 0;
}
