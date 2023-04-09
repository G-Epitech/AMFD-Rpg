/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Display types
*/

#ifndef DISPLAY_TYPES_H_
    #define DISPLAY_TYPES_H_

    #define SIZE_UP(pos, scale) ((sfVector2f) {pos.x * scale, pos.y * scale})
    #define MIDDLE_POS(size, middle) ((sfVector2f)\
    {size.x + middle.x, middle.y})
    #define RIGHT_POS(size, middle, right, scale) ((sfVector2f)\
    {size.x + middle.x * scale+ right.x, right.y})
    #define GAME_TITLE "Hackers Quests"
    #define SETTINGS_TITLE "Settings"
    #define VOLUME_POSITION ((sfVector2f) {1153, 490})
    #define FPS_POSITION ((sfVector2f) {1142, 587})
    #define VALID_LUCAS ((sfVector2f) {642, 646})
    #define VALID_TOM ((sfVector2f) {1173, 646})

#endif /* !DISPLAY_TYPES_H_ */
