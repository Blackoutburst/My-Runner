/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void poll_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            sfRenderWindow_close(window);
    }
}

int loading(sfRenderWindow *window)
{
    sfSprite *sp = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("res/loading.png", NULL);

    sfRenderWindow_clear (window, sfBlack);
    sfSprite_setTexture(sp, text, sfTrue);

    sfRenderWindow_drawSprite(window, sp, blend_mode(text));
    sfRenderWindow_display(window);
    return (3);
}

void description2(void)
{
    write(1, "    and i now you won't play this game many hours to ", 53);
    write(1, "achieve this far.\n    So there is a video of the full ", 54);
    write(1, "playthrought of the map:\n    https://www.youtube.com/", 53);
    write(1, "watch?v=V4Yc-M2z8Zk\n    (Drops are at 1:50 and 3:20)\n", 53);
    write(1, "    Thanks for reading this.\n", 29);
}

void description(void)
{
    write(1, "My Runner (PowerRun)\n\n", 22);
    write(1, "USAGE:\n", 7);
    write(1, "    ./my_runner\n", 16);
    write(1, "    Launch the game.\n\n", 22);
    write(1, "HOW TO PLAY:\n", 13);
    write(1, "    User use SpaceBar or Arrow Up to jump over obstacles.\n", \
    58);
    write(1, "    There is three types of element, blub, green and red.\n", \
    58);
    write(1, "    Blue make the player jump normally,\n", 40);
    write(1, "    Red kill the player if he step on it,\n", 42);
    write(1, "    Green reverse the gravity when player try to ", 49);
    write(1, "jump on it.\n\nIMPORTANT:\n", 24);
    write(1, "    Consider this like a sort of readme.\n", 41);
    write(1, "    Basically there is a special visual effect when ", 52);
    write(1, "the song drop,\n", 15);
    description2();
}

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            description();
            return (0);
        }
    }
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfImage *icon = sfImage_createFromFile("res/icon.png");

    window = sfRenderWindow_create(mode, "PowerRun", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 512, 512, sfImage_getPixelsPtr(icon));
    update(window, event);
    sfImage_destroy(icon);
    return (0);
}
