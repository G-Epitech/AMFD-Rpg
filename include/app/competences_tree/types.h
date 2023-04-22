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
    #define TEXTURE_GOBUSTER_LOCK renderer->ressources->icons->tree->\
    go_buster_lock
    #define TEXTURE_GOBUSTER_UNLOCK renderer->ressources->icons->tree->\
    go_buster_unlock
    #define POS_GOBUSTER_SPRITE ((sfVector2f) {811, 398})
    #define RECT_GOBUSTER(world_pos) (811 <= world_pos.x && \
world_pos.x <= 811 + 297 && 464 <= world_pos.y && world_pos.y <= 464 + 173)
    #define TEXTURE_BRUTE_LOCK renderer->ressources->icons->tree->\
    brute_force_lock
    #define TEXTURE_BRUTE_UNLOCK renderer->ressources->icons->tree->\
    brute_force_unlock
    #define POS_BRUTE_SPRITE ((sfVector2f) {811, 238})
    #define RECT_BRUTE(world_pos) (811 <= world_pos.x && world_pos.x \
<= 811 + 304 && 238 <= world_pos.y && world_pos.y <= 238 + 173)
    #define TEXTURE_FLIPPER_LOCK renderer->ressources->icons->tree->\
    flipper_lock
    #define TEXTURE_FLIPPER_UNLOCK renderer->ressources->icons->tree->\
    flipper_unlock
    #define POS_FLIPPER_SPRITE ((sfVector2f) {1096, 551})
    #define RECT_FLIPPER(world_pos) (1104 <= world_pos.x && world_pos.x \
<= 1104 + 306 && 690 <= world_pos.y && world_pos.y <= 690 + 173)
    #define TEXTURE_BASH_LOCK renderer->ressources->icons->tree->\
    script_bash_lock
    #define TEXTURE_BASH_UNLOCK renderer->ressources->icons->tree->\
    script_bash_unlock
    #define POS_BASH_SPRITE ((sfVector2f) {516, 551})
    #define RECT_BASH_SPRITE(world_pos) (516 <= world_pos.x && \
world_pos.x <= 516 + 297 && 690 <= world_pos.y && world_pos.y <= 690 + 173)
    #define TEXTURE_ONE_CREDIT renderer->ressources->icons->tree->one_credit
    #define POS_BASH_CREDIT ((sfVector2f) {620, 805})
    #define TEXTURE_THREE_CREDIT renderer->ressources->icons->tree->three_credit
    #define POS_GOBUSTER_CREDIT ((sfVector2f) {922, 577})
    #define POS_FLIPPER_CREDIT ((sfVector2f) {1215, 805})
    #define TEXTURE_FIVE_CREDIT renderer->ressources->icons->tree->five_credit
    #define POS_BRUTE_CREDIT ((sfVector2f) {922, 351})

typedef struct s_competences_node {
    int id;
    bool unlock;
} competences_node_t;

#endif /* !TYPES_COMPETENCES_TREE_H_ */
