/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** strncpy
*/

void internal_cjson_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i <= n) dest[i] = '\0';
}
