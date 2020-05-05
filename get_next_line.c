/*
** EPITECH PROJECT, 2019
** Get Next Line
** File description:
** All function
*/

#include "get_next_line.h"

int error(int fd)
{
    if (READ_SIZE < 1)
        return (1);
    if (fd == -1)
        return (1);
    return (0);
}

char *init_buffer(char *buffer)
{
    buffer = malloc(sizeof(*buffer) * 10000);
    for (int j = 0; j < 10000; j++)
        buffer[j] = 0;
    return (buffer);
}

restor_t restore_line(restor_t rest)
{
    int begin = 0;

    for (int j = 0; rest.buffer[j]; j) {
        if (rest.buffer[j] == '\n' && begin) {
            rest.index = -1;
            return (rest);
        }
        if (begin) {
            rest.line[rest.index++] = rest.buffer[j];
            j++;
        } else
            *rest.buffer++;
        if (rest.buffer[j] == '\n' && !begin) {
            begin = 1;
            *rest.buffer++;
        }
    }
    return (rest);
}

char *increment_line(char *line, char *buffer, int index, int fd)
{
    static int tru = 1;

    if (read(fd, buffer, READ_SIZE) <= 0) {
        return (NULL);
    }
    for (int j = 0; buffer[j]; j++) {
        if (buffer[j] == '\n')
            tru = 0;
        if (tru)
            line[index++] = buffer[j];
    }
    if (tru)
        return (increment_line(line, buffer, index, fd));
    tru = 1;
    return (line);
}

char *get_next_line(int fd)
{
    static int init = 0;
    static char *buffer;
    char *line = malloc(sizeof(*line) * 10000);
    restor_t rest;

    if (error(fd))
        return (NULL);
    if (!init++)
        buffer = init_buffer(buffer);
    for (int j = 0; j < 10000; j++)
        line[j] = 0;
    rest.index = 0;
    rest.buffer = buffer;
    rest.line = line;
    rest = restore_line(rest);
    buffer = rest.buffer;
    if (rest.index == -1)
        return (rest.line);
    return (increment_line(rest.line, buffer, rest.index, fd));
}
