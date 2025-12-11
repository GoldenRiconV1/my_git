/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myradar-31 [WSL: Ubuntu-24.04]
** File description:
** init.c
*/

#include "../include/my.h"

static void init_sprit_list(game_t *game, sprit_list_t *sprit_list)
{
    sprit_list->is_plane = false;
    sprit_list->is_tower = false;
    sprit_list->next = NULL;
    sprit_list->plane = NULL;
    sprit_list->plane_coord = (sfVector2f){0, 0};
    sprit_list->plane_hitbox = NULL;
    sprit_list->plane_texture = NULL;
    sprit_list->tower = NULL;
    sprit_list->tower_coord = (sfVector2f){0, 0};
    sprit_list->tower_hitbox = NULL;
    sprit_list->tower_texture = NULL;
}

static void init_general(game_t *game)
{
    game->state = START_MENU;
    game->window = NULL;
    game->background_sprite = NULL;
    game->background_texture = NULL;
}

void init(game_t *game)
{
    init_general(game);
}
