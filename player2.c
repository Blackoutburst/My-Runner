/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

player_t kill_player(tile_t *tile, int tiles_number, player_t p, game_t g)
{
    for (int i = 0; i < tiles_number; i++) {
        if (p.pos.x + 64 >= tile[i].pos.x && tile[i].name[0] != 'p' && \
            p.pos.x <= tile[i].pos.x + tile[i].scale.x * 64 && \
            p.pos.y + 64/2 > tile[i].pos.y && !p.inverted && \
            p.pos.y < tile[i].pos.y + tile[i].scale.y * 64 && \
            !p.dead) {
            p.dead = 1;
            run_song(g.over);
        }
        if (p.pos.x + 64 - 32 >= tile[i].pos.x && tile[i].solid && \
            p.pos.x + 32 <= tile[i].pos.x + 64 && tile[i].name[0] != 'p' && \
            p.pos.y + 65 > tile[i].pos.y && !p.inverted && \
            p.pos.y < tile[i].pos.y + 64 / 2 && !p.dead) {
            p.dead = 1;
            run_song(g.over);
        }
    }
    return (p);
}

player_t kill_player_inv(tile_t *tile, int tiles_number, player_t p, game_t g)
{
    for (int i = 0; i < tiles_number; i++) {
        if (p.pos.x + 64 >= tile[i].pos.x && tile[i].name[0] != 'p' && \
            p.pos.x <= tile[i].pos.x + tile[i].scale.x * 64 && \
            p.pos.y + 64/2 < tile[i].pos.y + 64 && p.inverted && \
            p.pos.y + 64 > tile[i].pos.y && \
            !p.dead) {
            p.dead = 1;
            run_song(g.over);
        }
        if (p.pos.x + 64 - 32 >= tile[i].pos.x && tile[i].solid && \
            p.pos.x + 32 <= tile[i].pos.x + 64 && tile[i].name[0] != 'p' && \
            p.pos.y < tile[i].pos.y + 65 && p.inverted && \
            p.pos.y > tile[i].pos.y + 64 / 2) {
            p.dead = 1;
            run_song(g.over);
        }
    }
    return (p);
}

player_t on_ground(player_t p, tile_t *tile, int tiles_number)
{
    for (int i = 0; i < tiles_number; i++) {
        if (!p.inverted && p.pos.x + 64 - 10 >= tile[i].pos.x && \
            p.pos.x <= tile[i].pos.x + 64 && tile[i].name[0] != 'p' && \
            p.pos.y + 64 > tile[i].pos.y && tile[i].name[0] != 'g' && \
            p.pos.y < tile[i].pos.y + 64 / 2) {
            p.ground = 1;
            p.spe_g = 0;
            p.pos.y = tile[i].pos.y - 64;
        }
        if (!p.inverted && p.pos.x + 64 + 20 >= tile[i].pos.x && \
            p.pos.x - 20 <= tile[i].pos.x + 64 && tile[i].name[0] != 'p' && \
            p.pos.y + 64 > tile[i].pos.y && tile[i].name[0] == 'g' && \
            p.pos.y < tile[i].pos.y + 64 / 2) {
            p.ground = 1;
            p.spe_g = 1;
            p.pos.y = tile[i].pos.y - 64;
        }
    }
    return (p);
}

player_t on_ground_inv(player_t p, tile_t *tile, int tiles_number)
{
    for (int i = 0; i < tiles_number; i++) {
        if (p.inverted && p.pos.x + 64 - 10 >= tile[i].pos.x && \
            p.pos.x <= tile[i].pos.x + 64 && tile[i].name[0] != 'p' && \
            p.pos.y < tile[i].pos.y + 64 && tile[i].name[0] != 'g' && \
            p.pos.y + 64 > tile[i].pos.y + 64 / 2) {
            p.ground = 1;
            p.spe_g = 0;
            p.pos.y = tile[i].pos.y + 64;
        }
        if (p.inverted && p.pos.x + 64 + 20 >= tile[i].pos.x && \
            p.pos.x - 20 <= tile[i].pos.x + 64 && tile[i].name[0] != 'p' && \
            p.pos.y < tile[i].pos.y + 64 && tile[i].name[0] == 'g' && \
            p.pos.y + 64 > tile[i].pos.y + 64 / 2) {
            p.ground = 1;
            p.spe_g = 1;
            p.pos.y = tile[i].pos.y + 64;
        }
    }
    return (p);
}
