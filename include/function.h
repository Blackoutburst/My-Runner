/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef enum parralax {
    BACK,
    MIDDLE,
    FRONT
} parralax_t;

typedef struct particles {
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture *texture;
    sfColor color;
} particles_t;

typedef struct player_trail {
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfColor color;
} player_trail_t;

typedef struct player {
    int inverted;
    int spe_g;
    int jumpStrength;
    int ground;
    sfVector2f pos;
    sfVector2f scale;
    int dead;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    player_trail_t *trail;
} player_t;

typedef struct r {
    int index;
    sfVideoMode *modes;
} r_t;

typedef struct arg_offset {
    int x;
    int pos;
} arg_offset_t;

typedef struct tile {
    sfVector2f pos;
    sfVector2f scale;
    int solid;
    float rotation;
    sfSprite *sprite;
    sfTexture *texture;
    char *name;
    sfIntRect rect;
    int x;
} tile_t;

typedef struct gameobject {
    parralax_t type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rectangle;
} gameobject_t;

typedef struct button {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rectangle;
    int hover;
    int down;
    int scene;
    int original_scene;
} button_t;

typedef struct title {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} title_t;

typedef struct endmenu {
    int scene;
    button_t restart_but;
    button_t exit_but;
    title_t title;
} endmenu_t;

typedef struct gameovermenu {
    int scene;
    button_t restart_but;
    button_t exit_but;
    title_t title;
} gameovermenu_t;

typedef struct pausemenu {
    int scene;
    button_t continue_but;
    button_t restart_but;
    button_t exit_but;
    title_t title;
} pausemenu_t;

typedef struct game {
    player_t player;
    gameobject_t *object;
    particles_t *particles;
    int tiles_number;
    tile_t *tile;
    int scene;
    sfSoundBuffer *soundBuffer;
    sfSound *song;
    sfSoundBuffer *completeBuffer;
    sfSound *complete;
    sfSoundBuffer *overBuffer;
    sfSound *over;
    pausemenu_t pause_menu;
    gameovermenu_t gameover_menu;
    endmenu_t end_menu;
    int pulse;
    int drop;
    float value;
    int pvalue;
    int dvalue;
    int is_drop;
    int avancement;
} game_t;

typedef struct mainmenu {
    sfSoundBuffer *soundBuffer;
    sfSound *song;
    int scene;
    player_t player;
    button_t play_but;
    button_t option_but;
    button_t exit_but;
    gameobject_t *object;
    title_t title;
    particles_t *particles;
} mainmenu_t;

typedef struct global {
    game_t game;
    mainmenu_t mainmenu;
    int scene;
} global_t;

void loop_song(sfSound *song);
void poll_event(sfRenderWindow *window, sfEvent event);
void update(sfRenderWindow *window, sfEvent event);
game_t manage_end(game_t g, sfRenderWindow *window, int ascene);
game_t manage_end_bis(game_t g, sfRenderWindow *window);
endmenu_t update_endmenu(endmenu_t g, sfRenderWindow *w, int a);
endmenu_t init_endmenu(void);
game_t manage_pause(game_t g, sfRenderWindow *window, int ascene);
game_t manage_pause_bis(game_t g, sfRenderWindow *window);
game_t manage_gameover(game_t g, sfRenderWindow *window, int ascene);
game_t manage_gameover_bis(game_t g, sfRenderWindow *window);
gameovermenu_t init_gameovermenu(void);
gameovermenu_t update_gameovermenu(gameovermenu_t g, sfRenderWindow *, int);
int loading(sfRenderWindow *window);
pausemenu_t update_pausemenu(pausemenu_t g, sfRenderWindow *window, int);
pausemenu_t init_pausemenu(void);
particles_t *update_particles_menu(particles_t *, sfRenderWindow *, player_t);
button_t render_button(button_t object, sfRenderWindow *win);
button_t update_button(button_t object, sfRenderWindow *win, int actual_scene);
button_t create_button(char *p, sfVector2f o, int scene);
void render_title(title_t object, sfRenderWindow *win);
title_t create_title(char *p, sfVector2f o);
mainmenu_t update_mainmenu(mainmenu_t g, sfRenderWindow *window, int ascene);
mainmenu_t init_mainmenu(void);
game_t init_game(void);
game_t update_game(game_t g, sfRenderWindow *window, int);
void run_song(sfSound *song);
void pause_song(sfSound *song);
void stop_song(sfSound *song);
sfIntRect blue_pulse(sfIntRect rect, char *name);
sfIntRect green_pulse(sfIntRect rect, char *name);
sfIntRect red_pulse(sfIntRect rect, char *name);
sfIntRect blue_tile(sfIntRect rect, char *name);
sfIntRect green_tile(sfIntRect rect, char *name);
sfIntRect red_tile(sfIntRect rect, char *name);
int animate_tile(int x, int);
sfRenderStates *blend_mode(sfTexture *texture);
game_t update_particles(particles_t *part, sfRenderWindow *win, game_t);
particles_t *create_particles(char const *path);
player_trail_t *create_player_trail(sfTexture *texture, sfVector2f pos);
void update_player_trail(player_t p, sfRenderWindow *win);
char *get_next_line(int fd);
player_t on_ground_inv(player_t p, tile_t *tile, int tiles_number);
int my_atoi(char const *str);
char *read_map(char *);
int count_lines(char *);
tile_t *generate_map(char *buffer, int tiles_number);
arg_offset_t fill_arg(char **, char, arg_offset_t);
void clean_args(char **);
sfVideoMode *set_video_mode(void);
void restore_window(int, sfRenderWindow *, sfVideoMode *);
r_t change_resolution(r_t, sfRenderWindow *, sfEvent);
player_t create_player(const char *, sfVector2f pos);
player_t update_player(player_t, tile_t *, int);
void destroy_parralax(gameobject_t obj);
gameobject_t create_parralax(char *, sfVector2f, sfIntRect, parralax_t);
gameobject_t update_parralax(gameobject_t);
gameobject_t *init_parralax(void);
game_t player_updater(game_t p, tile_t *tile, int tn, sfRenderWindow *win);
void render_map(int tn, tile_t *tile, sfRenderWindow *win, game_t g);
tile_t *update_map(int, tile_t *, player_t);
gameobject_t *parra_update(gameobject_t *o, sfRenderWindow *w, player_t p);
player_t on_ground_inv(player_t p, tile_t *tile, int tiles_number);
player_t on_ground(player_t p, tile_t *tile, int tiles_number);
player_t kill_player_inv(tile_t *tile, int tiles_number, player_t p, game_t g);
player_t kill_player(tile_t *tile, int tiles_number, player_t p, game_t g);
