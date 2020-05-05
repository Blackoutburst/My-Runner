/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

game_t update_game_bis(game_t g, sfRenderWindow *window, int ascene)
{
    if (!g.player.dead)
        g.avancement += 10;
    if (g.player.dead == 1) {
        stop_song(g.song);
        g = manage_gameover(g, window, ascene);
        g = manage_gameover_bis(g, window);
    }
    if (g.player.dead == 2) {
        g = manage_end(g, window, ascene);
        g = manage_end_bis(g, window);
    }
    if (g.avancement > 146400 && !g.player.dead) {
        g.player.dead = 2;
        run_song(g.complete);
    }
    return (g);
}

game_t update_game(game_t g, sfRenderWindow *window, int ascene)
{
    g.object = parra_update(g.object, window, g.player);
    g.tile = update_map(g.tiles_number, g.tile, g.player);
    render_map(g.tiles_number, g.tile, window, g);
    g = update_particles(g.particles, window, g);
    g = player_updater(g, g.tile, g.tiles_number, window);
    g.scene = ascene;
    if (!g.player.dead || g.player.dead == 3) {
        g = manage_pause(g, window, ascene);
        g = manage_pause_bis(g, window);
    }
    g = update_game_bis(g, window, ascene);
    if (!g.player.dead)
        g.value += 16.78f;
    return (g);
}

game_t init_game_bis(game_t game)
{
    game.pause_menu = init_pausemenu();
    game.gameover_menu = init_gameovermenu();
    game.end_menu = init_endmenu();
    game.pvalue = 0;
    game.dvalue = 0;
    game.is_drop = 1;
    game.avancement = 0;
    game.completeBuffer = sfSoundBuffer_createFromFile("res/complete.ogg");
    game.complete = sfSound_create();
    sfSound_setBuffer(game.complete, game.completeBuffer);

    game.overBuffer = sfSoundBuffer_createFromFile("res/game_over.ogg");
    game.over = sfSound_create();
    sfSound_setBuffer(game.over, game.overBuffer);
    return (game);
}

game_t init_game(void)
{
    game_t game;
    sfVector2f pos = {400.0, 600.0};
    char *buffer = read_map("map/map.dat");

    game.soundBuffer = sfSoundBuffer_createFromFile("res/song1.ogg");
    game.song = sfSound_create();
    sfSound_setBuffer(game.song, game.soundBuffer);
    game.scene = 0;
    game.drop = open("res/drop1", O_RDONLY);
    game.pulse = open("res/pulse1", O_RDONLY);
    game.player = create_player("res/player.png", pos);
    game.object = init_parralax();
    game.particles = create_particles("res/particles.png");
    game.value = 0;
    game.tiles_number = count_lines(buffer);
    game.tile = generate_map(buffer, game.tiles_number);
    game = init_game_bis(game);
    return (game);
}
