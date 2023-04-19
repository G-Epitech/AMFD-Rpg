/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player
*/

#include <stdio.h>
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "app/competences_tree/competences_tree.h"

static void display_competence(node_t *competence)
{
    if (COMPETENCE_UNLOCK(competence)) {
        
    } else {

    }
}

void display_competences_tree(renderer_t *renderer, app_t *app)
{
    list_t *competences = app->player->competences;
    node_t *temp_competence = competences->first;

    while (temp_competence != NULL) {
        display_competence(temp_competence);
        temp_competence = temp_competence->next;
    }
}
