/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

player_t animate_player(player_t p)
{
    float seconds;
    static int x;
    sfTime time;

    time = sfClock_getElapsedTime(p.clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.01) {
        x += p.inverted ? -1 : 1;
        if (x > 35)
        x = 0;
        if (x < 0)
            x = 35;
        sfClock_restart(p.clock);
    }
    p.rect.left = 128 * x;
    return (p);
}

game_t player_updater(game_t p, tile_t *tile, int tn, sfRenderWindow *win)
{
    sfVector2f scale = {0.5, 0.5};

    p.player = kill_player(tile, tn, p.player, p);
    p.player = kill_player_inv(tile, tn, p.player, p);
    if (!p.player.dead) {
        p.player = animate_player(p.player);
        sfSprite_setTextureRect(p.player.sprite, p.player.rect);
        p.player = update_player(p.player, tile, tn);
        sfSprite_setPosition(p.player.sprite, p.player.pos);
        update_player_trail(p.player, win);
    }
    sfSprite_setScale(p.player.sprite, scale);
    sfRenderWindow_drawSprite(win, p.player.sprite, \
    blend_mode(p.player.texture));
    return (p);
}

player_t create_player(const char *path, sfVector2f pos)
{
    player_t object;

    object.sprite = sfSprite_create();
    object.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.pos.x = pos.x;
    object.pos.y = pos.y;
    object.dead = 0;
    object.inverted = 0;
    object.spe_g = 0;
    object.jumpStrength = 0;
    object.ground = 0;
    object.rect = (sfIntRect) {0, 0, 128, 128};
    object.clock = sfClock_create();
    object.trail = create_player_trail(object.texture, pos);
    return (object);
}

player_t player_input(player_t p)
{
    if ((sfKeyboard_isKeyPressed(sfKeySpace) || \
    sfKeyboard_isKeyPressed(sfKeyUp)) && p.ground && !p.spe_g) {
        p.jumpStrength = 32;
        p.ground = 0;
    }
    if ((sfKeyboard_isKeyPressed(sfKeySpace) || \
    sfKeyboard_isKeyPressed(sfKeyUp)) && p.ground && p.spe_g) {
        p.inverted = p.inverted ? 0 : 1;
    }
    return (p);
}

player_t update_player(player_t p, tile_t *tile, int tiles_number)
{
    static float weight = 2.5f;

    p = player_input(p);
    if (!p.inverted) {
        if (!p.ground) {
            p.pos.y -= p.jumpStrength;
            p.jumpStrength -= weight;
        }
    } else {
        p.pos.y += p.jumpStrength;
        p.jumpStrength -= weight;
    }
        if (p.ground)
            p.jumpStrength = 0;
    p.ground = 0;
    p = on_ground(p, tile, tiles_number);
    p = on_ground_inv(p, tile, tiles_number);
    return (p);
}
