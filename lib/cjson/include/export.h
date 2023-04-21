/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** export
*/

#ifndef CJSON_EXPORT_H_
    #define CJSON_EXPORT_H_

    #include "types.h"

/**
 * @brief Export given CJSON object or element to file
 * @param cjson CJSON element to export
 * @param filepath Path of file in which export data to JSON
 * @return Status of exportation success
 */
bool cjson_export_to_file(cjson_t *cjson, char *filepath);

/**
 * @brief Export given CJSON object or element to file
 * @param cjson CJSON element to export
 * @param filepath Path of file in which export data to JSON
 * @param flags Flags to use in file creation. Takes same flags than
 * write function.
 * @param mode Mode to use in file creation. Takes same mode than
 * write function.
 * @return Status of exportation success
 */
bool cjson_export_to_file_with_options(cjson_t *cjson, char *filepath,
int flags, mode_t mode);

#endif /* !CJSON_EXPORT_H_ */
