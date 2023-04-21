/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** parse
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "cjson.h"
#include "internal/error.h"
#include "internal/stringify.h"

static bool open_file(char *filepath, int *fd, int flags, mode_t mode)
{
    *fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC | flags, mode);
    if (*fd == -1) {
        internal_cjson_error("unable to create expected file.", NULL);
        return false;
    }
    return true;
}

static bool write_in_file(cjson_t *cjson, int fd)
{
    size_t size = 0;
    char *stringified = cjson_stringify(cjson, &size);

    if (!stringified)
        return false;
    write(fd, stringified, size);
    write(fd, "\n", 1);
    free(stringified);
    return true;
}

bool cjson_export_to_file_with_options(cjson_t *cjson, char *filepath,
int flags, mode_t mode)
{
    int fd = 0;

    if (!open_file(filepath, &fd, flags, mode))
        return false;
    if (!write_in_file(cjson, fd))
        return false;
    close(fd);
    return true;
}

bool cjson_export_to_file(cjson_t *cjson, char *filepath)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH;

    return cjson_export_to_file_with_options(cjson, filepath, 0, mode);
}
