/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:56:44 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/01 01:05:49 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

char	**ft_free_tab(char **tab, int index)
{
	if (index == -1)
	{
		while (tab[++index])
			free(tab[index]);
		index = -1;
	}
	while (index >= 0)
	{
		if (tab[index])
			free(tab[index]);
		index--;
	}
	if (tab)
		free(tab);
	return (NULL);
}

static char	**duplicate_map(char **map)
{
	int		size;
	char	**new;
	int		i;

	size = 0;
	while (map[size])
		size++;
	new = ft_calloc(size + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		new[i] = ft_strdup(map[i]);
		if (!new[i])
			return (ft_free_tab(new, -1));
	}
	return (new);
}

static int	flood_fill(char **map, int x, int y, int *requirements)
{
	if (map[y][x] == '1' || map[y][x] == 'M' || map[y][x] == 'D')
		return (0);
	else if (map[y][x] == 'C')
		requirements[1]++;
	else if (map[y][x] == 'E')
		requirements[0] = 1;
	map[y][x] = '1';
	flood_fill(map, x + 1, y, requirements);
	flood_fill(map, x - 1, y, requirements);
	flood_fill(map, x, y + 1, requirements);
	flood_fill(map, x, y - 1, requirements);
	return (0);
}

int	check_path(t_mappy *game)
{
	char	**flood_map;
	int		x;
	int		y;
	int		requirements[2];

	flood_map = duplicate_map(game->map);
	if (!flood_map)
		exit_error("Cloning map error");
	x = game->player_x;
	y = game->player_y;
	requirements[0] = 0;
	requirements[1] = 0;
	flood_fill(flood_map, x, y, requirements);
	ft_free_tab(flood_map, -1);
	if (!requirements[0])
		exit_error("No game issue founded");
	if (requirements[1] != game->total_collectible)
		exit_error("Not enough collectible");
	return (0);
}
