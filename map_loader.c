/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map loader function
*/

#include "include/function.h"

sfIntRect choose_texture(char *name)
{
    sfIntRect rect =  {0, 0, 64, 64};

    rect = blue_tile(rect, name);
    rect = green_tile(rect, name);
    rect = red_tile(rect, name);
    rect = blue_pulse(rect, name);
    rect = green_pulse(rect, name);
    rect = red_pulse(rect, name);
    return (rect);

}

void fill_map(sfTexture *texture, tile_t *tile, int line, char **arg)
{
    tile[line].pos.x = my_atoi(arg[1]);
    tile[line].pos.y = my_atoi(arg[2]);
    tile[line].scale.x = (float) (my_atoi(arg[3])) / 64;
    tile[line].scale.y = (float) (my_atoi(arg[4])) / 64;
    tile[line].solid = arg[5][0] == 'f' ? 0 : 1;
    tile[line].rotation = my_atoi(arg[6]);
    tile[line].texture = texture;
    tile[line].sprite = sfSprite_create();
    tile[line].name = arg[7];
    tile[line].rect = choose_texture(tile[line].name);
    tile[line].x = 0;
    sfSprite_setPosition(tile[line].sprite, tile[line].pos);
    sfSprite_setTexture(tile[line].sprite, tile[line].texture, sfTrue);
    sfSprite_setScale(tile[line].sprite, tile[line].scale);
    sfSprite_setTextureRect(tile[line].sprite, tile[line].rect);
}

void clean_args(char **arg)
{
    for (int p = 0; p < 8; p++) {
        arg[p] = malloc(sizeof(char) * 30);
        for (int k = 0; k < 30; k++) {
            arg[p][k] = 0;
        }
    }
}

arg_offset_t fill_arg(char **arg, char c, arg_offset_t offset)
{
    if (c == ' ') {
        offset.pos++;
        offset.x = 0;
    }
    if (c != ' ') {
        arg[offset.pos][offset.x] = c;
        offset.x++;
    }
    return (offset);
}

tile_t *generate_map(char *buffer, int tiles_number)
{
    int line = 0;
    tile_t *tile = malloc(sizeof(*tile) * tiles_number);
    char **arg;
    arg_offset_t offset;
    sfTexture *texture = sfTexture_createFromFile("res/tile.png", NULL);

    for (int i = 0; buffer[i]; i++) {
        offset.x = 0;
        offset.pos = 0;
        arg = malloc(sizeof(char *) * 8);
        clean_args(arg);
        while (buffer[i] != '\n') {
            offset = fill_arg(arg, buffer[i], offset);
            i++;
        }
        fill_map(texture, tile, line, arg);
        line++;
    }
    return (tile);
}
