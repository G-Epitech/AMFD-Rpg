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
    #define DIALOG_BOX_MESSAGE_POSITION ((sfVector2f) {467, 812})
    #define DIALOG_BOX_OPT1_POSITION ((sfVector2f) {1152, 812})
    #define DIALOG_BOX_OPT2_POSITION ((sfVector2f) {1152, 867})
    #define DIALOG_BOX_OPT3_POSITION ((sfVector2f) {1152, 923})
    #define DIALOG_BOX_ICON_MARGIN_TOP 4.5
    #define DIALOG_OPTION_POS_MARGIN(p) ((sfVector2f) {p.x + 30, p.y})

typedef struct s_app app_t;

typedef void (*dialog_box_callback_t)(app_t *app);

typedef struct s_dialog_box {
    char *message;
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
