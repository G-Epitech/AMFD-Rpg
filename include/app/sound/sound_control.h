/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Sound control functions
*/

#ifndef SOUND_CONTROL_H_
    #define SOUND_CONTROL_H_

    #include "types.h"

/**
 * @brief Allows you to control game sound
 * @param sound_board Type of sound you want to control
 * @param sound_effect Sound you want to control
 * Current sounds:
 * WALK: walking sound
 * CLICK_MENU: menu button click
 * MENU_THEME: the music of the menu
 * @param new_sound_status Sets the new status of the sound
 * sfPlaying: Start playing the sound.\n
 * sfPaused: Pause the sound.\n
 * sfStopped: Stop playing the sound.\n
*/
void sound_control(list_t *sound_board, int sound_effect,
sfSoundStatus new_sound_status);

/**
 * @brief Plays one time sound
 * @param sound_board Sound list
 * @param sound_index Sound to play using enum
*/
void play_sound(list_t *sound_board, int sound_index);

/**
 * @brief Function working with core to handle
 * sound effects
 * @param sound_fx List of sound effects
*/
void handle_sound_effects(list_t *sound_fx);

/**
 * @brief Function working with core to handle
 * sound themes
 * @param theme_list List of sound themes 
 * @param app_state Current state of the app
*/
void handle_sound_themes(list_t *theme_list, app_states_t app_state);

/**
 * @brief Function working with core to handle
 * app volume
 * @param app_volume App volume
 * @param sound_board Soundboard
*/
void handle_sound_volume(float app_volume, sound_board_t *sound_board);

#endif /* !SOUND_CONTROL_H_ */
