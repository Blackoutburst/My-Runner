/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void run_song(sfSound *song)
{
    sfSound_play(song);
}

void pause_song(sfSound *song)
{
    sfSound_pause(song);
}

void stop_song(sfSound *song)
{
    sfSound_stop(song);
}

void loop_song(sfSound *song)
{
    sfSound_setLoop(song, sfTrue);
}
