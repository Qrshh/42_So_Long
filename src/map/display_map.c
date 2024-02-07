/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:01:55 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/07 23:04:23 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_select(t_game *all, int x, int y)
{
	if (all->map.matrix[y][x] != '\0')
	{
		if (all->map.matrix[y][x] == '0')
			display_floor(all, x, y);
		else if (all->map.matrix[y][x] == '1')
			display_wall(all, x, y);
		else if (all->map.matrix[y][x] == 'C')
			display_collectible(all, x, y);
		else if (all->map.matrix[y][x] == 'E')
			display_door(all, x, y);
	}
}
void	display_assets(t_game *all)
{
	int	x;
	int	y;
	int	check_x;
	int	check_y;

	check_x = -1;
	check_y = -1;
	y = 0;
	while (y < all->map.map_height)
	{
		x = 0;
		while (all->map.matrix[y][x])
		{
			image_select(all, x, y);
			if (all->map.matrix[y][x] == 'P')
			{
				check_x = x;
				check_y = y;
			}
			x++;
		}
		y++;
	}
	if (check_x != -1 && check_y != -1)
		display_hero(all, check_x, check_y);
}

void	delete_img_collected(t_game *all)
{
	int	i;
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	i = 0;
	while (i < all->map.info.collectibles)
	{
		if (all->map.texture_array[2].image->instances[i].x == x)
		{
			if (all->map.texture_array[2].image->instances[i].y == y)
				all->map.texture_array[2].image->instances[i].enabled = false;
		}
		i++;
	}
}
