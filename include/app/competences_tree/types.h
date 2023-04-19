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
    #define COMPETENCE_UNLOCK(comptence) competence->data.competence->unlock

typedef struct s_competences_node {
    int id;
    bool unlock;
    sfVector2f pos_competence;
    sfVector2f pos_pipe;
} competences_node_t;

#endif /* !TYPES_COMPETENCES_TREE_H_ */
