/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:20:32 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/05 22:05:21 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_floor(t_game *all, int x, int y)
{
    int image_x;
    int image_y;
    mlx_image_t *img = all->map.texture_array[0].image;

    image_x = x * TILE_SIZE;
    image_y = y * TILE_SIZE;
    mlx_image_to_window(all->map.mlx, img, image_x, image_y);
}

void display_wall(t_game *all, int x, int y)
{
    int image_x;
    int image_y;
    mlx_image_t *img = all->map.texture_array[1].image;

    image_x = x * TILE_SIZE;
    image_y = y * TILE_SIZE;
    mlx_image_to_window(all->map.mlx, img, image_x, image_y);
}

void display_collectible(t_game *all, int x, int y)
{
    int image_x;
    int image_y;
    mlx_image_t *img = all->map.texture_array[2].image;
    mlx_image_t *img2 = all->map.texture_array[0].image;

    image_x = x * TILE_SIZE;
    image_y = y * TILE_SIZE;
    mlx_image_to_window(all->map.mlx, img2, image_x, image_y);
    mlx_image_to_window(all->map.mlx, img, image_x, image_y);
}

void display_door(t_game *all, int x, int y)
{
    int image_x;
    int image_y;
    mlx_image_t *img = all->map.texture_array[3].image;
    mlx_image_t *img2 = all->map.texture_array[0].image;

    image_x = x * TILE_SIZE;
    image_y = y * TILE_SIZE;
    mlx_image_to_window(all->map.mlx, img2, image_x, image_y);
    mlx_image_to_window(all->map.mlx, img, image_x, image_y);
}

void display_hero(t_game *all, int x, int y)
{
    int image_x;
    int image_y;
    mlx_image_t *img = all->map.texture_array[4].image;
    mlx_image_t *img2 = all->map.texture_array[0].image;
    all->init++;


    image_x = x * TILE_SIZE;
    image_y = y * TILE_SIZE;
    all->player.x = image_x;
    all->player.y = image_y;
    mlx_image_to_window(all->map.mlx, img2, image_x, image_y);
    mlx_image_to_window(all->map.mlx, img, image_x, image_y);
}
