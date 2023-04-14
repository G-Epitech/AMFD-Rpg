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
 * @param sound_board List of sounds
 * @param sound_effect Sound you want to control
 * Current sounds:
 * WALK: walking sound
 * CLICK_MENU: menu button click
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

#endif /* !SOUND_CONTROL_H_ */
