/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:25:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/07 21:46:34 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game *all, int new_x, int new_y)
{
	new_x = new_x / 16;
	new_y = new_y / 16;
	if (new_x < 0 || new_y < 0 || new_x > all->map.map_width
		|| new_y > all->map.map_height)
		return (0);
	else if (all->map.matrix[new_y][new_x] == '1')
		return (0);
	else if (all->map.matrix[new_y][new_x] == 'C')
	{
		all->map.items_collected++;
		if (all->map.items_collected == all->map.info.collectibles)
			ft_printf("Collected ! You have collected all the items (%d)\n",
				all->map.items_collected);
		else
			ft_printf("Collected ! You have collected : %d items\n",
				all->map.items_collected);
		all->map.matrix[new_y][new_x] = '0';
	}
	else if (all->map.matrix[new_y][new_x] == 'E'
		&& all->map.items_collected == all->map.info.collectibles)
		mlx_close_window(all->map.mlx);
	else if (all->map.matrix[new_y][new_x] == 'E'
		&& all->map.items_collected < all->map.info.collectibles)
		return (0);
	return (1);
}

void	moove_update(t_game *all)
{
	all->player.player_mouv++;
	ft_printf("Steps : %d\n", all->player.player_mouv);
}
