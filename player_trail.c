/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

player_trail_t *create_player_trail(sfTexture *texture, sfVector2f pos)
{
    float alpha = 1;
    player_trail_t *object = malloc(sizeof(player_trail_t) * 10);

    for (int i = 0; i < 10; i++) {
        object[i].sprite = sfSprite_create();
        object[i].texture = texture;
        sfSprite_setTexture(object[i].sprite, object[i].texture, sfTrue);
        object[i].pos.x = pos.x;
        object[i].pos.y = pos.y;
        object[i].rect = (sfIntRect) {0, 0, 128, 128};
        object[i].color = (sfColor) {255, 255, 255, 255 * alpha};
        alpha -= 0.1;
    }
    return (object);
}

void update_player_trail(player_t p, sfRenderWindow *win)
{
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pos;

    for (int i = 9; i > -1; i--) {
        pos.x = 400 - 10 * i;
        p.trail[i].pos.y = i == 0 ? p.pos.y : p.trail[i - 1].pos.y;
        p.trail[i].rect.left = i == 0 ? p.rect.left : p.trail[i - 1].rect.left;
        sfSprite_setColor(p.trail[i].sprite, p.trail[i].color);
        sfSprite_setTextureRect(p.trail[i].sprite, p.trail[i].rect);
        sfSprite_setPosition(p.trail[i].sprite, \
        (sfVector2f) {pos.x, p.trail[i].pos.y});
        sfSprite_setScale(p.trail[i].sprite, scale);
        sfRenderWindow_drawSprite(win, p.trail[i].sprite, \
        blend_mode(p.trail[i].texture));
    }
}
