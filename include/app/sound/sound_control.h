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
 * @param sound_index Sound you want to control
 * Current sounds:
 * WALK: walking sound
 * @param new_sound_status Sets the new status of the sound
 * sfPlaying: Start playing the sound.
 * sfPaused: Pause the sound.
 * sfStopped: Stop playing the sound.
*/
void sound_control(list_t *sound_board, int sound_index,
sfSoundStatus new_sound_status);

#endif /* !SOUND_CONTROL_H_ */
