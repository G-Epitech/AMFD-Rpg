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
    #define FONT_PATH "assets/fonts/Hella Instegra.ttf"
    #define TEXT_COLOR ((sfColor) {103, 81, 82, 255})
    #define BG_COLOR ((sfColor) {205, 190, 169, 255})
    #define LOAD_TEXTURE "assets/components/backgrounds/loading.png"
    #define BAR_TEXTURE "assets/components/backgrounds/bar.png"
    #define LOAD_POSITION ((sfVector2f) {795, 985})
    #define BRG_POSITION ((sfVector2f) {743, 194})
    #define BRG_TEXTURE "assets/components/backgrounds/bras_gauche.png"

typedef struct s_loading {
    sfTexture *company_screen;
    sfTexture *game_loading_screen;
} loading_t;

#endif /* !TYPES_H_ */
