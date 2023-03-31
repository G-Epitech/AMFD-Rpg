/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** file
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

off_t internal_cjson_file_get_size(char *filepath)
{
    struct stat target;

    if (stat(filepath, &target) != 0)
        return -1;
    return target.st_size;
}
