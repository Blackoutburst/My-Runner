/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** File reader
*/

#include "include/function.h"

char *read_map(char *filepath)
{
    struct stat st;
    int size = 0;
    int file;
    stat(filepath, &st);
    size = st.st_size;
    char *buffer = malloc(sizeof(char) * size + 1);

    buffer[size] = '\0';
    file = open(filepath, O_RDONLY);
    read(file, buffer, size);
    close(file);
    return (buffer);
}

int count_lines(char *buffer)
{
    int lines = 0;

    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '\n')
            lines++;
    return (lines);
}
