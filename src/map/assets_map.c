/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:03:52 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/07 21:47:00 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	asset_init(t_game *all)
{
	int	i;

	i = 0;
	all->map.texture_array[0].texture = mlx_load_png("assets/floor.png");
	all->map.texture_array[1].texture = mlx_load_png("assets/wall.png");
	all->map.texture_array[2].texture = mlx_load_png("assets/collectible.png");
	all->map.texture_array[3].texture = mlx_load_png("assets/exit.png");
	all->map.texture_array[4].texture = mlx_load_png("assets/knight.png");
	while (i < 5)
	{
		all->map.texture_array[i].image = mlx_texture_to_image(all->map.mlx,
				all->map.texture_array[i].texture);
		mlx_delete_texture(all->map.texture_array[i].texture);
		i++;
	}
}
