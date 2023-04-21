/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onclick
*/

#include <stdlib.h>
#include "app/types.h"
#include "my/include/my.h"
#include "types/dialog_box/dialog_box.h"
#include "app/inventory/types.h"
#include "app/display/display.h"

static void remove_equipement(app_t *app)
{
    inventory_item_t *item = app->inventory_event->selected;

    if (!item)
        return;
    inventory_item_impact_player(app->player, item, -1);
    inventory_set_item_inactive(app->player, item);
}

void inventory_onclick_item_active(app_t *app, inventory_item_t *item)
{
    char *tmp = my_strcat("Voulez-vous retirer l'equipement \n\"",
    item->target->label);
    char *message = my_strcat(tmp, "\" ?");

    free(tmp);
    dialog_box_set_message(app->dialog_box, message);
    free(message);
    dialog_box_set_option1(app->dialog_box, "Retirer");
    dialog_box_set_option2(app->dialog_box, "Annuler");
    dialog_box_set_option3(app->dialog_box, NULL);
    app->dialog_box->onoption1 = &remove_equipement;
    app->dialog_box->onoption2 = NULL;
    app->dialog_box->onoption3 = NULL;
    app->dialog_box->option = 1;
    app->dialog_box->show = true;
}
