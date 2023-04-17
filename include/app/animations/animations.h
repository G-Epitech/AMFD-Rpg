/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_

    #include <SFML/Graphics.h>
    #include "app/animations/types.h"

typedef struct s_renderer renderer_t;
typedef struct s_app app_t;
typedef struct s_list list_t;

/**
 * @brief Animation handler
 * @param renderer Renderer object
 * @param app App object
 */
void animations_handler(renderer_t *renderer, app_t *app);

/**
 * @brief Add new animation event group
 * @param app App object
 * @return list_t* List of events
 */
list_t *animation_event_new(app_t *app);

/**
 * @brief Screen zoom animation
 * @param zoom Data of the animation event
 * @param clock Clock of animations
 * @return If the animation is ended
 */
bool animations_screen_zoom(animation_event_zoom_t *zoom, sfClock *clock);

/**
 * @brief Add new zoom animation
 * @param events Group of animations
 * @param view 
 * @param speed 
 * @param zoom 
 */
void animations_screen_zoom_add(list_t *events, sfView *view, float speed,
float zoom);

/**
 * @brief Init zoom event data
 * @return animation_event_zoom_t* Zoom event data
 */
animation_event_zoom_t *animations_screen_zoom_init(void);

/**
 * @brief Init new shake attack animations
 * @return animation_event_zoom_t* The new structure
 */
animation_event_shake_attack_t *animations_shake_attack_init(void);

/**
 * @brief Add a new shake attacks to events list
 * @param events Event list
 * @param attack Attack structure (data)
 */
void animations_shake_attack_add(list_t *events, attack_t *attack);

/**
 * @brief Shake attack button animation
 * @param shake Animation structure
 * @param clock Clock of animations
 */
bool animations_shake_attack(animation_event_shake_attack_t *shake,
sfClock *clock);

/**
 * @brief Init new floating text animation
 * @return animation_event_floating_text_t* Structure of the animation
 */
animation_event_floating_text_t *animations_floting_text_init(void);

/**
 * @brief Add new floating text animation
 * @param events Events list of animations
 * @param color Color of the text
 * @param position Position of the text
 * @param content Content of the text
 */
void animations_floating_text_add(list_t *events, sfColor color,
sfVector2f position, char *content);

/**
 * @brief Floating text animation
 * @param text Text structure
 * @param clock Clock of animations
 */
bool animations_floating_text(animation_event_floating_text_t *text,
sfClock *clock);

/**
 * @brief Init notif animation
 * @return animation_event_notif_t* Structure of the animation
 */
animation_event_notif_t *animations_notif_init(void);

/**
 * @brief Add new notif animation
 * @param events Events list of animations
 * @param icon Icon of notif
 * @param title Title of notification
 * @param description Description of notification
 */
void animations_notif_add(list_t *events, sfTexture *icon, char *title,
char *description);

/**
 * @brief Notification animation
 * @param notif Notification structure
 * @param clock Clock of animation
 */
bool animations_notif(animation_event_notif_t *notif, sfClock *clock);
#endif /* !ANIMATIONS_H_ */
