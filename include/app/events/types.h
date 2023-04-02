/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Events types
*/

#ifndef EVENTS_TYPES_H_
    #define EVENTS_TYPES_H_

    #include <SFML/Graphics.h>

    #define POSITION_UP(position) ((sfVector2f) {position.x, position.y - 6})
    #define POSITION_DOWN(position) ((sfVector2f) {position.x, position.y + 6})
    #define POSITION_LEFT(position) ((sfVector2f) {position.x - 6, position.y})
    #define POSITION_RIGHT(position) ((sfVector2f)\
    {position.x + 6, position.y})

#endif /* !EVENTS_TYPES_H_ */
