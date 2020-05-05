/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void destroy_parralax(gameobject_t obj)
{
    sfSprite_destroy(obj.sprite);
    sfTexture_destroy(obj.texture);
}
