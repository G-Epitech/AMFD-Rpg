/*
** EPITECH PROJECT, 2023
** app.h
** File description:
** App functions
*/

#ifndef APP_H_
    #define APP_H_

    #include "app/types.h"
    #include "app/utils/utils.h"

/**
 * @brief Run rpg
 * @param renderer Main renderer function
 * @param app Application structure
*/
app_t *app_init(void);

int app_run(renderer_t *renderer, app_t *app);

#endif /* !APP_H_ */
