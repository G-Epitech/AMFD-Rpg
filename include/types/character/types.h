/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef CHARACTER_TYPES_H_
    #define CHARACTER_TYPES_H_
    
    #include <SFML/Graphics.h>

typedef enum e_character_orientation {
    CO_RIGHT,
    CO_BACK,
    CO_LEFT,
    CO_FACE,
    CO_LEN
} character_orientation_t;

static const sfVector2f character_orientations[CO_LEN] = {
    [CO_RIGHT] = {0, 0},
    [CO_BACK] = {1, 0},
    [CO_LEFT] = {2, 0},
    [CO_FACE] = {3, 0}
};

#endif /* !CHARACTER_TYPES_H_ */
