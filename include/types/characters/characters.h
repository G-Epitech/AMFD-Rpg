/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** character
*/

#ifndef CHARACTER_H_
    #define CHARACTER_H_

    #include <SFML/Graphics.h>
    #include "types/characters/types.h"
    #include "types/renderer/renderer.h"
    #include "types/ressources/ressources.h"

/**
 * @brief Get rect given orientation
 * @param orientation Orientation to apply to skin
 * @return Computed rect
 */
sfIntRect character_get_rect(skin_orientation_t orientation);

#endif /* !CHARACTER_H_ */
