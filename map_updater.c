/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map updater function
*/

#include "include/function.h"

tile_t *update_map(int tn, tile_t *tile, player_t player)
{
    for (int i = 0; i < tn; i++) {
        if (!player.dead)
            tile[i].pos.x -= 10;
        sfSprite_setPosition(tile[i].sprite, tile[i].pos);
    }
    return (tile);
}

tile_t *update_color(int tn, tile_t *tile, game_t g)
{
    static sfColor pulse = {255, 255, 255, 0};
    if (g.value >= g.pvalue) {
        pulse.a = 255;
        tile[0].x = 31;
    }
    if (pulse.a >= 10)
        pulse.a -= 10;
    for (int i = 0; i < tn; i++)
        if (tile[i].name[0] == 'p')
            sfSprite_setColor(tile[i].sprite, pulse);
    return (tile);
}

void render_condition(tile_t tile, sfRenderWindow *w, int drop)
{
    if (tile.pos.x + tile.scale.x * 64 > 0 && tile.pos.x < 1920 && \
        tile.pos.y + tile.scale.y * 64 > 0 && tile.pos.y < 1080) {
        if (tile.name[0] == 'p' && drop)
            sfRenderWindow_drawSprite(w, tile.sprite, \
            blend_mode(tile.texture));
        sfRenderWindow_drawSprite(w, tile.sprite, \
        blend_mode(tile.texture));
    }
}

void render_map(int tn, tile_t *tile, sfRenderWindow *win, game_t g)
{
    int x = 0;

    tile = update_color(tn, tile, g);
    x = animate_tile(tile[0].x, g.is_drop);
    for (int i = 0; i < tn; i++) {
        tile[i].x = x;
        tile[i].rect.left = 64 *x;
        if (tile[i].name[0] != 'p')
            sfSprite_setTextureRect(tile[i].sprite, tile[i].rect);
        render_condition(tile[i], win, g.is_drop);
    }
}
