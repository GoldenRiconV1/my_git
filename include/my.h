/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myradar-31 [WSL: Ubuntu-24.04]
** File description:
** my.h
*/
#ifndef MY_H_
    #define MY_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <time.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdarg.h>
    #define _GNU_SOURCE
    #define GAME_WIDTH 1920
    #define GAME_HEIGHT 1080

typedef enum game_state_e
{
    START_MENU,
    PLAYING,
    PAUSED,
    LOOSE
} game_state_t;

    typedef struct sprit_list_s
{
    bool is_plane;
    bool is_tower;
    sfSprite *plane;
    sfTexture *plane_texture;
    sfRectangleShape *plane_hitbox;
    sfVector2f plane_coord;

    sfSprite *tower;
    sfRectangleShape *tower_hitbox;
    sfTexture *tower_texture;
    sfVector2f tower_coord;

    struct planel_s *next;
} sprit_list_t;

typedef struct game_s
{
    game_state_t state;
    sfRenderWindow *window;
    sfSprite *background_sprite;
    sfTexture *background_texture;
} game_t;

game_t *create_game(void);
void destroy_game(game_t *game);
void game_loop(game_t *game);
void manage_events(game_t *game);
void init(game_t *game);

bool create_background(game_t *game);

int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
int my_putchar(char c);
int my_put_nbr(int nb);
int mini_printf(const char *format, ...);
char *unsigned_int_to_str(unsigned int n);
char *my_revstr(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
bool get_start_coord(const char *filepath);

#endif
