/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map loader function
*/

#include "include/function.h"

sfIntRect blue_pulse(sfIntRect rect, char *name)
{
    if (name[0] == 'p' && name[1] == 'b')
        rect.top = 12 * 64;
    if (name[0] == 'p' && name[1] == 'b')
        rect.left = 64 * (my_atoi(name) - 1);
    return (rect);
}

sfIntRect green_pulse(sfIntRect rect, char *name)
{
    if (name[0] == 'p' && name[1] == 'g')
        rect.top = 13 * 64;
    if (name[0] == 'p' && name[1] == 'g')
        rect.left = 64 * (my_atoi(name) - 1);
    return (rect);
}

sfIntRect red_pulse(sfIntRect rect, char *name)
{
    if (name[0] == 'p' && name[1] == 'r')
        rect.top = 14 * 64;
    if (name[0] == 'p' && name[1] == 'r')
        rect.left = 64 * (my_atoi(name) - 1);
    return (rect);
}
