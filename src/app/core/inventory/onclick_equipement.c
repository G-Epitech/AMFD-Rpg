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

static void unable_to_consume(app_t *app)
{
    char *message = "Impossible d'ajouter l'equipement.\n"
    "Veuillez liberer un emplacement.";

    dialog_box_set_message(app->dialog_box, message);
    dialog_box_set_option1(app->dialog_box, "OK");
    dialog_box_set_option2(app->dialog_box, NULL);
    dialog_box_set_option3(app->dialog_box, NULL);
    app->dialog_box->onoption1 = NULL;
    app->dialog_box->onoption2 = NULL;
    app->dialog_box->onoption3 = NULL;
    app->dialog_box->show = true;
    app->dialog_box->option = 1;
}

static void consume_equipement(app_t *app)
{
    inventory_item_t *item = app->inventory_event->selected;

    if (!item)
        return;
    if (!inventory_set_item_active(app->player, item)) {
        unable_to_consume(app);
    } else {
        inventory_item_impact_player(app->player, item, 1);
    }
}

static void sell_equipement(app_t *app)
{
    inventory_item_t *item = app->inventory_event->selected;

    my_putstr("Equipement vendu !\n");
    inventory_remove_item(app->player, item);
}

void inventory_onclick_item_equipement(app_t *app, inventory_item_t *item)
{
    char *tmp = my_strcat("Voulez-vous equiper de l'objet \n\"",
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
    dialog_box_set_option1(app->dialog_box, "M'equiper");
    dialog_box_set_option2(app->dialog_box, "Vendre");
    dialog_box_set_option3(app->dialog_box, "Annuler");
    app->dialog_box->onoption1 = &consume_equipement;
    app->dialog_box->onoption2 = &sell_equipement;
    app->dialog_box->onoption3 = NULL;
    app->dialog_box->show = true;
    app->dialog_box->option = 1;
}