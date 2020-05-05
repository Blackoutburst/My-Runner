/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** parralax function
*/

#include "include/function.h"

title_t create_title(char *p, sfVector2f o)
{
    title_t object;
    object.sprite = sfSprite_create();
    object.texture = sfTexture_createFromFile(p, NULL);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.pos.x = o.x;
    object.pos.y = o.y;
    return (object);
}

void render_title(title_t object, sfRenderWindow *win)
{
    sfSprite_setPosition(object.sprite, object.pos);
    sfRenderWindow_drawSprite(win, object.sprite, blend_mode(object.texture));
}
