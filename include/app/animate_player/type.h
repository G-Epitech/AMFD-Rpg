/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Types for animation of the player
*/

#ifndef PLAYER_ANIM_TYPE_H_
    #define PLAYER_ANIM_TYPE_H_

    #include <SFML/Graphics.h>

    #define ANIMATION_CONFIG "configs/animation.json"

typedef enum e_entity_state enitity_state_t;
typedef enum e_skin_orientation skin_orientation_t;

typedef struct s_animation {
    char *title;                        //Title of animation
    char *file;
    int skin_id;                        //Skin id
    enitity_state_t state;              //State when animation will play
    int curr_frame;                     //Current frame of the animation
    int frames_len;                     //Number of frames
    sfIntRect rect;                     //Animation rect
} animation_t;

#endif /* !PLAYER_ANIM_TYPE_H_ */
