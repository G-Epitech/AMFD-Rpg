/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef INVENTORY_TYPES_H_
    #define INVENTORY_TYPES_H_

    #define INVENTORY_MAIN_GRID_POS ((sfVector2f) {759.0, 266.0})
    #define INVENTORY_MAIN_GRID_SIZE ((sfVector2i) {6, 3})
    #define INVENTORY_MAIN_GRID_ITEM_SIZE 130
    #define INVENTORY_MAIN_GRID_MARGIN ((sfVector2f) {16.2, 13.0})
    #define INVENTORY_ACTIVE_GRID_POS ((sfVector2f) {324.0, 734.0})
    #define INVENTORY_ACTIVE_GRID_SIZE ((sfVector2i) {3, 2})
    #define INVENTORY_ACTIVE_GRID_ITEM_SIZE 85
    #define INVENTORY_ACTIVE_GRID_MARGIN ((sfVector2f) {32.0, 20.0})
    #define INVENTORY_GRID_ITEM_INACTIVE_RECT ((sfIntRect) {0, 0, 85, 85})
    #define INVENTORY_GRID_ITEM_ACTIVE_RECT ((sfIntRect) {85, 0, 85, 85})
    #define INVENTORY_GRID_ITEM_CONSUMABLE_RECT ((sfIntRect) {170, 0, 85, 85})
    #define INVENTORY_GRID_ITEM_SELECTED_RECT ((sfIntRect) {255, 0, 85, 85})
    #define INVENTORY_PROFILE_POS ((sfVector2f) {349, 309})
    #define INVENTORY_PROFILE_SIZE ((sfVector2f) {267, 356})

#endif /* !INVENTORY_TYPES_H_ */
