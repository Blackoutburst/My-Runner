/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** parralax function
*/

#include "include/function.h"

button_t create_button(char *p, sfVector2f o, int scene)
{
    button_t object;

    object.sprite = sfSprite_create();
    object.texture = sfTexture_createFromFile(p, NULL);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.pos.x = o.x;
    object.pos.y = o.y;
    object.hover = 0;
    object.rectangle = (sfIntRect) {0, 0, 512, 512};
    object.down = 1;
    object.original_scene = scene;
    object.scene = 0;
    return (object);
}

button_t update_button(button_t object, sfRenderWindow *win, int actual_scene)
{
    sfVector2i m_pos = {0, 0};

    object.scene = actual_scene;
    m_pos = sfMouse_getPositionRenderWindow(win);

    if (m_pos.x >= object.pos.x && m_pos.x <= object.pos.x + 512 && \
    m_pos.y >= object.pos.y && m_pos.y <= object.pos.y + 512)
        object.hover = 1;
    else
        object.hover = 0;
    if (object.hover && sfMouse_isButtonPressed(sfMouseLeft) && !object.down)
        object.scene = object.original_scene;
    object.down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    object = render_button(object, win);
    return (object);
}

button_t render_button(button_t object, sfRenderWindow *win)
{
    object.rectangle.top = object.hover ? 512 : 0;
    sfSprite_setTextureRect(object.sprite, object.rectangle);
    sfSprite_setPosition(object.sprite, object.pos);
    sfRenderWindow_drawSprite(win, object.sprite, blend_mode(object.texture));
    return (object);
}
