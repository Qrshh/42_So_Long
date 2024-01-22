/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personnage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:23:24 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/22 23:43:42 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

int	is_valid(char **map, int x, int y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (0);
	map_x = x / 16;
	map_y = y / 16;
	ft_printf("Y%d X%d C%c(%x)\n", map_y, map_x, map[map_y][map_x],
		map[map_y][map_x]);
	if (map[map_y][map_x] == '0' || map[map_y][map_x] == 'P')
		return (1);
	return (0);
}

void	select_key(t_mappy *sex, int new_x, int new_y)
{
	if (mlx_is_key_down(sex->mlx, MLX_KEY_W))
	{
		if (is_valid(sex->map, new_x, new_y - TILE_SIZE) == 1)
			sex->texture_array[4].image->instances[0].y = new_y - TILE_SIZE;
	}
	if (mlx_is_key_down(sex->mlx, MLX_KEY_S))
	{
		if (is_valid(sex->map, new_x, new_y + TILE_SIZE) == 1)
			sex->texture_array[4].image->instances[0].y = new_y + TILE_SIZE;
	}
	if (mlx_is_key_down(sex->mlx, MLX_KEY_D))
	{
		if (is_valid(sex->map, new_x + TILE_SIZE, new_y) == 1)
			sex->texture_array[4].image->instances[0].x = new_x + TILE_SIZE;
	}
	if (mlx_is_key_down(sex->mlx, MLX_KEY_A))
	{
		if (is_valid(sex->map, new_x - TILE_SIZE, new_y) == 1)
			sex->texture_array[4].image->instances[0].x = new_x - TILE_SIZE;
	}
}

void	ft_hook(void *param)
{
	t_mappy	*sex;
	int		new_y;
	int		new_x;

	sex = (t_mappy *)param;
	new_y = sex->texture_array[4].image->instances->y;
	new_x = sex->texture_array[4].image->instances->x;
	if (mlx_is_key_down(sex->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(sex->mlx);
	select_key(sex, new_x, new_y);
}
