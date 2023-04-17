/*
** EPITECH PROJECT, 2023
** sound.h
** File description:
** Soundboard functions
*/

#ifndef SOUND_H_
    #define SOUND_H_

    #include "types.h"

/**
 * @brief Loads the list of sounds_fx
 * @return List of sounds
*/
list_t *sound_fx_load(void);

/**
 * @brief Loads the list of themes
 * @return List of themes
*/
list_t *sound_themes_load(void);

/**
 * @brief Loads the entirety of the soundboard
 * @return Soundboard
*/
sound_board_t *load_sound_board(void);

#endif /* !SOUND_H_ */
