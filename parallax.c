/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** parralax function
*/

#include "include/function.h"

gameobject_t create_parralax(char *p, sfVector2f o, sfIntRect r, parralax_t t)
{
    gameobject_t object;
    sfSprite *sp = sfSprite_create();
    object.type = t;
    object.sprite = sfSprite_create();
    object.texture = sfTexture_createFromFile(p, NULL);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.pos.x = o.x;
    object.pos.y = o.y;
    object.rectangle.top = r.top;
    object.rectangle.left = r.left;
    object.rectangle.width = r.width;
    object.rectangle.height = r.height;
    sfSprite_destroy(sp);
    return (object);
}

void render_parralax(gameobject_t object, sfRenderWindow *win)
{
    sfVector2f scale = {0, 0};
    sfVector2u sc = sfTexture_getSize(object.texture);
    scale.x = (float) 1920 / sc.x;
    scale.y = (float) 1080 / sc.y;
    sfSprite_setScale(object.sprite, scale);
    sfSprite_setPosition(object.sprite, object.pos);
    sfRenderWindow_drawSprite(win, object.sprite, blend_mode(object.texture));
}

gameobject_t update_parralax(gameobject_t object)
{

    if (object.type == FRONT)
        object.pos.x -= 1920 / 500;
    if (object.type == MIDDLE)
        object.pos.x -= 1920 / 1000;
    if (object.type == BACK)
        object.pos.x -= 1920 / 5000;
    if (object.pos.x <= -1920)
        object.pos.x = 1920;
    return (object);
}

gameobject_t *init_parralax(void)
{
    gameobject_t *object = malloc(sizeof(*object) * 6);
    sfVector2f pos = {0.0, 0.0};
    sfVector2f backpos = {1920.0, 0.0};
    sfIntRect rect = {0, 0, 8, 8};

    object[0] = create_parralax("res/back.png", pos, rect, BACK);
    object[1] = create_parralax("res/back.png", backpos, rect, BACK);
    object[2] = create_parralax("res/mid.png", pos, rect, MIDDLE);
    object[3] = create_parralax("res/mid.png", backpos, rect, MIDDLE);
    object[4] = create_parralax("res/front.png", pos, rect, FRONT);
    object[5] = create_parralax("res/front.png", backpos, rect, FRONT);
    return (object);
}

gameobject_t *parra_update(gameobject_t *o, sfRenderWindow *w, player_t p)
{
    for (int i = 0; i < 6; i++) {
        render_parralax(o[i], w);
        if (!p.dead)
            o[i] = update_parralax(o[i]);
    }
    return (o);
}
