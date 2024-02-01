/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:59:55 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/01 01:21:58 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

char	**tab_map(char *argv)
{
	char	**tab;
	char	*line;
	int		i;
	int		fd;
	int		nb_line;

	i = 0;
	nb_line = ft_count_line_map(argv);
	tab = ft_calloc(1, sizeof(char *) * (nb_line + 1));
	if (!tab)
		exit_error("Error \nMalloc error");
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (i < nb_line)
			tab[i] = ft_strdup(line);
		line[ft_strlen(line) - 1] = '\0';
		tab[i] = line;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (tab);
}

int	count_tab_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	wall_checker(char **tab)
{
	int	i;
	int	j;
	int	nb_line;

	i = 0;
	nb_line = count_tab_line(tab);
	while (tab[i])
	{
		if (i == 0 || i == nb_line - 1)
		{
			j = 0;
			while (tab[i][j])
			{
				if (tab[i][j] != '1')
					exit_error("Error \nMap incorrect");
				j++;
			}
		}
		else
		{
			if (tab[i][0] != '1' || tab[i][ft_strlen(tab[i]) - 1] != '1')
				exit_error("Error \nMap incorrect");
		}
		i++;
	}
}
