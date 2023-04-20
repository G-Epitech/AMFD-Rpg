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
    #define INVENTORY_ACTIVE_GRID_POS ((sfVector2f) {334.0, 734.0})
    #define INVENTORY_ACTIVE_GRID_SIZE ((sfVector2i) {3, 2})
    #define INVENTORY_ACTIVE_GRID_ITEM_SIZE 85
    #define INVENTORY_ACTIVE_GRID_MARGIN ((sfVector2f) {20.0, 20.0})
    #define INVENTORY_GRID_ITEM_INACTIVE_RECT ((sfIntRect) {0, 0, 85, 85})
    #define INVENTORY_GRID_ITEM_ACTIVE_RECT ((sfIntRect) {85, 0, 85, 85})
    #define INVENTORY_GRID_ITEM_CONSUMABLE_RECT ((sfIntRect) {170, 0, 85, 85})
    #define INVENTORY_GRID_ITEM_SELECTED_RECT ((sfIntRect) {255, 0, 85, 85})
    #define INVENTORY_PROFILE_POS ((sfVector2f) {349, 309})
    #define INVENTORY_PROFILE_SIZE ((sfVector2f) {267, 356})
    #define INVENTORY_MAX 18
    #define INVENTORY_LEVEL_LABEL_POS ((sfVector2f) {1540, 794})
    #define INVENTORY_LIFE_LABEL_POS ((sfVector2f) {1540, 905})
    #define INVENTORY_INTELLIGENCE_LABEL_POS ((sfVector2f) {1111, 794})
    #define INVENTORY_SPEED_LABEL_POS ((sfVector2f) {1111, 902})

typedef struct s_item item_t;

typedef struct s_inventory_item {
    item_t *target;
    bool active;
    int pos;
} inventory_item_t;

typedef struct s_inventory_move {
    bool pressed;
    bool moved;
    sfVector2f pressed_on;
    sfVector2f position;
    inventory_item_t *selected;
    inventory_item_t target;
    inventory_item_t *target_ref;
    inventory_item_t target_ref_tmp;
} inventory_event_t;

#endif /* !INVENTORY_TYPES_H_ */
