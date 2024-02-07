/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:27:08 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/07 22:36:48 by abesneux         ###   ########.fr       */
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

int	is_closed(t_map map)
{
	int	i;

	i = -1;
	while (++i < map.map_height)
	{
		if (map.matrix[i][0] != '1' || map.matrix[i][map.map_width - 1] != '1')
			exit_error("Error \nMap isn't close", map.matrix);
	}
	i = -1;
	while (++i < map.map_width)
	{
		if (map.matrix[0][i] != '1' || map.matrix[map.map_height - 1][i] != '1')
			exit_error("Error \nMap isn't close2", map.matrix);
	}
	return (1);
}

int	check_map(t_game *all)
{
	if (check_shape(all) == 1 && is_closed(all->map) == 1
		&& check_content(all) == 1)
		return (1);
	free_map(all->map.matrix);
	return (0);
}
