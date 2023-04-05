/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef CHARACTER_TYPES_H_
    #define CHARACTER_TYPES_H_

    #include <SFML/Graphics.h>

typedef enum e_skin_orientation {
    SO_RIGHT,
    SO_BACK,
    SO_LEFT,
    SO_FACE,
    SO_LEN
} skin_orientation_t;

static const sfVector2i skin_orientations[SO_LEN] = {
    [SO_RIGHT] = {0, 0},
    [SO_BACK] = {1, 0},
    [SO_LEFT] = {2, 0},
    [SO_FACE] = {3, 0}
};

#endif /* !CHARACTER_TYPES_H_ */
