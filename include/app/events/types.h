/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Events types
*/

#ifndef EVENTS_TYPES_H_
    #define EVENTS_TYPES_H_

    #include <SFML/Graphics.h>

    #define POSITION_UP(position) ((sfVector2f) {position.x, position.y - 1})
    #define POSITION_DOWN(position) ((sfVector2f) {position.x, position.y + 1})
    #define POSITION_LEFT(position) ((sfVector2f) {position.x - 1, position.y})
    #define POSITION_RIGHT(position) ((sfVector2f)\
    {position.x + 1, position.y})
    #define ATTACK_BUTTON_SCALE ((sfVector2f) {270, 70})
    #define ATTACK_ANIM_COLOR ((sfColor) {73, 149, 227, 255})
    #define ATTACK_ANIM_POSITION ((sfVector2f) {536, 700})
    #define ATTACKS_WIN_TITLE "Victoire !"
    #define ATTACKS_WIN_DESCRIPTION "Vous venez de gagner le combat."

#endif /* !EVENTS_TYPES_H_ */
