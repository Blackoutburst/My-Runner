/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

game_t manage_pause(game_t g, sfRenderWindow *window, int ascene)
{
    if (g.player.dead != 3)
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && ascene != 4) {
        g.player.dead = 3;
        pause_song(g.song);
    }
    if (g.player.dead == 3)
        g.pause_menu = update_pausemenu(g.pause_menu, window, ascene);
    if (g.pause_menu.scene == 4) {
        g.player.dead = 0;
        run_song(g.song);
        g.pause_menu.scene = 3;
    }
    return (g);
}

game_t manage_pause_bis(game_t g, sfRenderWindow *window)
{
    if (g.pause_menu.scene == 1) {
        stop_song(g.song);
        loading(window);
        close(g.pulse);
        close(g.drop);
        g = init_game();
        run_song(g.song);
    }
    if (g.pause_menu.scene == 0) {
        stop_song(g.song);
        loading(window);
        g.scene = 5;
        close(g.pulse);
        close(g.drop);
    }
    return (g);
}

pausemenu_t update_pausemenu(pausemenu_t g, sfRenderWindow *window, int ascene)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    g.continue_but = update_button(g.continue_but, window, ascene);
    g.restart_but = update_button(g.restart_but, window, ascene);
    g.exit_but = update_button(g.exit_but, window, ascene);
    if (g.restart_but.scene != ascene)
        g.scene = g.restart_but.scene;
    if (g.exit_but.scene != ascene)
        g.scene = g.exit_but.scene;
    if (g.continue_but.scene != ascene)
        g.scene = g.continue_but.scene;
    render_title(g.title, window);
    return (g);
}

pausemenu_t init_pausemenu(void)
{
    pausemenu_t menu;
    sfVector2f play_pos = {704, 300.0};
    sfVector2f option_pos = {64, 500.0};
    sfVector2f exit_pos = {1344, 500.0};
    sfVector2f title_pos = {448, -100};

    menu.scene = 3;
    menu.continue_but = create_button("res/continue.png", play_pos, 4);
    menu.restart_but = create_button("res/restart.png", option_pos, 1);
    menu.exit_but = create_button("res/exit.png", exit_pos, 0);
    menu.title = create_title("res/pause.png", title_pos);
    return (menu);
}
