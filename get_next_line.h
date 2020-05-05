/*
** EPITECH PROJECT, 2019
** Get Next Line
** File description:
** Read size
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef READ_SIZE

#define READ_SIZE (1)

#endif

typedef struct restor {
    int index;
    char *buffer;
    char *line;
} restor_t;

char *get_next_line(int);
