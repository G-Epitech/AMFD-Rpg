/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** saving
*/

#ifndef TYPES_SAVING_H_
    #define TYPES_SAVING_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>

    #define SAVING_TEMPLATE "configs/game.json"

typedef struct s_renderer renderer_t;

typedef struct s_saver {
    bool close_window;
    sfRenderWindow *window;
    renderer_t *renderer;
} saver_t;

#endif /* !TYPES_SAVING_H_ */
