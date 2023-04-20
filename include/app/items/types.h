/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef ITEMS_TYPES_H_
    #define ITEMS_TYPES_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>

    #define ITEMS_CONFIG "configs/items.json"
    #define ITEM_SIZE ((sfVector2i) {46, 46})

typedef enum e_item_type {
    IVT_CONSUMABLE,
    IVT_EQUIPEMENT
} item_type_t;

typedef struct s_item {
    item_type_t type;
    unsigned int id;
    char *label;
    int xp;
    int life;
    int speed;
    int intelligence;
    float price;
    sfIntRect rect;
} item_t;

#endif /* !ITEMS_TYPES_H_ */
