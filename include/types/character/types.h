/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef CHARACTER_TYPES_H_
    #define CHARACTER_TYPES_H_

    #include <SFML/Graphics.h>

    #define LUCAS_POSITION 524
    #define TOM_POSITION 1055

typedef enum e_skin_textures {
    STX_LUCAS = 4,
    STX_TOM = 5
} skin_textures_t;

typedef enum e_skin_orientation {
    SO_RIGHT,
    SO_BACK,
    SO_LEFT,
    SO_FACE,
    SO_LEN
} skin_orientation_t;

typedef struct s_skin_config {
    unsigned int x;
    unsigned int y;
    unsigned int weight;
} skin_config_t;

static const skin_config_t skin_configs[SO_LEN] = {
    [SO_RIGHT] = {0, 0, 1},
    [SO_BACK] = {1, 0, 1},
    [SO_LEFT] = {2, 0, 1},
    [SO_FACE] = {3, 0, 1}
};

#endif /* !CHARACTER_TYPES_H_ */
