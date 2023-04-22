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

void inventory_onclick_item_consumable(app_t *app, inventory_item_t *item)
{
    char *tmp = my_strcat("Voulez-vous consommer de l'objet \n\"",
    item->target->label);
    char *tmp2 = my_strcat(tmp, "\" ou alors le\nvendre pour ");
    char *price = nbr_to_str(item->target->price);

    free(tmp);
    tmp = my_strcat(tmp2, price);
    free(tmp2);
    tmp2 = my_strcat(tmp, " pieces ?");
    dialog_box_set_message(app->dialog_box, tmp2);
    free(tmp2);
    free(tmp);
    dialog_box_set_option1(app->dialog_box, "Consommer");
    dialog_box_set_option2(app->dialog_box, "Vendre");
    dialog_box_set_option3(app->dialog_box, "Annuler");
    app->dialog_box->onoption1 = &consume_item;
    app->dialog_box->onoption2 = &sell_item;
    app->dialog_box->onoption3 = NULL;
    app->dialog_box->show = true;
    app->dialog_box->option = 1;
}
