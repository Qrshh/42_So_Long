/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:41:04 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/24 20:21:05 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

int	check_map(char *filename, char **tab_map)
{
	if (map_is_ber(filename) == 0 && map_is_rectangle(tab_map) == 0)
		return (1);
	return (0);
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
		filename_last = calloc(5, sizeof(char));
		while (filename[i])
		{
			filename_last[j] = filename[i];
			i++;
			j++;
		}
		if (ft_strcmp(filename_last, EXTENSION) == 0)
			return (0);
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
			exit_error("La map n'est pas rectangulaire");
		i++;
	}
	return (0);
}
