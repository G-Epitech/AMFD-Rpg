/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialog_box
*/

#ifndef DIALOG_BOX_H_
    #define DIALOG_BOX_H_

    #include "types.h"

/**
 * @brief Create a new dialog box
 * @return Created dialog box
 */
dialog_box_t *dialog_box_new(void);

/**
 * @brief Free given dialog box
 * @param dialog_box Dialog box to free
 */
void dialog_box_free(dialog_box_t *dialog_box);

/**
 * @brief Set option 1 of dialog box
 * @param dialog_box Dialog box
 * @param option Option to set
 */
void dialog_box_set_option1(dialog_box_t *dialog_box, char *option);

/**
 * @brief Set option 2 of dialog box
 * @param dialog_box Dialog box
 * @param option Option to set
 */
void dialog_box_set_option2(dialog_box_t *dialog_box, char *option);

/**
 * @brief Set option 3 of dialog box
 * @param dialog_box Dialog box
 * @param option Option to set
 */
void dialog_box_set_option3(dialog_box_t *dialog_box, char *option);

/**
 * @brief Set message of dialog box
 * @param dialog_box Dialog box
 * @param message Message to set
 */
void dialog_box_set_message(dialog_box_t *dialog_box, char *message);

/**
 * @brief On valid option event
 * @param dialog_box Dialog box to handle
 * @param app App object to bind to callback
 */
void dialog_box_onvalid(dialog_box_t *dialog_box, app_t *app);

#endif /* !DIALOG_BOX_H_ */
