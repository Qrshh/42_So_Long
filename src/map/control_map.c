/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:27:08 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/08 21:58:31 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_content(t_game *all)
{
	if ((all->map.info.exit > 1 || all->map.info.exit == 0)
		|| (all->map.info.hero > 1 || all->map.info.hero == 0)
		|| (all->map.info.collectibles < 1))
	{
		destroy_window(all);
		exit_error("Error \nWrong number of Hero/Collectible/Exit",
			all->map.matrix);
	}
	return (1);
}

int	check_shape(t_game *all)
{
	char	**tab;
	int		i;
	int		j;
	int		max;

	tab = all->map.matrix;
	i = 0;
	j = 0;
	while (tab[i][j])
		j++;
	max = j;
	i++;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != ' ')
			j++;
		if (j != max)
		{
			destroy_window(all);
			exit_error("Error \nShape not compliant", tab);
		}
		i++;
	}
	return (1);
}

int	is_closed(t_game *all)
{
	int	i;

	i = -1;
	while (++i < all->map.map_height)
	{
		if (all->map.matrix[i][0] != '1'
			|| all->map.matrix[i][all->map.map_width - 1] != '1')
		{
			destroy_window(all);
			exit_error("Error \nMap isn't close", all->map.matrix);
		}
	}
	i = -1;
	while (++i < all->map.map_width)
	{
		if (all->map.matrix[0][i] != '1' || all->map.matrix[all->map.map_height
			- 1][i] != '1')
		{
			destroy_window(all);
			exit_error("Error \nMap isn't close2", all->map.matrix);
		}
	}
	return (1);
}

int	check_map(t_game *all)
{
	if (check_shape(all) && is_closed(all) && check_content(all))
		return (1);
	free_map(all->map.matrix);
	return (0);
}
