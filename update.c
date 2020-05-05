/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

global_t update_bis(global_t glo, sfRenderWindow *window)
{
    if (glo.scene == 1) {
        stop_song(glo.mainmenu.song);
        glo.mainmenu.scene = loading(window);
        glo.game = init_game();
        run_song(glo.game.song);
    }
    if (glo.scene == 0 || glo.scene == 1 || glo.scene == 2)
    glo.scene = glo.mainmenu.scene;
    if (glo.scene == 3) {
        glo.game = update_game(glo.game, window, glo.scene);
        glo.scene = glo.game.scene;
    }
    if (glo.scene == 5) {
        glo.mainmenu = init_mainmenu();
        run_song(glo.mainmenu.song);
        loop_song(glo.mainmenu.song);
        glo.scene = 0;
    }
    return (glo);
}

void update(sfRenderWindow *window, sfEvent event)
{
    global_t glo;

    glo.game;
    glo.mainmenu = init_mainmenu();
    glo.scene = 0;
    loop_song(glo.mainmenu.song);
    run_song(glo.mainmenu.song);
    while (sfRenderWindow_isOpen(window)) {
        poll_event(window, event);
        sfRenderWindow_clear (window, sfBlack);
        glo = update_bis(glo, window);
        if (glo.scene == 0)
            glo.mainmenu = update_mainmenu(glo.mainmenu, window, glo.scene);
        if (glo.scene == -1)
            break;
        sfRenderWindow_display(window);
    }
}
