/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialogs
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "types/npc/types.h"
#include "cjson/include/cjson.h"

static void dialog_append(cjson_t *source, list_t *dialogs_list)
{
    npc_dialog_t dialog = { NULL, NULL };
    node_t *node = NULL;

    if (!cjson_get_prop_string(source, "label", &dialog.label))
        return;
    if (!cjson_get_prop_string(source, "content", &dialog.content)) {
        free(dialog.label);
        return;
    }
    node = node_new((node_data_t) dialog);
    if (!node) {
        free(dialog.content);
        return free(dialog.label);
    }
    list_append(dialogs_list, node);
}

void npc_load_world_dialogs(cjson_array_t *dialogs, npc_data_t *world_data)
{
    list_t *dialogs_list = list_new();
    cjson_t *dialog_element = dialogs->first;

    if (!dialogs_list)
        return;
    while (dialog_element) {
        dialog_append(dialog_element, dialogs_list);
        dialog_element = dialog_element->next;
    }
    world_data->dialogs = dialogs_list;
}
