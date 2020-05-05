/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

int animate_tile(int x, int drop)
{
    static sfClock *clock;
    static float seconds = 0;
    static sfTime time;
    static int init = 0;

    if (!init++)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.0001 && drop) {
        x -= 2;
        if (x < 0)
            x = 0;
        sfClock_restart(clock);
    }
    return (x);
}
