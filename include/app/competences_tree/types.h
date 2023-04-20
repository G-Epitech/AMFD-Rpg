/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** types_competences_tree
*/

#ifndef TYPES_COMPETENCES_TREE_H_
    #define TYPES_COMPETENCES_TREE_H_

    #include <SFML/Graphics.h>
    #include <stdbool.h>

    #define SCRIPT_BASH_ID 1
    #define BRUTE_FORCE_ID 2
    #define FLIPPER_ID 3
    #define GO_BUSTER_ID 4
    #define COMPETENCE_UNLOCK(competence) competence->data.competence->unlock
    #define COMPETENCE_ID(temp_competence) temp_competence->data.competence->id

typedef struct s_competences_node {
    int id;
    bool unlock;
} competences_node_t;

#endif /* !TYPES_COMPETENCES_TREE_H_ */