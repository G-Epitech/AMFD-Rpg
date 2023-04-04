/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Types for the loading
*/

#ifndef TYPES_H_
    #define TYPES_H_

    #include <SFML/Graphics.h>

    #define LOGO_PATH "assets/loading_screen/logo_groupe.png"

typedef struct s_loading {
    sfTexture *company_screen;
    sfTexture *game_loading_screen;
} loading_t;

#endif /* !TYPES_H_ */
