/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Display types
*/

#ifndef DISPLAY_TYPES_H_
    #define DISPLAY_TYPES_H_

    #define SIZE_UP(pos, scale) ((sfVector2f) {pos.x * scale, pos.y * scale})
    #define MIDDLE_POS(size, middle) ((sfVector2f)\
    {size.x + middle.x, middle.y})
    #define RIGHT_POS(size, middle, right, scale) ((sfVector2f)\
    {size.x + middle.x * scale+ right.x, right.y})
    #define MAIN_COLOR ((sfColor) {107, 80, 82, 255})
    #define TEXT_DEFAULT_COLOR ((sfColor) {107, 80, 82, 255})
    #define TEXT_SELECT_COLOR ((sfColor) {218, 164, 99, 255})
    #define TEXT_LOCK_COLOR ((sfColor) {58, 58, 80, 255})
    #define GAME_TITLE "Hackers Quests"
    #define SETTINGS_TITLE "Settings"
    #define VOLUME_POSITION ((sfVector2f) {1153, 490})
    #define FPS_POSITION ((sfVector2f) {1142, 587})
    #define VALID_LUCAS ((sfVector2f) {642, 646})
    #define VALID_TOM ((sfVector2f) {1173, 646})
    #define REFUSE_LUCAS ((sfVector2f) {653, 649})
    #define REFUSE_TOM ((sfVector2f) {1184, 649})
    #define FIGHT_CHOICE_TITLE " veut se battre !"
    #define FIGHT_CHOICE_TITLE_POSITION ((sfVector2f) {526, 810})
    #define FIGHT_CHOICE_RESPONSIVE ((sfVector2f) {1156, 862})
    #define FIGHT_CHOICE_RATIO 60
    #define FIGHT_CHOICE_ICON_X 27
    #define FIGHT_CHOICE_ICON_Y 5
    #define FIGHT_CHOICE_CONFIG "configs/fight/choice.json"
    #define FIGHT_ATTACK_RATIO ((sfVector2f) {176, 27})
    #define INTERACTION_ICON_POSITION ((sfVector2f) {704, 700})
    #define DIALOGS_TITLE_POSITION ((sfVector2f) {537, 813})
    #define DIALOGS_CONTENT_POSITION ((sfVector2f) {537, 879})
    #define DIALOGS_ICON_POSITION ((sfVector2f) {1382, 942})
    #define QUESTS_CONTENT_POS ((sfVector2f) {100, 212})
    #define QUESTS_TITLE_POS ((sfVector2f) {100, 164})
    #define QUESTS_TITLE_POS_UP ((sfVector2f) {100, 176})

#endif /* !DISPLAY_TYPES_H_ */
