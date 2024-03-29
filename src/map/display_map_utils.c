/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:20:32 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/07 21:46:21 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_floor(t_game *all, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;

	img = all->map.texture_array[0].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(all->map.mlx, img, image_x, image_y);
	all->map.info.floor++;
}

void	display_wall(t_game *all, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;

	img = all->map.texture_array[1].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(all->map.mlx, img, image_x, image_y);
	all->map.info.wall++;
}

void	display_collectible(t_game *all, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;
	mlx_image_t	*img2;

	img = all->map.texture_array[2].image;
	img2 = all->map.texture_array[0].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(all->map.mlx, img2, image_x, image_y);
	mlx_image_to_window(all->map.mlx, img, image_x, image_y);
	all->map.info.collectibles++;
}

void	display_door(t_game *all, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;
	mlx_image_t	*img2;

	img = all->map.texture_array[3].image;
	img2 = all->map.texture_array[0].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(all->map.mlx, img2, image_x, image_y);
	mlx_image_to_window(all->map.mlx, img, image_x, image_y);
	all->map.info.exit++;
}

void	display_hero(t_game *all, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;
	mlx_image_t	*img2;

	img = all->map.texture_array[4].image;
	img2 = all->map.texture_array[0].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	all->player.x = image_x;
	all->player.y = image_y;
	mlx_image_to_window(all->map.mlx, img2, image_x, image_y);
	mlx_image_to_window(all->map.mlx, img, image_x, image_y);
	all->map.info.hero++;
}
