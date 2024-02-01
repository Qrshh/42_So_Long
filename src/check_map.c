/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:41:04 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/01 18:42:12 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void	counter_on_map(t_mappy *all)
{
	int	i;
	int	j;

	all->player_count = 0;
	all->exit_count = 0;
	all->collectible_count = 0;
	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'P')
				all->player_count++;
			else if (all->map[i][j] == 'E')
				all->exit_count++;
			else if (all->map[i][j] == 'C')
				all->collectible_count++;
			j++;
		}
		i++;
	}
}

int	map_is_ber(char *filename)
{
	int		i;
	int		j;
	int		filename_len;
	char	*filename_last;

	filename_len = ft_strlen(filename);
	if (filename_len > 4)
	{
		i = filename_len - 4;
		j = 0;
		filename_last = ft_calloc(5, sizeof(char));
		while (filename[i])
		{
			filename_last[j] = filename[i];
			i++;
			j++;
		}
		if (ft_strcmp(filename_last, EXTENSION) == 0)
			return (free(filename_last), 0);
		free(filename_last);
	}
	return (1);
}

int	map_is_rectangle(char **tab_map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	j = 0;
	while (tab_map[i][j])
		j++;
	max = j;
	i++;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
			j++;
		if (j != max)
			exit_error("Error \nMap is not rectangular");
		i++;
	}
	return (0);
}

int	check_map(char *filename, char **tab_map)
{
	t_mappy	*all;

	all = malloc(sizeof(t_mappy));
	if (!all)
		exit_error("Malloc error");
	all->map = tab_map;
	if (map_is_ber(filename) == 0 && map_is_rectangle(tab_map) == 0)
	{
		counter_on_map(all);
		if (all->collectible_count > 0 && all->exit_count == 1
			&& all->player_count == 1)
			return (free(all), 1);
		else
			exit_error("Error \nInvalid number of player/exit/collectible");
	}
	free(all);
	return (0);
}
