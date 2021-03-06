/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

game_t manage_end(game_t g, sfRenderWindow *window, int ascene)
{
    if (g.player.dead != 2)
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    if (g.player.dead == 2)
        g.end_menu = update_endmenu(g.end_menu, window, ascene);
    if (g.end_menu.scene == 1) {
        stop_song(g.song);
        stop_song(g.complete);
        loading(window);
        close(g.pulse);
        close(g.drop);
        g = init_game();
        run_song(g.song);
    }
    return (g);
}

game_t manage_end_bis(game_t g, sfRenderWindow *window)
{
    if (g.end_menu.scene == 0) {
        stop_song(g.song);
        stop_song(g.complete);
        loading(window);
        g.scene = 5;
        close(g.pulse);
        close(g.drop);
    }
    return (g);
}

endmenu_t update_endmenu(endmenu_t g, sfRenderWindow *w, int a)
{
    sfRenderWindow_setMouseCursorVisible(w, sfTrue);
    g.restart_but = update_button(g.restart_but, w, a);
    g.exit_but = update_button(g.exit_but, w, a);
    if (g.restart_but.scene != a)
        g.scene = g.restart_but.scene;
    if (g.exit_but.scene != a)
        g.scene = g.exit_but.scene;
    render_title(g.title, w);
    return (g);
}

endmenu_t init_endmenu(void)
{
    endmenu_t menu;
    sfVector2f option_pos = {164, 500.0};
    sfVector2f exit_pos = {1244, 500.0};
    sfVector2f title_pos = {448, -100};

    menu.scene = 3;
    menu.restart_but = create_button("res/restart.png", option_pos, 1);
    menu.exit_but = create_button("res/exit.png", exit_pos, 0);
    menu.title = create_title("res/level_complete.png", title_pos);
    return (menu);
}
