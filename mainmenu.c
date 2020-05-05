/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

mainmenu_t update_mainmenu(mainmenu_t g, sfRenderWindow *window, int ascene)
{
    g.object = parra_update(g.object, window, g.player);
    g.particles = update_particles_menu(g.particles, window, g.player);
    g.play_but = update_button(g.play_but, window, ascene);
    g.option_but = update_button(g.option_but, window, ascene);
    g.exit_but = update_button(g.exit_but, window, ascene);
    if (sfKeyboard_isKeyPressed(sfKeyReturn))
        g.scene = 1;
    if (g.play_but.scene != ascene)
        g.scene = g.play_but.scene;
    if (g.option_but.scene != ascene)
        g.scene = g.option_but.scene;
    if (g.exit_but.scene != ascene)
        g.scene = g.exit_but.scene;
    render_title(g.title, window);
    return (g);
}

mainmenu_t init_mainmenu(void)
{
    mainmenu_t mainmenu;
    sfVector2f pos = {-100.0, -100.0};
    sfVector2f play_pos = {704, 300.0};
    sfVector2f option_pos = {64, 500.0};
    sfVector2f exit_pos = {1344, 500.0};
    sfVector2f title_pos = {448, -100};

    mainmenu.soundBuffer = sfSoundBuffer_createFromFile("res/menu.ogg");
    mainmenu.song = sfSound_create();
    sfSound_setBuffer(mainmenu.song, mainmenu.soundBuffer);
    mainmenu.scene = 0;
    mainmenu.play_but = create_button("res/play.png", play_pos, 1);
    mainmenu.option_but = create_button("res/option.png", option_pos, 0);
    mainmenu.exit_but = create_button("res/leave.png", exit_pos, -1);
    mainmenu.title = create_title("res/title.png", title_pos);
    mainmenu.player = create_player("res/player.png", pos);
    mainmenu.object = init_parralax();
    mainmenu.particles = create_particles("res/particles.png");
    return (mainmenu);
}
