/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_grid
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "app/inventory/types.h"
#include "types/ressources/ressources.h"

static void display_item(renderer_t *renderer, inventory_item_t *item)
{
    display_inventory_item_box(renderer, item->pos, item->active, false);
}

static void get_boxes_occupations(int **actives_boxes, int **main_boxes)
{
    sfVector2i active_size = INVENTORY_ACTIVE_GRID_SIZE;
    sfVector2i main_size = INVENTORY_MAIN_GRID_SIZE;
    size_t size_actives_boxes = sizeof(int) * active_size.x * active_size.y;
    size_t size_main_boxes = sizeof(int) * main_size.x * main_size.y;

    *actives_boxes = malloc(size_actives_boxes);
    *main_boxes = malloc(size_main_boxes);
    printf("actives : %d\n", active_size.x * active_size.y);
    printf("main : %d\n", main_size.x * main_size.y);
    memset(*actives_boxes, 0, size_actives_boxes);
    memset(*main_boxes, 0, size_main_boxes);
}

static void set_box_occupation(inventory_item_t *item, int *actives_boxes,
int *main_boxes)
{
    sfVector2i active_size = INVENTORY_ACTIVE_GRID_SIZE;
    sfVector2i main_size = INVENTORY_MAIN_GRID_SIZE;
    int nb_actives_boxes = active_size.x * active_size.y;
    int nb_main_boxes = main_size.x * main_size.y;
    int pos = item->active ? -item->pos : item->pos;

    pos -= 1;
    if (item->active && pos >= 0 && pos < nb_actives_boxes)
        actives_boxes[pos] = 1;
    else if (pos >= 0 && pos < nb_main_boxes)
        main_boxes[pos] = 1;
}

static void display_empty(renderer_t *renderer, int *actives_boxes,
int *main_boxes)
{
    sfVector2i active_size = INVENTORY_ACTIVE_GRID_SIZE;
    sfVector2i main_size = INVENTORY_MAIN_GRID_SIZE;
    size_t nb_actives_boxes = active_size.x * active_size.y;
    size_t nb_main_boxes = main_size.x * main_size.y;

    for (size_t i = 0; i < nb_actives_boxes; i++) {
        printf("active[%zu] = %d\n", i, actives_boxes[i]);
        if (actives_boxes[i] == 0)
            display_inventory_item_box(renderer, i + 1, true, true);
    }
    for (size_t i = 0; i < nb_main_boxes; i++) {
        if (main_boxes[i] == 0)
            display_inventory_item_box(renderer, i + 1, false, true);
    }
}

void display_inventory_grids(renderer_t *renderer, app_t *app)
{
    list_t *inventory = app->player->inventory;
    node_t *node = inventory ? inventory->first : NULL;
    int *main_boxes = NULL;
    int *actives_boxes = NULL;
    inventory_item_t *item = NULL;

    get_boxes_occupations(&actives_boxes, &main_boxes);
    while (node) {
        item = node->data.inventory_item;
        if (item) {
            display_item(renderer, item);
            set_box_occupation(item, actives_boxes, main_boxes);
        }
        node = node->next;
    }
    display_empty(renderer, actives_boxes, main_boxes);
    free(actives_boxes);
    free(main_boxes);
}
