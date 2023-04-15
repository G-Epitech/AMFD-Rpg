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

#endif /* !EVENTS_TYPES_H_ */
