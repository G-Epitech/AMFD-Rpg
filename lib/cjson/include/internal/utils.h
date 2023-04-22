/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** utils
*/

#ifndef CJSON_INTERNAL_UTILS_H_
    #define CJSON_INTERNAL_UTILS_H_

    #include <sys/types.h>
    #include "types.h"

    #define CJSON_INTERNAL_BLANKS " \t\r\n"
    #define CJSON_INTERNAL_EOFIELD(c) ( c == ',' || c == '\t' || \
c == ' ' || c == '\r' || c == '\n' )
    #define CJSON_INTERNAL_EONUM(c) ( c == '}' || c == ']' || \
CJSON_INTERNAL_EOFIELD(c) )
    #define CJSON_INTERNAL_ISNUM(c) (c >= '0' && c <= '9')
    #define CJSON_INTERNAL_NUM(c) (c - '0')
    #define CJSON_INTERNAL_NUM_0 ((internal_cjson_number_t)\
                                    { false, false, 0, 0, 1 })
    #define CJSON_INTERNAL_IS_SPECIAL(c) (c == '\\' || c == '"' || c == '/' \
|| c == '\b' || c == '\f' || c == '\n' || c == '\r' || c == '\t')
    #define CJSON_INTERNAL_IS_ESC_SPECIAL(c) (c == '\\' || c == '"' \
|| c == '/' || c == 'b' || c == 'f' || c == 'n' || c == 'r' || c == 't')

/**
 * @brief Calculate the length of a string
 * @param s String of which get length
 * @return Number of bytes in the string pointed to by s
 */
size_t internal_cjson_strlen(const char *s);

/**
 * @brief Calculate the length of a string and adding backslashes
 * on special chars in length
 * @param s String of which get length
 * @return Number of bytes in the string pointed to by s
 */
size_t internal_cjson_strlen_with_specials(const char *s);

/**
 * @brief Duplicate given string
 * @param s String to duplicate
 * @return Duplicated string
 */
char *internal_cjson_strdup(const char *s);

/**
 * @brief Duplicate given string on n chars or size of s if n too large
 * @param s String to duplicate
 * @param n Number of bytes to duplicate
 * @return Duplicated string
 */
char *internal_cjson_strndup(const char *s, unsigned int n);

/**
 * @brief Check if given char is in given char collection
 * @param c Char to find
 * @param chars Char collection in which search
 * @return Status of searching
 */
bool internal_cjson_char_in_str(char c, char *chars);

/**
 * @brief Copy src in dest on n bytes
 * @param dest Destination
 * @param src Source
 * @param n Number of bytes to copy
 */
void internal_cjson_strncpy(char *dest, char const *src, int n);

/**
 * @brief Compare s1 to s2
 * @param s1 String 1
 * @param s2 String 2
 * @return Difference between s1 and s2
 */
int internal_cjson_strcmp(char const *s1, char const *s2);

/**
 * @brief Compare s1 to s2 on n bytes
 * @param s1 String 1
 * @param s2 String 2
 * @param n Number of bytes to compare
 * @return Difference between s1 and s2
 */
int internal_cjson_strncmp(char const *s1, char const *s2, unsigned int n);

#endif /* !CJSON_INTERNAL_UTILS_H_ */
