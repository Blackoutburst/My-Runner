/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map updater function
*/

#include "include/function.h"

particles_t *create_particles(char const *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    float alpha = 100;
    particles_t *object = malloc(sizeof(particles_t) * 300);

    for (int i = 0; i < 300; i++) {
        object[i].sprite = sfSprite_create();
        object[i].texture = texture;
        sfSprite_setTexture(object[i].sprite, object[i].texture, sfTrue);
        object[i].pos.x = rand() % 1920;
        object[i].pos.y = rand() % 1080;
        object[i].color = (sfColor) {255, 255, 255, 50};
        alpha -= 0.1;
    }
    return (object);
}

game_t update_color_part(particles_t *tile, game_t g)
{
    static sfColor pulse = {255, 255, 255, 50};

    if (g.value >= g.pvalue) {
        char *line = get_next_line(g.pulse);
        if (line != NULL)
            g.pvalue = my_atoi(line);
        pulse.a = 255;
    }
    if (pulse.a >= 50)
        pulse.a -= 10;
    for (int i = 0; i < 300; i++)
        tile[i].color = g.is_drop ? pulse : (sfColor) {255, 255, 255, 50};
    return (g);
}

game_t drop_manager_part(game_t g)
{
    if (g.value >= g.dvalue) {
        char *line = get_next_line(g.drop);
        if (line != NULL) {
            g.dvalue = my_atoi(line);
            g.is_drop = g.is_drop ? 0 : 1;
        }
    }
    return (g);
}

game_t update_particles(particles_t *part, sfRenderWindow *win, game_t g)
{
    g = drop_manager_part(g);
    g = update_color_part(g.particles, g);
    for (int i = 0; i < 300; i++) {
        if (!g.player.dead)
            part[i].pos.x -= 1;
        if (part[i].pos.x < 0) {
            part[i].pos.x += 1920;
            part[i].pos.y = rand() % 1080;
        }
        sfSprite_setColor(part[i].sprite, part[i].color);
        sfSprite_setPosition(part[i].sprite, part[i].pos);
        sfRenderWindow_drawSprite(win, part[i].sprite, \
        blend_mode(part[i].texture));
        sfRenderWindow_drawSprite(win, part[i].sprite, \
        blend_mode(part[i].texture));
    }
    return (g);
}

particles_t *update_particles_menu(particles_t *part, sfRenderWindow *win, \
player_t p)
{
    for (int i = 0; i < 300; i++) {
        if (!p.dead)
            part[i].pos.x -= 1;
        if (part[i].pos.x < 0) {
            part[i].pos.x += 1920;
            part[i].pos.y = rand() % 1080;
        }
        sfSprite_setColor(part[i].sprite, part[i].color);
        sfSprite_setPosition(part[i].sprite, part[i].pos);
        sfRenderWindow_drawSprite(win, part[i].sprite, \
        blend_mode(part[i].texture));
        sfRenderWindow_drawSprite(win, part[i].sprite, \
        blend_mode(part[i].texture));
    }
    return (part);
}
