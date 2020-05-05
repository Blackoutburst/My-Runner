/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map loader function
*/

#include "include/function.h"

sfIntRect blue_tile(sfIntRect rect, char *name)
{
    if (name[0] == 'b' && name[4] == '\0')
        rect.top = 0 * 64;
    if (name[0] == 'b' && name[5] == 'l')
        rect.top = 1 * 64;
    if (name[0] == 'b' && name[5] == 'm')
        rect.top = 2 * 64;
    if (name[0] == 'b' && name[5] == 'r')
        rect.top = 3 * 64;
    return (rect);
}

sfIntRect green_tile(sfIntRect rect, char *name)
{
    if (name[0] == 'g' && name[5] == '\0')
        rect.top = 4 * 64;
    if (name[0] == 'g' && name[6] == 'l')
        rect.top = 5 * 64;
    if (name[0] == 'g' && name[6] == 'm')
        rect.top = 6 * 64;
    if (name[0] == 'g' && name[6] == 'r')
        rect.top = 7 * 64;
    return (rect);
}

sfIntRect red_tile(sfIntRect rect, char *name)
{
    if (name[0] == 'r' && name[3] == '\0')
        rect.top = 8 * 64;
    if (name[0] == 'r' && name[4] == 'l')
        rect.top = 9 * 64;
    if (name[0] == 'r' && name[4] == 'm')
        rect.top = 10 * 64;
    if (name[0] == 'r' && name[4] == 'r')
        rect.top = 11 * 64;
    return (rect);
}
