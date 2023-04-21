/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events of skills tree
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/events/events.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "app/competences_tree/competences_tree.h"

competences_node_t *find_skill(app_t *app, int id)
{
    list_t *competences = app->player->competences;
    node_t *temp_competence = competences->first;

    while (temp_competence != NULL) {
        if (COMPETENCE_ID(temp_competence) == id)
            return temp_competence->data.competence;
        temp_competence = temp_competence->next;
    }
    return NULL;
}
