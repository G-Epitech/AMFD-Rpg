/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Add new player to list
*/

#include <stdlib.h>
#include "my/include/my.h"
#include "types/list/list.h"
#include "types/list/types.h"
#include "app/competences_tree/competences_tree.h"

static node_t *init_competence(int id)
{
    competences_node_t *competence = malloc(sizeof(competences_node_t));

    if (!competence)
        return NULL;
    competence->id = id;
    competence->unlock = false;
    return node_new((node_data_t) competence);
}

list_t *player_init_competence(void)
{
    list_t *competences = list_new();
    node_t *script_bash = init_competence(SCRIPT_BASH_ID);
    node_t *brute_force = init_competence(BRUTE_FORCE_ID);
    node_t *flipper = init_competence(FLIPPER_ID);
    node_t *go_buster = init_competence(GO_BUSTER_ID);

    if (!script_bash || !brute_force || !flipper || !go_buster)
        return NULL;
    list_append(competences, script_bash);
    list_append(competences, brute_force);
    list_append(competences, flipper);
    list_append(competences, go_buster);
    return competences;
}
