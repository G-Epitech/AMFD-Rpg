/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialog_box
*/

#ifndef DIALOG_BOX_TYPES_H_
    #define DIALOG_BOX_TYPES_H_

    #include <stdbool.h>

    #define DIALOG_BOX_DEF_OPT1 "Oui"
    #define DIALOG_BOX_DEF_OPT2 "Non"
    #define DIALOG_BOX_DEF_OPT3 "Annuler"
    #define DIALOG_BOX_POSITION ((sfVector2f) {0, 0})
    #define DIALOG_BOX_MESSAGE_POSITION ((sfVector2f) {411, 774})
    #define DIALOG_BOX_OPT1_POSITION ((sfVector2f) {1240, 786})
    #define DIALOG_BOX_OPT2_POSITION ((sfVector2f) {1240, 846})
    #define DIALOG_BOX_OPT3_POSITION ((sfVector2f) {1240, 906})
    #define DIALOG_BOX_ICON_MARGIN_TOP 4.5
    #define DIALOG_OPTION_POS_MARGIN(p) ((sfVector2f) {p.x + 30, p.y})
    #define DIALOG_BOX_INPUT_RECT_POSITION ((sfVector2f) {411, 891})
    #define DIALOG_BOX_INPUT_RECT_SIZE ((sfVector2f) {780, 56})
    #define DIALOG_BOX_INPUT_RECT_OUT_COLOR ((sfColor) {177, 138, 116, 255})
    #define DIALOG_BOX_INPUT_RECT_IN_COLOR ((sfColor) {195, 172, 144, 127})
    #define DIALOG_BOX_INPUT_RECT_OULTINE_SIZE 6
    #define DIALOG_BOX_INPUT_TEXT_SIZE 20
    #define DIALOG_BOX_INPUT_MAX_VISIBLE_LEN 37
    #define DIALOG_BOX_INPUT_TEXT_POSITION ((sfVector2f) {430, 908})

typedef struct s_app app_t;

typedef void (*dialog_box_callback_t)(app_t *app, char *input);

typedef enum e_dialog_box_mode {
    DGBOX_DIALOG,
    DGBOX_INPUT
} dialog_box_mode_t;

typedef struct s_dialog_box {
    dialog_box_mode_t mode;
    char *message;
    char *input;
    char *option1;
    char *option2;
    char *option3;
    int option;
    bool show;
    dialog_box_callback_t onoption1;
    dialog_box_callback_t onoption2;
    dialog_box_callback_t onoption3;
} dialog_box_t;

#endif /* !DIALOG_BOX_TYPES_H_ */
