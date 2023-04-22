/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onclick
*/

#include <stdlib.h>
#include "app/types.h"
#include "my/include/my.h"
#include "app/items/items.h"
#include "app/inventory/types.h"
#include "app/display/display.h"
#include "types/dialog_box/dialog_box.h"

static void consume_item(app_t *app, char *data)
{
    inventory_item_t *item = app->inventory_event->selected;
    item_consumer_t consumer = NULL;

    (void) data;
    if (!item)
        return;
    consumer = item_get_consumer(item->target);
    if (consumer)
        consumer(app, item->target);
    inventory_remove_item(app->player, item);
}

static void sell_item(app_t *app, char *data)
{
    inventory_item_t *item = app->inventory_event->selected;

    (void) data;
    my_putstr("Item vendu !\n");
    inventory_remove_item(app->player, item);
}

static char *get_label(inventory_item_t *item)
{
    char *first = NULL;
    int len = my_strlen(item->target->label);
    char *second = NULL;

    if (len > 10) {
        first = my_strcat("Voulez-vous consommer l'objet \n\"",
        item->target->label);
    } else {
        first = my_strcat("Voulez-vous consommer l'objet \"",
        item->target->label);
    }
    if (len > 10)
        second = my_strcat(first, "\" ou alors le vendre\npour ");
    else
        second = my_strcat(first, "\"\nou alors le vendre pour ");
    free(first);
    first = my_strcat(second, nbr_to_str(item->target->price));
    free(second);
    return my_strcat(first, " pieces ?");
}

void inventory_onclick_item_consumable(app_t *app, inventory_item_t *item)
{
    char *label = get_label(item);

    dialog_box_set_message(app->dialog_box, label);
    dialog_box_set_option1(app->dialog_box, "Consommer");
    dialog_box_set_option2(app->dialog_box, "Vendre");
    dialog_box_set_option3(app->dialog_box, "Annuler");
    dialog_box_reset_events(app->dialog_box, true);
    app->dialog_box->onoption1 = &consume_item;
    app->dialog_box->onoption2 = &sell_item;
    app->dialog_box->show = true;
    app->dialog_box->option = 1;
}
