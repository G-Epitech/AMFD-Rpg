/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Types for animation of the player
*/

#ifndef TYPE_H_
    #define TYPE_H_

    #include <SFML/Graphics.h>

    #define ANIMATION_CONFIG "configs/animation.json"

typedef enum e_entity_state enitity_state_t;

typedef struct s_animation {
    char *title;            //Title of animation
    int skin_id;            //Skin id
    enitity_state_t state;  //State when animation will play
    int curr_frame;         //Current frame of the animation
    int frames_len;         //Number of frames
    sfIntRect rect;         //Animation rect
} animation_t;

#endif /* !TYPE_H_ */
