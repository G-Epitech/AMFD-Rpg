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
    #define TEXTURE_GOBUSTER_LOCK renderer->ressources->icons->tree->go_buster_lock
    #define TEXTURE_GOBUSTER_UNLOCK renderer->ressources->icons->tree->go_buster_unlock
    #define POS_GOBUSTER_SPRITE (sfVector2f) {811, 398}
    #define TEXTURE_BRUTE_LOCK renderer->ressources->icons->tree->brute_force_lock
    #define TEXTURE_BRUTE_UNLOCK renderer->ressources->icons->tree->brute_force_unlock
    #define POS_BRUTE_SPRITE (sfVector2f) {811, 238}
    #define TEXTURE_FLIPPER_LOCK renderer->ressources->icons->tree->flipper_lock
    #define TEXTURE_FLIPPER_UNLOCK renderer->ressources->icons->tree->flipper_unlock
    #define POS_FLIPPER_SPRITE (sfVector2f) {1096, 551}
    #define TEXTURE_BASH_LOCK renderer->ressources->icons->tree->script_bash_lock
    #define TEXTURE_BASH_UNLOCK renderer->ressources->icons->tree->script_bash_unlock
    #define POS_BASH_SPRITE (sfVector2f) {516, 551}

typedef struct s_competences_node {
    int id;
    bool unlock;
} competences_node_t;

#endif /* !TYPES_COMPETENCES_TREE_H_ */
