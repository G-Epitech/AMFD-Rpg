/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/app.h"
#include "types/list/list.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"
#include "app/competences_tree/types.h"

static void set_competence(int id, bool unlock, list_t *competences)
{
    node_t *node = competences ? competences->first : NULL;

    while (node) {
        if (node->data.competence->id == id) {
            node->data.competence->unlock = unlock;
            return;
        }
        node = node->next;
    }
}

void save_load_restore_player_competences(player_t *player,
cjson_t *player_file)
{
    cjson_array_t *array = NULL;
    cjson_t *competence = NULL;
    int id = 0;
    bool unlock = false;

    if (!cjson_get_prop_array(player_file, "competences", &array))
        return;
    competence = array ? array->first : NULL;
    while (competence) {
        cjson_get_prop_int(competence, "id", &id);
        cjson_get_prop_bool(competence, "unlock", &unlock);
        set_competence(id, unlock, player->competences);
        competence = competence->next;
    }
}
