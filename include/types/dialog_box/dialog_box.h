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

/**
 * @brief Add given char to current dialog box input
 * @param dialog_box Dialog box of which add char to input
 * @param c Char to add to input
 */
void dialog_box_add_input_char(dialog_box_t *dialog_box, char c);

/**
 * @brief Remove last char of given dialog box input
 * @param dialog_box Dialog box
 */
void dialog_box_remove_input_char(dialog_box_t *dialog_box);

/**
 * @brief Set input to display in dialog_box
 * @param dialog_box Dialog box
 * @param input Input to set to diaog box
 */
void dialog_box_set_input(dialog_box_t *dialog_box, char *input);

/**
 * @brief Get input typed by user in dialog box
 * @param dialog_box Dialog box of which get input
 * @return Input of dialog box
 */
char *dialog_box_get_input(dialog_box_t *dialog_box);

/**
 * @brief Reset event handler of given dialog box
 * @param dialog_box Dialog box of which reset events
 * @param reset_after Specify if after functions have to been reset
 */
void dialog_box_reset_events(dialog_box_t *dialog_box, bool rester_after);

#endif /* !DIALOG_BOX_H_ */
