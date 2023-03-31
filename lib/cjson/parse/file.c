/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** parse
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "cjson.h"
#include "internal/error.h"
#include "internal/parsing.h"

static bool open_file(char *filepath, cjson_file_t *file)
{
    file->fd = open(filepath, O_RDONLY);
    if (file->fd == -1) {
        internal_cjson_error("unable to open given file.", NULL);
        return false;
    }
    return true;
}

static bool load_file(char *filepath, cjson_file_t *file)
{
    off_t size = internal_cjson_file_get_size(filepath);

    if (size < 0) {
        internal_cjson_error("error during file loading (get size).", NULL);
        return false;
    }
    file->content = malloc(size + 1);
    if (!file->content) {
        internal_cjson_error("error during file loading (malloc).", NULL);
        return false;
    }
    read(file->fd, file->content, size);
    file->content[size] = '\0';
    return true;
}

cjson_t *cjson_parse_file(char *filepath)
{
    cjson_file_t file = { NULL, 0 };
    cjson_t *cjson = NULL;

    if (!open_file(filepath, &file))
        return NULL;
    if (!load_file(filepath, &file))
        return NULL;
    close(file.fd);
    cjson = cjson_parse(file.content);
    free(file.content);
    return cjson;
}
